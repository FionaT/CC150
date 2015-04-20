#include "memory_manager.h"
#include "random_scheduler.h"
#include "fifo_scheduler.h"
#include "2chance_scheduler.h"
#include "nru_scheduler.h"
#include "lru_scheduler.h"
#include "clock_scheduler.h"
#include "aging_scheduler.h"
#include <iostream>
#include <iomanip>

using namespace std;

MemoryManager::MemoryManager(string algo, int n, string rfile, bool the_O, bool the_P, bool the_F, bool the_S, bool the_p, bool the_f)
{
	//initialize these fields
	max_frame_num = n;
	frame_id = 0;
	instr_counter = 0;
	unmap_counter = 0;
	map_counter = 0;
	pagein_counter = 0;
	pageout_counter = 0;
	zero_counter = 0;
	
	O = the_O;
	P = the_P;
	F = the_F;
	S = the_S;
	p = the_p;
	f = the_f;
	
	algo_type = algo;
	
	//choose different scheduler by the algo variable
	if(algo == "r"){
		scheduler = new RandomScheduler(n, rfile);
	}else if(algo == "f"){
		scheduler = new FIFOScheduler(n);
	}else if(algo == "s"){
		scheduler = new SecondChanceScheduler(n);
	}else if(algo == "N"){
		scheduler = new NRUScheduler(n, rfile);
	}else if(algo == "l"){
		scheduler = new LRUScheduler(n);
	}else if(algo == "a" || algo == "Y"){
		
		if(algo == "Y"){
			scheduler = new AgingScheduler(n, true);
		}else{
			scheduler = new AgingScheduler(n, false);
		}
		
	}else if(algo == "c" || algo == "X"){
		
		if(algo == "X"){
			scheduler = new ClockScheduler(n, true);
		}else{
			scheduler = new ClockScheduler(n, false);
		}
		
	}

	//initialize the page table
	for(int i = 0; i < 64; i++){
		Pte entry;
		page_table.push_back(entry);
	}
	
	//initialize the Frame table
	for(int i = 0; i < max_frame_num; i++){
		frame_table.push_back(-1);
	}
	
}

MemoryManager::~MemoryManager()
{
	
}

void MemoryManager::print_page_table(){
	
	for(int i = 0; i < 64; i++){
		Pte page = page_table[i];
		
		if(page.get_present()){
			cout<<i<<":";
			
			if(page.get_referenced())
				cout<<"R";
			else
				cout<<"-";
			
			if(page.get_modified())
				cout<<"M";
			else
				cout<<"-";
			
			if(page.get_pageout())
				cout<<"S";
			else
				cout<<"-";
		
		}else{
			if(page.get_pageout())
				cout<<"#";
			else
				cout<<"*";
		}
		
		cout<<" ";
	}
	
	cout<<endl;
}

void MemoryManager::print_frame_table(bool is_last){
	for(int i = 0; i < max_frame_num; i++){
		if(frame_table[i] == -1){
			cout<<"* ";
		}else{
			cout<<frame_table[i]<<" ";
		}
	}
	
	if( (algo_type == "f" || algo_type == "s") && is_last == false){
		cout<<" || ";
		
		queue<int> q = scheduler->frame_queue;
		
		while(q.size()){
			cout<<q.front()<<" ";
			q.pop();
		}
	}
	
	if( (algo_type == "a" || algo_type == "Y") && is_last == false){
		cout<<" || ";
		
		vector<bitset<32>> tmp = scheduler->counters;
		
		
		for(int i = 0; i < frame_id; i++){
			cout<<i;
			cout<<":"<<tmp[i].to_ulong()<<" ";
		}
	}
	
	/*
	if( (algo_type == "l") && is_last == false){
		cout<<" || ";
		
		vector<int> q = scheduler->frame_vect;
		
		while(q.size()){
			cout<<q.front()<<" ";
			q.erase(q.begin());
		}
	}*/
	
	if( (algo_type == "c" || algo_type == "X") && is_last == false){
		cout<<" || ";
		
		cout<<"hand = "<<scheduler->clock_hand;
	}
	
	
	cout<<endl;
}

void MemoryManager::print_summary(){
	if(P)
		print_page_table();
	
	if(F)
		print_frame_table(true);
	
	if(S){
		long sum = instr_counter + (unmap_counter + map_counter) * 400
				   + (pageout_counter + pagein_counter) * 3000 +
				   zero_counter * 150;
		
		cout<<"SUM "<<instr_counter<<" U="<<unmap_counter<<" M="<<map_counter
		<<" I="<<pagein_counter<<" O="<<pageout_counter<<" Z="<<zero_counter
		<<" ===> "<<sum<<endl;
	}
		
}

void MemoryManager::handle_instr(int &rw, int &page_num){
	//get the page info from page table
	Pte page = page_table[page_num];
	
	//if O is true, print the content of the instruction
	if(O)
		cout<<"==> inst: "<<rw<<" "<<page_num<<endl;
	
	if(page.get_present() == 1){
		
		scheduler->update(page_num, page_table);
		
		if(rw == 0){
			page.set_referenced();
		}else{
			page.set_referenced();
			page.set_modified();
		}
		
	}else{
		
		//if the frame table still has space
		if(frame_id < max_frame_num){
			
			//the page: p will link to frame: frame_counter
			page.set_frame_index(frame_id);
			
			//put the frame into frame queue in FIFO
			scheduler->append_frame_queue(frame_id);
			
			if(O){
				cout<<instr_counter<<": ZERO"<<setw(9)<<frame_id<<endl;
				cout<<instr_counter<<": MAP"<<setw(6)<<page_num<<setw(4)<<frame_id<<endl;
			}
			
			map_counter++;
			zero_counter++;
			
			frame_table[frame_id] = page_num;
			
			frame_id++;
			
		//if frame table is full, we have to replace a frame
		}else{
			int victim_frame_id, replace_page;
			
			//find the victim frame
			victim_frame_id = scheduler->select_frame(page_table, frame_table);
			
			//find the page that was linked to the victim frame
			replace_page = frame_table[victim_frame_id];

			if(O){
				cout<<instr_counter<<": UNMAP"<<setw(4)<<replace_page<<setw(4)<<victim_frame_id<<endl;
			}
			
			unmap_counter++;
			
			//if the replace page is dirty
			if(page_table[replace_page].get_modified()){
				
				page_table[replace_page].reset_modified();
				page_table[replace_page].set_pageout();
				
				if(O){
					cout<<instr_counter<<": OUT"<<setw(6)<<replace_page<<setw(4)<<victim_frame_id<<endl;
				}
				
				pageout_counter++;
	
			}
			
			
			if(page_table[page_num].get_pageout()){
				
				if(O)
					cout<<instr_counter<<": IN"<<setw(7)<<page_num<<setw(4)<<victim_frame_id<<endl;
				
				pagein_counter++;
			}else{
				
				if(O)
					cout<<instr_counter<<": ZERO"<<setw(9)<<victim_frame_id<<endl;
				
				zero_counter++;
			}

			
			if(O){
				cout<<instr_counter<<": MAP"<<setw(6)<<page_num<<setw(4)<<victim_frame_id<<endl;
			}
			
			map_counter++;
			
			//reset the replaced page
			page.set_frame_index(victim_frame_id);
			frame_table[victim_frame_id] = page_num;
			page_table[replace_page].reset_present();
			page_table[replace_page].reset_referenced();
		}
		
		page.set_present();
		
		
		if(rw == 0){
			page.set_referenced();
		}else{
			page.set_referenced();
			page.set_modified();
		}
	}
	
	if(p)
		print_page_table();
	
	if(f)
		print_frame_table(false);
	
	
	
	instr_counter++;
	
}




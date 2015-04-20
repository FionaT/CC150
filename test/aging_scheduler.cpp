#include "aging_scheduler.h"
#include <iostream>

using namespace std;

AgingScheduler::AgingScheduler(){
}

AgingScheduler::AgingScheduler(int f, bool v){
	
	//cout<<"Aging scheduler frame_num "<<f<<endl;
	frame_num = f;
	is_v = v;
	clock_hand = 0;
	
	if(is_v){
		//if it is the virtual version, initialize counters according to the page number
		for(int i = 0; i < 64; i++){
			bitset<32> tmp(0);
			counters.push_back(tmp);
		}
		
	}else{
		//if it is the physical version, initialize counters according to the frame number
		//cout<<"aging physical"<<endl;
		
		for(int i = 0; i < frame_num; i++){
			bitset<32> tmp(0);
			counters.push_back(tmp);
		}
		
		//cout<<counters.size()<<endl;
	}
}

AgingScheduler::~AgingScheduler(){
	
}

int AgingScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int frame_id = 0;
	bool not_found = true;
	long min = 0;
	bitset<32> tmp;
	
	for(int i = 0; i < 32; i++){
		tmp[i] = 1;
	}
	
	min = tmp.to_ulong();
	
	if(is_v){
		
		for(int i = 0; i < page_table.size(); i++){
			Pte page = page_table[i];
			int r = page.get_referenced();
			int p = page.get_present();
			
			if(!p){
				continue;
			}
			
			counters[i] = (counters[i] >> 1);
			counters[i][31] = r;
			
			if(counters[i].to_ulong() < min){
				min = counters[i].to_ulong();
				frame_id = page.get_frame_index();
			}
			
			page.reset_referenced();
		}
		
		counters[frame_table[frame_id]] = 0;
		
	}else{
		
		for(int i = 0; i < frame_vect.size(); i++){
			Pte page = page_table[frame_table[frame_vect[i]]];
			int r = page.get_referenced();
			
			//shift one bit to the right
			counters[i] = (counters[i] >> 1);
			counters[i][31] = r;
			
			//cout<<i<<" "<<frame_table[frame_vect[i]]<<" "<<counters[i].to_string()<<" "<<r<<endl;
			
			if(counters[i].to_ulong() < min){
				min = counters[i].to_ulong();
				frame_id = i;
			}
			
			page.reset_referenced();
 		}
		
		counters[frame_id] = 0;
	}
	
	return frame_id;
}

void AgingScheduler::append_frame_queue(int frame_id){
	
	frame_vect.push_back(frame_id);
	
}

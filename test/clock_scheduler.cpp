#include "clock_scheduler.h"
#include <iostream>

using namespace std;

ClockScheduler::ClockScheduler(){
}

ClockScheduler::ClockScheduler(int f, bool v){
	//cout<<"Clock scheduler frame_num "<<f<<endl;
	frame_num = f;
	is_v = v;
	clock_hand = 0;
	/*
	if(is_v){
		cout<<"Clock Virtual"<<endl;
	}else{
		cout<<"Clock Physical"<<endl;
	}*/

}

ClockScheduler::~ClockScheduler(){
	
}

int ClockScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int frame_id = 0;
	Pte page;
	bool not_found = true;
	
	if(is_v){
		
		while(not_found){
			page = page_table[clock_hand];
			
			if(page.get_present() == 0){
				clock_hand++;
				clock_hand %= page_table.size();
				continue;
			}
			
			if(page.get_referenced()){
				
				page.reset_referenced();
				clock_hand++;
				clock_hand %= page_table.size();
				
				//cout<<"hand: "<<clock_hand<<" frame_id: "<<frame_id<<endl;
				
			}else{
				
				frame_id = page.get_frame_index();
				
				//cout<<"hand: "<<clock_hand<<" frame_id: "<<frame_id<<endl;
				
				clock_hand++;
				clock_hand %= page_table.size();
				break;
			}
		}
		
	}else{
		//Clock physical
		while(not_found){
			frame_id = frame_vect[clock_hand];
			page = page_table[frame_table[frame_id]];
			
			if(page.get_referenced()){
				
				page.reset_referenced();
				clock_hand++;
				clock_hand %= frame_table.size();
				
			}else{
				clock_hand++;
				clock_hand %= frame_table.size();
				break;
			}
		}
	}
	
	return frame_id;
}

void ClockScheduler::append_frame_queue(int frame_id){
	
	frame_vect.push_back(frame_id);
	
}

#include "2chance_scheduler.h"
#include <iostream>

using namespace std;

SecondChanceScheduler::SecondChanceScheduler(){
}

SecondChanceScheduler::SecondChanceScheduler(int f){
	//cout<<"FIFO scheduler frame_num "<<f<<endl;
	frame_num = f;
}

SecondChanceScheduler::~SecondChanceScheduler(){
	
}

int SecondChanceScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int frame_id = 0, page_id = 0;
	
	//select the first frame in the queue
	frame_id = frame_queue.front();
	page_id = frame_table[frame_id];
	
	//loop until we meet a page whose r bit is 0
	while(page_table[page_id].get_referenced()){
		page_table[page_id].reset_referenced();
		frame_queue.push(frame_id);
		frame_queue.pop();
		
		frame_id = frame_queue.front();
		page_id = frame_table[frame_id];
	}
	
	frame_queue.push(frame_id);
	frame_queue.pop();
		
	return frame_id;
}

void SecondChanceScheduler::append_frame_queue(int frame_id){
	
	//when a new page is used, map it into the frame_queue
	frame_queue.push(frame_id);
}

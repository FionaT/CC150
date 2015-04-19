#include "fifo_scheduler.h"
#include <iostream>

using namespace std;

FIFOScheduler::FIFOScheduler(){
}

FIFOScheduler::FIFOScheduler(int f){
	//cout<<"FIFO scheduler frame_num "<<f<<endl;
	frame_num = f;
}

FIFOScheduler::~FIFOScheduler(){
	
}

int FIFOScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int id = 0;
	
	//first come first out
	id = frame_queue.front();
	
	frame_queue.push(id);
	frame_queue.pop();
	
	return id;
}

void FIFOScheduler::append_frame_queue(int frame_id){
	
	frame_queue.push(frame_id);
	
}

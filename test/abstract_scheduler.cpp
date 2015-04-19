#include "abstract_scheduler.h"

AbstractScheduler::AbstractScheduler(){
}

AbstractScheduler::AbstractScheduler(int f, string rfile){
	random = new RandGen(rfile);
	frame_num = f;
	clock_hand = 0;
}

AbstractScheduler::AbstractScheduler(int f){
	frame_num = f;
}

AbstractScheduler::~AbstractScheduler(){
	
}

int AbstractScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int res = 1;
	
	return res;
}


void AbstractScheduler::append_frame_queue(int frame_id){
	
}

void AbstractScheduler::update(int page_num, vector<Pte> &page_table){
	
}
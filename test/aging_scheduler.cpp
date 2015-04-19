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
	/*
	if(is_v){
		cout<<"aging Virtual"<<endl;
	}else{
		cout<<"aging Physical"<<endl;
	}*/
}

AgingScheduler::~AgingScheduler(){
	
}

int AgingScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int id = 0;
	bool flag = true;
	
	//aging
	while(flag){
		
		
		
	}
	
	return id;
}

void AgingScheduler::append_frame_queue(int frame_id){
	
	frame_vect.push_back(frame_id);
	
}

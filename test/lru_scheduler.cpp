#include "lru_scheduler.h"
#include <iostream>

using namespace std;

LRUScheduler::LRUScheduler(){
}

LRUScheduler::LRUScheduler(int f){
	//cout<<"LRU scheduler frame_num "<<f<<endl;
	frame_num = f;
}

LRUScheduler::~LRUScheduler(){
	
}

int LRUScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int frame_id = 0;

	frame_id = frame_vect.front();
	
	frame_vect.push_back(frame_id);
	frame_vect.erase(frame_vect.begin());
	
	return frame_id;
}

void LRUScheduler::append_frame_queue(int frame_id){
	
	frame_vect.push_back(frame_id);
}


void LRUScheduler::update(int page_num, vector<Pte> &page_table){
	
	int frame_id = page_table[page_num].get_frame_index();
	int pos = -1;
	
	for(int i = 0; i < frame_vect.size(); i++){
		if(frame_vect[i] == frame_id){
			pos = i;
			break;
		}
	}
	
	frame_vect.erase(frame_vect.begin() + pos);
	frame_vect.push_back(frame_id);
}

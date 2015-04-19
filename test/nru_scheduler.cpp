#include "NRU_scheduler.h"
#include <iostream>

using namespace std;

NRUScheduler::NRUScheduler(){
}

NRUScheduler::NRUScheduler(int f, string rfile){
	
	//initialize
	random = new RandGen(rfile);
	frame_num = f;
	reset_counter = 0;
}

NRUScheduler::~NRUScheduler(){
	
}

int NRUScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int res = -1;
	vector<vector<int>> classes(4, vector<int>());
	
	//put all present pages into 4 classes by their r bit and m bit
	//attention that the return value is the frame number
	for(int i = 0; i < page_table.size(); i++){
		Pte p = page_table[i];
		
		if(p.get_present()){
			int r = p.get_referenced();
			int m = p.get_modified();
			
			if(r && m){
				classes[3].push_back(p.get_frame_index());
			}else if(r){
				classes[2].push_back(p.get_frame_index());
			}else if(m){
				classes[1].push_back(p.get_frame_index());
			}else{
				classes[0].push_back(p.get_frame_index());
			}
		}
	}
	
	//choose the page at random from the lowest numbered nonempty class
	//but the return value is the frame number
	for(int i = 0; i < classes.size(); i++){
		if(classes[i].size()){
			res = classes[i][random->get_next(classes[i].size())];
			break;
		}
	}
	
	reset_counter++;
	
	//we shall reset the ref bits every 10th page replacement
	if(reset_counter == 10){
		for(int i = 0; i < page_table.size(); i++){
			page_table[i].reset_referenced();
		}
		
		reset_counter = 0;
	}
	
	return res;
}



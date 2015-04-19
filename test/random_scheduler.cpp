#include "random_scheduler.h"
#include <iostream>

using namespace std;

RandomScheduler::RandomScheduler(){
}

RandomScheduler::RandomScheduler(int f, string rfile){
	//cout<<"random scheduler frame_num "<<f<<endl;
	frame_num = f;
	random = new RandGen(rfile);
}

RandomScheduler::~RandomScheduler(){
	
}

int RandomScheduler::select_frame(vector<Pte> &page_table, vector<int> &frame_table){
	int res = -1;
	
	//select a random frame to be replaced
	res = random->get_next(frame_num);
	
	return res;
}
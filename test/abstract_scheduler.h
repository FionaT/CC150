#ifndef ABSTRACT_SCHEDULER_H
#define ABSTRACT_SCHEDULER_H

#include <vector>
#include <queue>
#include "randgen.h"
#include "pte.h"

using namespace std;

class AbstractScheduler
{
public:
	int frame_num;
	int clock_hand;
	RandGen *random;
	queue<int> frame_queue;
	vector<int> frame_vect;
	
	AbstractScheduler();
	AbstractScheduler(int n);
	AbstractScheduler(int n, string rfile);
    ~AbstractScheduler();
	
	virtual int select_frame(vector<Pte> &page_table, vector<int> &frame_table);
	virtual void append_frame_queue(int frame_id);
	virtual void update(int page_num, vector<Pte> &page_table);
};

#endif // ABSTRACT_SCHEDULER_H
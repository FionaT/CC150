#ifndef CLOCK_SCHEDULER_H
#define CLOCK_SCHEDULER_H

#include <vector>
#include <queue>
#include "abstract_scheduler.h"

using namespace std;

class ClockScheduler : public AbstractScheduler
{
public:
	int frame_num;
	bool is_v;
	//int clock_hand;
	
	ClockScheduler();
    ClockScheduler(int f, bool v);
    ~ClockScheduler();
	
	virtual int select_frame(vector<Pte> &page_table, vector<int> &frame_table);
	virtual void append_frame_queue(int frame_id);
	
};

#endif // CLOCK_SCHEDULER_H
#ifndef AGING_SCHEDULER_H
#define AGING_SCHEDULER_H

#include <vector>
#include <queue>
#include "abstract_scheduler.h"

using namespace std;

class AgingScheduler : public AbstractScheduler
{
public:
	int frame_num;
	bool is_v;
	int clock_hand;
	
	AgingScheduler();
    AgingScheduler(int f, bool v);
    ~AgingScheduler();
	
	virtual int select_frame(vector<Pte> &page_table, vector<int> &frame_table);
	virtual void append_frame_queue(int frame_id);
};

#endif // AGING_SCHEDULER_H
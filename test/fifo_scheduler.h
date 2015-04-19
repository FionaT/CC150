#ifndef FIFO_SCHEDULER_H
#define FIFO_SCHEDULER_H

#include <vector>
#include <queue>
#include "abstract_scheduler.h"

using namespace std;

class FIFOScheduler : public AbstractScheduler
{
public:
	int frame_num;

	FIFOScheduler();
    FIFOScheduler(int f);
    ~FIFOScheduler();
	
	virtual int select_frame(vector<Pte> &page_table, vector<int> &frame_table);
	virtual void append_frame_queue(int frame_id);
};

#endif // FIFO_SCHEDULER_H
#ifndef SECONDCHANCE_SCHEDULER_H
#define SECONDCHANCE_SCHEDULER_H

#include <vector>
#include <queue>
#include "abstract_scheduler.h"

using namespace std;

class SecondChanceScheduler : public AbstractScheduler
{
public:
	int frame_num;
	
	SecondChanceScheduler();
    SecondChanceScheduler(int f);
    ~SecondChanceScheduler();
	
	virtual int select_frame(vector<Pte> &page_table, vector<int> &frame_table);
	virtual void append_frame_queue(int frame_id);
};

#endif // SECONDCHANCE_SCHEDULER_H
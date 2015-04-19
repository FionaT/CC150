#ifndef LRU_SCHEDULER_H
#define LRU_SCHEDULER_H

#include <vector>
#include <queue>
#include "abstract_scheduler.h"

using namespace std;

class LRUScheduler : public AbstractScheduler
{
public:
	int frame_num;
	
	LRUScheduler();
    LRUScheduler(int f);
    ~LRUScheduler();
	
	virtual int select_frame(vector<Pte> &page_table, vector<int> &frame_table);
	virtual void append_frame_queue(int frame_id);
	virtual void update(int page_num, vector<Pte> &page_table);
};

#endif // LRU_SCHEDULER_H
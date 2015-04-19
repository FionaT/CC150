#ifndef NRU_SCHEDULER_H
#define NRU_SCHEDULER_H

#include <vector>
#include "randgen.h"
#include "abstract_scheduler.h"

using namespace std;

class NRUScheduler : public AbstractScheduler
{
public:
	int frame_num;
	int reset_counter;
	RandGen *random;
	
	NRUScheduler();
    NRUScheduler(int f, string rfile);
    ~NRUScheduler();
	
	virtual int select_frame(vector<Pte> &page_table, vector<int> &frame_table);
};

#endif // _SCHEDULER_H
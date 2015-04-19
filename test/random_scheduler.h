#ifndef RANDOM_SCHEDULER_H
#define RANDOM_SCHEDULER_H

#include <vector>
#include "randgen.h"
#include "abstract_scheduler.h"

using namespace std;

class RandomScheduler : public AbstractScheduler
{
public:
	int frame_num;
	RandGen *random;
	
	RandomScheduler();
    RandomScheduler(int f, string rfile);
    ~RandomScheduler();
	
	virtual int select_frame(vector<Pte> &page_table, vector<int> &frame_table);
};

#endif // RANDOM_SCHEDULER_H
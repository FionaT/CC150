#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>
#include <string>
#include "abstract_scheduler.h"
#include "pte.h"

using namespace std;

class MemoryManager
{
public:
	int max_frame_num;
	int frame_id;
	string algo_type;
	bool O, P, F, S, p, f;
	long instr_counter, unmap_counter, map_counter,
	     pagein_counter, pageout_counter, zero_counter;
	
	AbstractScheduler *scheduler;
	vector<Pte> page_table;
	vector<int> frame_table;
	
    MemoryManager(string algo, int n, string rfile, bool the_O, bool the_P, bool the_F, bool the_S, bool the_p, bool the_f);
    ~MemoryManager();
	
	void handle_instr(int &rw, int &page_num);
	void print_page_table();
	void print_frame_table(bool is_last);
	void print_summary();

};

#endif // INSTRUCTION_HANDLER_H
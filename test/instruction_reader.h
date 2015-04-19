#ifndef INSTRUCTION_READER_H
#define INSTRUCTION_READER_H

#include "memory_manager.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class InstructionReader
{
public:
	//bool O, P, F, S, p, f;
	int frame_num;
	ifstream input_file;
	
    InstructionReader();
    ~InstructionReader();
	
	MemoryManager* initialize(string &command, string &filename);
	void read_instr(string instr, int &rw, int &page_num);
};

#endif // INSTRUCTION_READER_H
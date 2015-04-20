#include "instruction_reader.h"
#include "memory_manager.h"
#include <fstream>
#include <sstream>
#include <iostream>


InstructionReader::InstructionReader()
{
	
}

InstructionReader::~InstructionReader()
{
	
}

MemoryManager* InstructionReader::initialize(string &command, string &filename){
	
	filename = "in1M2";
	frame_num = 32;
	
	bool O = false;
	bool P = true;
	bool F = true;
	bool S = true;
	bool p = false;
	bool f = false;
	
	string rfile_name = "rfile";
	string algo = "Y";
	
	MemoryManager *MM = new MemoryManager(algo, frame_num, rfile_name, O, P, F, S, p, f);
	
	return MM;
}

void InstructionReader::read_instr(string instr, int &rw, int &page_num){
	if(instr[0] == '#'){
		rw = -1;
		return ;
	}
	
	istringstream iss(instr);
	string sub;
	
	iss>>sub;
	rw = stoi(sub);
	
	iss>>sub;
	page_num = stoi(sub);
}




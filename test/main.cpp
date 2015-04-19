//
//  main.cpp
//  lab3
//
//  Created by Fiona on 15/4/16.
//  Copyright (c) 2015年 Fiona. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <fstream>
#include <sstream>
#include "randgen.h"
#include "instruction_reader.h"
#include "memory_manager.h"
#include <bitset>



int main(int argc, const char * argv[])
{
	/*
	 bitset<5> *temp;
	 temp = new bitset<5>(6);
	 
	 cout<<*temp<<endl;
	 cout<<temp->to_ulong()<<endl;
	 (*temp)[0] = 1;
	 
	 
	 cout<<*temp<<endl;
	 cout<<temp->to_ulong()<<endl;
	 
	 bitset<2> sub;
	 
	 for(int i = 0; i < 2; i++){
	 sub[i] = (*temp)[i + 2];
	 }
	 
	 cout<<sub<<endl;
	 cout<<sub.to_ulong()<<endl;
	 */
	
	
	
	string filename, line;
	string command = "-ar –oOPFS -f4 in18 rfile";
	int rw, page_num;
	InstructionReader reader;
	MemoryManager *MM;
    
	MM = reader.initialize(command, filename);
	
	ifstream the_file(filename);
	
	if (!the_file.is_open()) {
        cout<<"Could not open file\n";
        return false;
    }
	
	while(getline(the_file, line)) {
		
		reader.read_instr(line, rw, page_num);
		
		if(rw == -1)
			continue;
		
		MM->handle_instr(rw, page_num);
	}
	
	
	MM->print_summary();
	
	
    return 0;
}


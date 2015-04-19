#include "randgen.h"
#include <fstream>
#include <sstream>
#include <iostream>

int RandGen::ofs = 0;
vector<int> RandGen::random_num;

RandGen::RandGen()
{
	
}

RandGen::RandGen(string rfile)
{
	read_rfile(rfile);
}

RandGen::~RandGen()
{

}

bool RandGen::read_rfile(string filename)
{
    ifstream the_file(filename);

    if (!the_file.is_open()) {
        cout<<"Could not open file\n";
        return false;
    }

    string line;

    getline(the_file, line);
    int num = stoi(line);
    int x;

    for(int i = 0; i < num; i++){
        getline(the_file, line);
        x = stoi(line);
        random_num.push_back(x);
    }

    return true;
}

int RandGen::get_next(int seed)
{
	if(ofs == random_num.size())
		ofs = 0;
	
	int result;
	
	if(seed != 0)
		result = random_num[ofs] % seed;
	else
		result = -1;
	
	
	ofs++;

	return result;
}


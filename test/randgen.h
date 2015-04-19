#ifndef RANDGEN_H
#define RANDGEN_H

#include <vector>
#include <string>

using namespace std;

class RandGen
{
public:
    RandGen();
	RandGen(string rfile);
    ~RandGen();

    static bool read_rfile(string filename);
    static int get_next(int burst);

    static int ofs;
    static vector<int> random_num;
};

#endif // RANDGEN_H

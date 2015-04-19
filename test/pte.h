#ifndef PTE_H
#define PTE_H

#include <bitset>

using namespace std;

class Pte
{
public:
	bitset<32> *entry;
	
	Pte();
    ~Pte();
	
	int get_present();
	void reset_present();
	void set_present();
	int get_modified();
	void reset_modified();
	void set_modified();
	int get_referenced();
	void reset_referenced();
	void set_referenced();
	int get_pageout();
	void reset_pageout();
	void set_pageout();
	int get_frame_index();
	void set_frame_index(int x);
};

#endif // PTE_H
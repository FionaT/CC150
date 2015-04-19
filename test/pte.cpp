#include "pte.h"

Pte::Pte(){
	entry = new bitset<32>(0);
}

Pte::~Pte(){
	
}

int Pte::get_present(){
	return (*entry)[0];
}

void Pte::reset_present(){
	(*entry)[0] = 0;
}

void Pte::set_present(){
	(*entry)[0] = 1;
}

int Pte::get_modified(){
	return (*entry)[1];
}

void Pte::reset_modified(){
	(*entry)[1] = 0;
}

void Pte::set_modified(){
	(*entry)[1] = 1;
}

int Pte::get_referenced(){
	return (*entry)[2];
}

void Pte::reset_referenced(){
	(*entry)[2] = 0;
}

void Pte::set_referenced(){
	(*entry)[2] = 1;
}

int Pte::get_pageout(){
	return (*entry)[3];
}

void Pte::set_pageout(){
	(*entry)[3] = 1;
}

void Pte::reset_pageout(){
	(*entry)[3] = 0;
}

int Pte::get_frame_index(){
	int index = 0;
	bitset<28> sub;
	
	for(int i = 0; i < 28; i++){
		sub[i] = (*entry)[i + 4];
	}
	
	index = (int)sub.to_ulong();
	
	return index;
}

void Pte::set_frame_index(int x){
	bitset<28> index(x);
	
	for(int i = 0; i < 28; i++){
		(*entry)[i + 4] = index[i];
	}
}


#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "CllEnum.hpp"

#define CELLMAX 2048
#define MAX_LOOP_STATES 16
class Cll
{
private:
	unsigned curr_state;
	int state_pointer[MAX_LOOP_STATES];
	std::string command;		// The string that holds the current command, also takes cells and casts them as ints.(removing the #)
	std::ifstream cellfile;		// The file that the code is being read from.
	long long cell[CELLMAX];	// The cells that the user manipulates through the language.
	int temp[8];				// Temp variables for casting cell numbers into.
public:
	Cll(const std::string &file);
	void go();					// This functions "drives" the language, using it to go through the language until it reaches an "exit"
	void print();
	void printc();
	void prints();
	void printp();
	void read();
	void readc();
	void reads();
	void set();
	void setc();
	void sets();
	void add();
	void sub();
	void div();
	void mul();
	void exp();
	void cpy();
	void mov();
	void swp();
	void len();
	void inc();
	void dec();
	void w_go();
	void i_go();

	~Cll();
};


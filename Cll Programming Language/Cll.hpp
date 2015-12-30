#pragma once
#include <string>
#include <iostream>
#include <fstream>

#define CELLMAX 2048

class Cll
{
private:
	std::string command;		// The string that holds the current command, also takes cells and casts them as ints.(removing the #)
	std::ifstream cellfile;		// The file that the code is being read from.
	long long cell[CELLMAX];	// The cells that the user manipulates through the language.
	int temp[8];				// Temp variables for casting cell numbers into.
public:
	Cll(std::string file);
	void go();					// This functions "drives" the language, using it to go through the language until it reaches an "exit"
	void print();
	void printc();
	void set();
	void setc();
	void add();
	void sub();
	void div();
	void mul();
	void exp();
	void inc();
	void dec();


	~Cll();
};


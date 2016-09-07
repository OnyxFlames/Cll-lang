#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "CllEnum.hpp"
#include "error_definitions.hpp"


#define CELLMAX 2048
#define MAX_LOOP_STATES 16
class Cll
{
private:
	unsigned curr_state;
	std::streamoff state_pointer[MAX_LOOP_STATES];
	char OP = 0;				// the opcode that is deduced from the member 'command'.
	std::string command;		// The string that holds the current command, also takes cells and casts them as ints.(removing the #)
	std::ifstream cellfile;		// The file that the code is being read from.
	long long cell[CELLMAX];	// The cells that the user manipulates through the language.
	int temp[4];				// Temp variables for casting cell numbers into.
public:
	Cll(const std::string &file);
	int get_num_val(std::string &command)
	{
		// Assure that the command is prefixed with a '#' so it's referring to a cell.
		if (command[0] != '#')
		{
			std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
			exit(NOT_A_CELL);
		}
		// Remove the '#' and convert the string number to an actual number, then return it.
		command[0] = ' ';
		return std::stoi(command);
	}

	void go();					// This functions "drives" the language, using it to go through the language until it reaches an "exit"
	void callfunc(char &opcode);
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
	void ret();

	~Cll();
};


#include "CllEnum.hpp"

char str_to_enum(const std::string &cmd)
{
	if (cmd == "print")
		return PRINT;
	else if (cmd == "printc")
		return PRINTC;
	else if (cmd == "prints")
		return PRINTS;
	else if (cmd == "printp")
		return PRINTP;
	else if (cmd == "read")
		return READ;
	else if (cmd == "readc")
		return READC;
	else if (cmd == "reads")
		return READS;
	else if (cmd == "set")
		return SET;
	else if (cmd == "setc")
		return SETC;
	else if (cmd == "sets")
		return SETS;
	else if (cmd == "add")
		return ADD;
	else if (cmd == "sub")
		return SUB;
	else if (cmd == "mul")
		return MUL;
	else if (cmd == "div")
		return DIV;
	else if (cmd == "exp")
		return EXP;
	else if (cmd == "cpy")
		return CPY;
	else if (cmd == "mov")
		return MOV;
	else if (cmd == "swp")
		return SWP;
	else if (cmd == "len")
		return LEN;
	else if (cmd == "inc")
		return INC;
	else if (cmd == "dec")
		return DEC;
	else if (cmd == "if")
		return I_GO;
	else if (cmd == "while")
		return W_GO;
	else if (cmd == "sizeof")
		return SIZEOF;
}
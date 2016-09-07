#pragma once

#include <string>

enum functions : char
{
	PRINT,
	PRINTC,
	PRINTS,
	PRINTP,
	READ,
	READC,
	READS,
	SET,
	SETC,
	SETS,
	ADD,
	SUB,
	MUL,
	DIV,
	EXP,
	CPY,
	MOV,
	SWP,
	LEN,
	INC,
	DEC,
	I_GO,
	W_GO,
	IF,
	WHILE,
	SIZEOF,
	END,
	EXIT,
};
char str_to_enum(const std::string &cmd);
#include <iostream>

#include "cll.hpp"

int main(int argc, char* argv[])
{

	if (argc < 2)
	{
		std::cerr << "Cll: no file passed. Closing." << std::endl;
		exit(-3);
	}
	Cll cll(argv[1]);
	cll.go();

	return 0;
}
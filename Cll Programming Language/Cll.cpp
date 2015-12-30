#include "Cll.hpp"


Cll::Cll(std::string file)
{
	cellfile.open(file);
	if (!cellfile)
	{
		std::cerr << "Cll: " << file << " is not a file or has failed to open!" << std::endl;
		exit(-1);
	}
}
void Cll::go()
{
	while (command != "exit")
	{
		cellfile >> command;
		if (command == "print")
			print();
		if (command == "printc")
			printc();
		if (command == "set")
			set();
		if (command == "setc")
			setc();
		if (command == "add")
			add();
		if (command == "sub")
			sub();
		if (command == "mul")
			mul();
		if (command == "div")
			div();
		if (command == "exp")
			exp();
		if (command == "inc")
			inc();
		if (command == "dec")
			dec();
		if (command == "sizeof")
			std::cout << sizeof(long long) * 8 << std::endl;
		
		
		
		if (cellfile.eof() && command != "exit")
		{
			std::cerr << "Cll: Reached end of file without \"exit\"! Undefined behavior." << std::endl;
			exit(-2);
		}
	}
}
void Cll::print()
{
		cellfile >> command;
		if (command[0] != '#')
		{
			std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
			exit(-4);
		}
		command[0] = ' ';
		temp[0] = stoi(command);
		std::cout << cell[temp[0]] << std::endl;
}
void Cll::printc()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-4);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	std::cout << (char)cell[temp[0]] << std::endl;
}
void Cll::set()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-4);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	temp[1] = stoi(command);
	cell[temp[0]] = temp[1];
}
void Cll::setc()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-4);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	temp[1] = command[0];
	cell[temp[0]] = temp[1];
}
void Cll::add()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[1] = stoi(command);
	cell[temp[0]] = cell[temp[0]] + cell[temp[1]];
}
void Cll::sub()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[1] = stoi(command);
	cell[temp[0]] = cell[temp[0]] - cell[temp[1]];
}
void Cll::mul()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[1] = stoi(command);
	cell[temp[0]] = cell[temp[0]] * cell[temp[1]];
}
void Cll::div()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[1] = stoi(command);
	cell[temp[0]] = cell[temp[0]] / cell[temp[1]];
}
void Cll::exp()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[1] = stoi(command);
	cell[temp[0]] = pow(cell[temp[0]], cell[temp[1]]);
}
void Cll::inc()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cell[temp[0]]++;
}
void Cll::dec()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cell[temp[0]]--;
}
Cll::~Cll()
{
}

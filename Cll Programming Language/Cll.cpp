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
		if (command == "prints")
			prints();
		if (command == "set")
			set();
		if (command == "setc")
			setc();
		if (command == "sets")
			sets();
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
		if (command == "cpy")
			cpy();
		if (command == "mov")
			mov();
		if (command == "swp")
			swp();
		if (command == "inc")
			inc();
		if (command == "dec")
			dec();
		if (command == "while")
			w_go();
		if (command == "sizeof")
			std::cout << sizeof(long long) * 8 << std::endl;
		
		
		
		if (cellfile.eof() && command != "exit")
		{
			std::cerr << "\nCll: Reached end of file without \"exit\"! Undefined behavior." << std::endl;
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
void Cll::prints()
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
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-4);
	}
	command[0] = ' ';
	temp[1] = stoi(command);
	
	if (temp[0] < temp[1])
	{
		while (temp[0] <= temp[1])
		{
			std::cout << (char)cell[temp[0]++];
		}
	}
	else if (temp[0] > temp[1])
	{
		while (temp[0] >= temp[1])
		{
			std::cout << (char)cell[temp[0]--];
		}
	}
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
void Cll::sets()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-4);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	std::getline(cellfile, command);
	command.erase(command.begin());
	for (char c : command)
	{ 
		cell[temp[0]] = c;
		temp[0] = temp[0] + 1;
	}
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
void Cll::cpy()
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

	cell[temp[0]] = cell[temp[1]];
}
void Cll::mov()
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

	cell[temp[0]] = cell[temp[1]];
	cell[temp[1]] = 0x0000;
}
void Cll::swp()
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
	long long tempbuff = 0x0000;
	tempbuff = cell[temp[0]];
	cell[temp[0]] = cell[temp[1]];
	cell[temp[1]] = tempbuff;
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
void Cll::w_go()				
{
	int length = cellfile.tellg();
	int buffer;
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-1);
	}

	command[0] = ' ';
	buffer = stoi(command);

	while (cell[buffer] != 0)
	{
		cellfile >> command;
		if (command == "print")
			print();
		if (command == "printc")
			printc();
		if (command == "prints")
			prints();
		if (command == "set")
			set();
		if (command == "setc")
			setc();
		if (command == "sets")
			sets();
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
		if (command == "cpy")
			cpy();
		if (command == "mov")
			mov();
		if (command == "swp")
			swp();
		if (command == "inc")
			inc();
		if (command == "dec")
			dec();
		if (command == "while")
			w_go();
		if (command == "sizeof")
			std::cout << sizeof(long long) * 8 << std::endl;
		if (command == "end")
		{
			cellfile.seekg(length);
		}
	}
}
Cll::~Cll()
{
}

#include "Cll.hpp"
#include "error_definitions.hpp"

Cll::Cll(const std::string &file)
{
	for (int i = MAX_LOOP_STATES;
		i > 0; i--)
	{
		state_pointer[i] = -1;
	}
	cellfile.open(file);
	if (!cellfile)
	{
		std::cerr << "Cll: " << file << " is not a file or has failed to open!" << std::endl;
		exit(BAD_FILE);
	}
}
void Cll::go()
{
	while (command != "exit")
	{
		cellfile >> command;
		if (command == "print")
			print();
		else if (command == "printc")
			printc();
		else if (command == "prints")
			prints();
		else if (command == "printp")
			printp();
		else if (command == "read")
			read();
		else if (command == "readc")
			readc();
		else if (command == "reads")
			reads();
		else if (command == "set")
			set();
		else if (command == "setc")
			setc();
		else if (command == "sets")
			sets();
		else if (command == "add")
			add();
		else if (command == "sub")
			sub();
		else if (command == "mul")
			mul();
		else if (command == "div")
			div();
		else if (command == "exp")
			exp();
		else if (command == "cpy")
			cpy();
		else if (command == "mov")
			mov();
		else if (command == "swp")
			swp();
		else if (command == "len")
			len();
		else if (command == "inc")
			inc();
		else if (command == "dec")
			dec();
		else if (command == "if")
			i_go();
		else if (command == "while")
			w_go();
		else if (command == "sizeof")
			std::cout << sizeof(long long) * 8 << std::endl;
		
		
		
		if (cellfile.eof() && command != "exit")
		{
			std::cerr << "\nCll: Reached end of file without \"exit\"! Undefined behavior." << std::endl;
			exit(END_WITHOUT_EXIT);
		}
	}
}
void Cll::print()
{
		cellfile >> command;
		if (command[0] != '#')
		{
			std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
			exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
void Cll::printp()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[1] = stoi(command);

	if (temp[0] <= cell[temp[1]])
	{
		while (temp[0] <= cell[temp[1]])
		{
			std::cout << (char)cell[temp[0]++];
		}
	}
	else if (temp[0] >= cell[temp[1]])
	{
		while (temp[0] >= cell[temp[1]])
		{
			std::cout << (char)cell[temp[0]--];
		}
	}
}
void Cll::read()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-4);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	std::cin >> cell[temp[0]];
}
void Cll::readc()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	std::cin >> command;
	cell[temp[0]] = command[0];
}
void Cll::reads()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	/*if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(-4);
	}
	command[0] = ' ';*/
	temp[1] = stoi(command);
	std::cin >> command;
	if (command.length() > temp[1])
		command.erase(command.begin() + temp[1], command.end());
	for (auto c : command)
		cell[temp[0]++] = c;
}
void Cll::set()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	std::getline(cellfile, command);
	std::cout << "DEBUG: " << command << "\n";
	command.at(0);
	command.erase(command.begin());
	for (char &c : command)
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[1] = stoi(command);
	long long tempbuff = 0x0000;
	tempbuff = cell[temp[0]];
	cell[temp[0]] = cell[temp[1]];
	cell[temp[1]] = tempbuff;
}
void Cll::len()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[1] = stoi(command);
	int buffer = 0x0000;
	while (cell[temp[1]] != 0)
	{
		buffer++;
		temp[1]++;
	}
	cell[temp[0]] = buffer;
}
void Cll::inc()
{
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
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
		exit(NOT_A_CELL);
	}
	command[0] = ' ';
	temp[0] = stoi(command);
	cell[temp[0]]--;
}
void Cll::w_go()				
{
	if (curr_state == MAX_LOOP_STATES)
	{
		std::cerr << "Max loop states reached! Max: " << MAX_LOOP_STATES << "Current: " << curr_state << std::endl;
		exit(MAX_LOOP_STATE);
	}
	state_pointer[++curr_state] = cellfile.tellg();
	int buffer;
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}

	command[0] = ' ';
	buffer = stoi(command);

	while (cell[buffer] != 0)
	{
		cellfile >> command;
		if (command == "print")
			print();
		else if (command == "printc")
			printc();
		else if (command == "prints")
			prints();
		else if (command == "printp")
			printp();
		else if (command == "read")
			read();
		else if (command == "readc")
			readc();
		else if (command == "reads")
			reads();
		else if (command == "set")
			set();
		else if (command == "setc")
			setc();
		else if (command == "sets")
			sets();
		else if (command == "add")
			add();
		else if (command == "sub")
			sub();
		else if (command == "mul")
			mul();
		else if (command == "div")
			div();
		else if (command == "exp")
			exp();
		else if (command == "cpy")
			cpy();
		else if (command == "mov")
			mov();
		else if (command == "swp")
			swp();
		else if (command == "len")
			len();
		else if (command == "inc")
			inc();
		else if (command == "dec")
			dec();
		else if (command == "if")
			i_go();
		else if (command == "while")
			w_go();
		else if (command == "sizeof")
			std::cout << sizeof(long long) * 8 << std::endl;
		else if (command == "end")
		{
			if (state_pointer[curr_state] == -1)
			{
				std::cerr << "Unexpected \"end\" reached!" << std::endl;
				exit(-4);
			}
			cellfile.seekg(state_pointer[curr_state--]);
		}
	}
}
void Cll::i_go()
{
	if (curr_state == MAX_LOOP_STATES)
	{
		std::cerr << "Max loop states reached! Max: " << MAX_LOOP_STATES << "Current: " << curr_state << std::endl;
		exit(MAX_LOOP_STATE);
	}
	state_pointer[++curr_state] = cellfile.tellg();
	int buffer;
	cellfile >> command;
	if (command[0] != '#')
	{
		std::cerr << "Error: " << command << " is not a cell. Expected a cell within 0 - " << CELLMAX << std::endl;
		exit(NOT_A_CELL);
	}

	command[0] = ' ';
	buffer = stoi(command);

	while (cell[buffer] != 0)
	{
		cellfile >> command;
		if (command == "print")
			print();
		else if (command == "printc")
			printc();
		else if (command == "prints")
			prints();
		else if (command == "printp")
			printp();
		else if (command == "read")
			read();
		else if (command == "readc")
			readc();
		else if (command == "reads")
			reads();
		else if (command == "set")
			set();
		else if (command == "setc")
			setc();
		else if (command == "sets")
			sets();
		else if (command == "add")
			add();
		else if (command == "sub")
			sub();
		else if (command == "mul")
			mul();
		else if (command == "div")
			div();
		else if (command == "exp")
			exp();
		else if (command == "cpy")
			cpy();
		else if (command == "mov")
			mov();
		else if (command == "swp")
			swp();
		else if (command == "len")
			len();
		else if (command == "inc")
			inc();
		else if (command == "dec")
			dec();
		else if (command == "if")
			i_go();
		else if (command == "while")
			w_go();
		else if (command == "sizeof")
			std::cout << sizeof(long long) * 8 << std::endl;
		else if (command == "end")
		{
			if (state_pointer[curr_state] == -1)
			{
				std::cerr << "Unexpected \"end\" reached!" << std::endl;
				exit(-4);
			}
			cellfile.seekg(state_pointer[++curr_state]);
		}
	}
}
Cll::~Cll()
{
}

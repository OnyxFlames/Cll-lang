#include "Cll.hpp"

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
		OP = str_to_enum(command);

		callfunc(OP);
		
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
		temp[0] = get_num_val(command);
		std::cout << cell[temp[0]] << std::endl;
}
void Cll::printc()
{
	cellfile >> command;
	temp[0] = get_num_val(command);
	std::cout << (char)cell[temp[0]] << std::endl;
}
void Cll::prints()
{
	cellfile >> command;
	temp[0] = get_num_val(command);
	cellfile >> command;
	temp[1] = get_num_val(command);
	
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
	temp[0] = get_num_val(command);
	cellfile >> command;
	temp[1] = get_num_val(command);

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
	temp[0] = get_num_val(command);
	std::cin >> cell[temp[0]];
}
void Cll::readc()
{
	cellfile >> command;
	temp[0] = get_num_val(command);
	std::cin >> command;
	cell[temp[0]] = command[0];
}
void Cll::reads()
{
	cellfile >> command;
	temp[0] = get_num_val(command);
	cellfile >> command;
	temp[1] = stoi(command);
	std::cin >> command;
	if (command.length() > (size_t)temp[1])
		command.erase(command.begin() + temp[1], command.end());
	for (auto c : command)
		cell[temp[0]++] = c;
}
void Cll::set()
{
	cellfile >> command;
	temp[0] = get_num_val(command);
	cellfile >> command;
	temp[1] = stoi(command);
	cell[temp[0]] = temp[1];
}
void Cll::setc()
{
	cellfile >> command;
	temp[0] = get_num_val(command);
	cellfile >> command;
	temp[1] = command[0];
	cell[temp[0]] = temp[1];
}
void Cll::sets()
{
	cellfile >> command;
	temp[0] = get_num_val(command);
	std::getline(cellfile, command);
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
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

	cell[temp[0]] = cell[temp[0]] + cell[temp[1]];
}
void Cll::sub()
{
	cellfile >> command;
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

	cell[temp[0]] = cell[temp[0]] - cell[temp[1]];
}
void Cll::mul()
{
	cellfile >> command;
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

	cell[temp[0]] = cell[temp[0]] * cell[temp[1]];
}
void Cll::div()
{
	cellfile >> command;
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

	cell[temp[0]] = cell[temp[0]] / cell[temp[1]];
}
void Cll::exp()
{
	cellfile >> command;
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

	cell[temp[0]] = (long long)std::pow(cell[temp[0]], cell[temp[1]]);
}
void Cll::cpy()
{
	cellfile >> command;
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

	cell[temp[0]] = cell[temp[1]];
}
void Cll::mov()
{
	cellfile >> command;
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

	cell[temp[0]] = cell[temp[1]];
	cell[temp[1]] = 0x0000;
}
void Cll::swp()
{
	cellfile >> command;
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

	long long tempbuff = 0x0000;
	tempbuff = cell[temp[0]];
	cell[temp[0]] = cell[temp[1]];
	cell[temp[1]] = tempbuff;
}
void Cll::len()
{
	//TODO: Pick up here
	cellfile >> command;
	temp[0] = get_num_val(command);

	cellfile >> command;
	temp[1] = get_num_val(command);

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
	temp[0] = get_num_val(command);

	cell[temp[0]]++;
}
void Cll::dec()
{
	cellfile >> command;
	temp[0] = get_num_val(command);

	cell[temp[0]]--;
}
void Cll::w_go()				
{
	if (curr_state == MAX_LOOP_STATES)
	{
		std::cerr << "Max loop states reached! Max: " << MAX_LOOP_STATES << "Current: " << curr_state << std::endl;
		exit(MAX_LOOP_STATE);
	}
	state_pointer[++curr_state] = /*(long long)*/cellfile.tellg();
	int buffer;
	cellfile >> command;
	buffer = get_num_val(command);

	while (cell[buffer] != 0)
	{
		cellfile >> command;
		if (command == "end")
		{
			if (state_pointer[curr_state] == -1)
			{
				std::cerr << "Unexpected \"end\" reached!" << std::endl;
				exit(-4);
			}
			cellfile.seekg(state_pointer[--curr_state]);
		}
		else
		{
			OP = str_to_enum(command);
			switch (OP)
			{
			case PRINT:
				print();
				break;
			case PRINTC:
				printc();
				break;
			case PRINTS:
				prints();
				break;
			case PRINTP:
				printp();
				break;
			case READ:
				read();
				break;
			case READC:
				readc();
				break;
			case READS:
				reads();
				break;
			case SET:
				set();
				break;
			case SETC:
				setc();
				break;
			case SETS:
				sets();
				break;
			case ADD:
				add();
				break;
			case SUB:
				sub();
				break;
			case MUL:
				mul();
				break;
			case DIV:
				div();
				break;
			case EXP:
				exp();
				break;
			case CPY:
				cpy();
				break;
			case MOV:
				mov();
				break;
			case SWP:
				swp();
				break;
			case LEN:
				len();
				break;
			case INC:
				inc();
				break;
			case DEC:
				dec();
				break;
			case I_GO:
				i_go();
				break;
			case W_GO:
				w_go();
				break;
			case SIZEOF:
				std::cout << sizeof(long long) * 8 << std::endl;
				break;
			case EXIT:
				command = "exit";
				break;
			default:
				std::cerr << "CLL: Unknown command:\t" << command << "\n";
				std::exit(-5);
				break;
			}
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
	state_pointer[++curr_state] = (int)cellfile.tellg();
	int buffer;
	cellfile >> command;
	buffer = get_num_val(command);

	while (cell[buffer] != 0)
	{
		cellfile >> command;

		OP = str_to_enum(command);

		callfunc(OP);

		// TODO: add opcode to pop off a loop/if statement from the stack.
		if (command == "end")
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

void Cll::callfunc(char &opcode)
{
	switch (opcode)
	{
	case PRINT:
		print();
		break;
	case PRINTC:
		printc();
		break;
	case PRINTS:
		prints();
		break;
	case PRINTP:
		printp();
		break;
	case READ:
		read();
		break;
	case READC:
		readc();
		break;
	case READS:
		reads();
		break;
	case SET:
		set();
		break;
	case SETC:
		setc();
		break;
	case SETS:
		sets();
		break;
	case ADD:
		add();
		break;
	case SUB:
		sub();
		break;
	case MUL:
		mul();
		break;
	case DIV:
		div();
		break;
	case EXP:
		exp();
		break;
	case CPY:
		cpy();
		break;
	case MOV:
		mov();
		break;
	case SWP:
		swp();
		break;
	case LEN:
		len();
		break;
	case INC:
		inc();
		break;
	case DEC:
		dec();
		break;
	case I_GO:
		i_go();
		break;
	case W_GO:
		w_go();
		break;
	case SIZEOF:
		std::cout << sizeof(long long) * 8 << std::endl;
		break;
	case EXIT:
		std::exit(1);
		break;
	default:
		std::cerr << "CLL: Unknown command:\t" << command << "\n";
		std::exit(-5);
		break;
	}
}

Cll::~Cll()
{
}

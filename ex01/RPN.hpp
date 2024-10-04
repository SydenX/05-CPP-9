#ifndef RPNC
# define RPNC

#include <iostream>
#include <iomanip>
#include <list>

class RPN {
	private:
		std::list<int> _list;
		RPN();
		int isIntOrParam(std::string const &s);

	public:
		RPN(int argc, char **argv);
		~RPN();

};

#endif
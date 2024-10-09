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
		void calculate(int i, std::string toRead);
		RPN &operator=(const RPN &ref);
		RPN(const RPN &ref);
	public:
		RPN(int argc, char **argv);
		~RPN();

};

#endif
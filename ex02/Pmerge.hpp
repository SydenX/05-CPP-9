#ifndef PMERGE
# define PMERGE

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <deque>

class Pmerge {
	private:
		std::vector<int> _v;
		std::deque<int> _d;
		Pmerge();
		int isInt(std::string const &s);
	public:
		Pmerge(int argc, char **argv);
		~Pmerge();
};

#endif
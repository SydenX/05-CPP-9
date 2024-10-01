#include <iostream>
#include "Pmerge.hpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Use: ./PmergeMe <sequence of int>" << std::endl;
		return 1;
	}
	Pmerge(argc, argv);
	return 0;
}
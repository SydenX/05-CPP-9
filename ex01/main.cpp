#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Use: ./RPN <sequence of number (0-9) and parameters (*/-+)>" << std::endl;
		return 1;
	}
	RPN(argc, argv);
	return 0;
}
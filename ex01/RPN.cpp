#include "RPN.hpp"

int RPN::isIntOrParam(std::string const &s){
	for (unsigned int i = 0; i < s.length(); i++){
		if (s[i] != ' '){
			if (std::isdigit(s[i]) == false && (s[i] != '+' && s[i] != '-' && s[i] != '/' && s[i] != '*'))
				return (std::cerr << "\'" << s[i] << "\' is not a valid integer or parameter." << std::endl, 0);
			if (++i < s.length())
				if (s[i] != ' ')
					return (std::cerr << "\'" << s << "\' is not correctly formatted." << std::endl, 0);
		}
	}
	return 1;
}

RPN::RPN(int argc, char **argv){
	std::string toRead = argv[1];
	for (int i = 1; i < argc; i++){
		if (!isIntOrParam(argv[i]))
			exit(1);
		if (i > 1)
			toRead += (std::string(" ") + argv[i]);
	}
	for(unsigned int i = 0; i < toRead.size(); i++){
		if (toRead[i] != ' '){
			if (std::isdigit(toRead[i])){
				this->_list.push_back(toRead[i] - '0');
			} else if (this->_list.size() >= 2) {
				int sign = toRead[i];
				int second = this->_list.back();
				this->_list.pop_back();
				int first = this->_list.back();
				this->_list.pop_back();
				int result;
				switch(sign){
					case 42:
						result = first * second;
						break;
					case 43:
						result = first + second;
						break;
					case 45:
						result = first - second;
						break;
					case 47:
						if (second == 0){
							std::cerr << "\'" << first << " / " << second << "\' division by 0 is not possible." << std::endl;
							this->_list.clear();
							exit(1);
						}
						result = first / second;
						break;
				}
				this->_list.push_back(result);
			} else {
				std::cerr << "\'" << toRead << "\' is not correctly formatted." << std::endl;
				this->_list.clear();
				exit(1);
			}
		}
	}
	if (this->_list.size() > 1){
		std::cerr << "\'" << toRead << "\' is not correctly formatted." << std::endl;
		this->_list.clear();
		exit(1);
	}
	std::cout << this->_list.front() << std::endl;
	this->_list.clear();
}

RPN::~RPN(){}
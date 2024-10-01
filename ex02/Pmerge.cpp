#include "Pmerge.hpp"

int Pmerge::isInt(std::string const &s){
	for (unsigned int i = 0; i < s.length(); i++){
		if (i == 0){
			if (s[i] == '-'){
				if (s.length() < 2)
					return 0;
			} else if (!std::isdigit(s[i]))
				return 0;
		} else if (std::isdigit(s[i]) == false) {
			return 0;
		}
	}
	return 1;
}

void swap(int *first, int *second){
	int *tmp = *first;
	*first = *second;
	*second = *tmp;
}

void split(std::vector v){
	for(unsigned int i = 0; i < v.size(); i++){
		int *first = &v[i];
		if (i + 1 < v.size()){
			int *second = &v[++i];
			if (*first > *second)
				swap(first, second);
			std::cout << *first << " " << *second << " ";
		} else std::cout << *first << " ";
	}
	std::cout << endl;
}

Pmerge::Pmerge(int argc, char **argv){
	for (int i = 1; i < argc; i++){
		if (!isInt(argv[i])){
			std::cerr << argv[i] << " is not a valid integer." << std::endl;
			exit(1);
		}
		try {
			int num = std::stoi(argv[i], 0, 10);
			this->_v.push_back(num);
			this->_d.push_back(num);
		} catch (std::exception &e){
			std::cout << e.what() << " for " << argv[i] << std::endl;
			this->_v.clear();
			this->_d.clear();
			exit(1);
		}
	}
	split(this->_v);
}

Pmerge::~Pmerge(){
}
#include "Pmerge.hpp"

int stringToInt(std::string & str) {
    int i;
    std::istringstream(str) >> i;
    return i;
}


int Pmerge::isInt(std::string const &s){
	for (unsigned int i = 0; i < s.length(); i++){
		if (std::isdigit(s[i]) == false)
			return 0;
	}
	return 1;
}

Pmerge::Pmerge(int argc, char **argv){
	std::vector<int> beforeList;
	for (int i = 1; i < argc; i++){
		if (!isInt(argv[i])){
			std::cerr << argv[i] << " is not a valid integer." << std::endl;
			this->_v.clear();
			this->_d.clear();
			beforeList.clear();
			exit(1);
		}
		try {
			std::string s = argv[i];
			int num = stringToInt(s);
			this->_v.push_back(num);
			this->_d.push_back(num);
			beforeList.push_back(num);
		} catch (std::exception &e){
			std::cout << e.what() << " for " << argv[i] << std::endl;
			this->_v.clear();
			this->_d.clear();
			beforeList.clear();
			exit(1);
		}
	}

	double vectorTime = clock();
	this->_v = mergeInsertSort(this->_v);
	vectorTime = static_cast<double>(clock() - vectorTime) / CLOCKS_PER_SEC * 1000000;

	double dequeTime = clock();
	this->_d = mergeInsertSort(this->_d);
	dequeTime = static_cast<double>(clock() - dequeTime) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Before: ";
	printList(beforeList);
	std::cout << "After: ";
	printList(this->_v);

	std::cout << "Time to process a range of " << this->_v.size() << " elements with std::vector : " << vectorTime << "us" << std::endl;
	std::cout << "Time to process a range of " << this->_d.size() << " elements with std::deque : " << dequeTime << "us" << std::endl;;
	beforeList.clear();
	this->_v.clear();
	this->_d.clear();
}

Pmerge::~Pmerge(){}
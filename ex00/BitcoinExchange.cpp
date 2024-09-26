#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::ifstream file;
    file.open("data.csv", std::ios::in);

	if (!file.is_open()){
		return;
	}
	std::string line;
	while(getline(file, line)){
		std::string date = line.substr(0, line.find(","));
		double value = stod(line.substr(line.find(","), line.size()));
		this->_db[date] = value;
	}
	file.close();

	std::map<std::string, double>::iterator it = this->_db.begin();
	while (it != this->_db.end()){
		std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
		++it;
	}
}

BitcoinExchange::~BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref){
	(void)ref;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &ref){
	(void)ref;
	return *this;
}

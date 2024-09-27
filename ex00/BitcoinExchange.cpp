#include "BitcoinExchange.hpp"

void BitcoinExchange::initDatabase(){
	std::ifstream file;
    file.open("data.csv", std::ios::in);

	if (!file.is_open()){
		std::cerr << "File \"" << "data.csv" << "\" cannot be read." << std::endl;
		exit(1);
	}
	std::string line;
	getline(file, line);
	while(getline(file, line)){
		std::string date = (line.substr(0, line.find(",")));
		double value = stod(line.substr(line.find(",") + 1, line.size()));
		this->_db[date] = value;
	}
	file.close();
}

int checkDate(std::string date){
	if (date.size() < 10)
		return 0;
	for (unsigned int i = 0; i < date.size(); i++){
		if (i < 4 || (i > 4 && i < 7) || (i > 7 && i < 10))
			if (date[i] < '0' || date[i] > '9')
				return 0;
		if ((i == 4 || i == 7) && date[i] != '-')
			return 0;
	}
	if (stod(date.substr(date.find("-")+1, date.find("-", 2))) > 12)
		return 0;
	if (stod(date.substr(date.find("-", date.find("-") + 1) + 1, date.size())) > 31)
		return 0;
	return 1;
}

void BitcoinExchange::compareValues(const std::string& name){
	std::ifstream file;
    file.open(name, std::ios::in);
	if (!file.is_open()){
		std::cerr << "File \"" << name << "\" cannot be read." << std::endl;
		exit(1);
	}
	std::string line;
	getline(file, line);
	while(getline(file, line)){
		if (line.find(" | ") == std::string::npos)
			std::cerr << "Error: bad input => " << line << std::endl;
		else {
			std::string date = line.substr(0, line.find(" | "));
			if (!checkDate(date))
				std::cerr << "Error: bad input => " << line << std::endl;
			else {
				try {
					double value = stod(line.substr(line.find(" | ") + 3, line.size()));
					if (value >= 0 && value <= 1000){
						std::map<std::string, double>::iterator it = this->_db.lower_bound(date);
						if (it != this->_db.begin() && it->first != date)
							it--;
						if (date < it->first)
							std::cerr << "Error: " << date << " do not have lower or equal date." << std::endl;
						else
							std::cout << date << " => " << value << " = " << value * it->second << std::endl;
					} else if(value < 0)
						std::cerr << "Error: not a positive number." << std::endl;
					else 
						std::cerr << "Error: too large number." << std::endl;
				} catch(std::exception &e){
					std::cerr << "Error: bad input => " << line << std::endl;
				}
			}
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(std::string infile){
	initDatabase();
	compareValues(infile);
}

BitcoinExchange::~BitcoinExchange(){
	this->_db.clear();
}
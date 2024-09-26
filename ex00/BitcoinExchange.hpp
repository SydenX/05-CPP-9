#ifndef EXCHANGE
# define EXCHANGE

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> _db;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &ref);
		BitcoinExchange &operator=(BitcoinExchange const &ref);
		~BitcoinExchange();


};

#endif
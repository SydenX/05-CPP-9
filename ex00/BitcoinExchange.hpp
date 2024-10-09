#ifndef EXCHANGE
# define EXCHANGE

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> _db;
		BitcoinExchange();
		void initDatabase();
		void compareValues(const std::string& name);
		BitcoinExchange &operator=(const BitcoinExchange &ref);
		BitcoinExchange(const BitcoinExchange &ref);
	public:
		BitcoinExchange(std::string infile);
		~BitcoinExchange();
};

#endif
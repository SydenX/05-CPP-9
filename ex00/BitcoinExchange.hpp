#ifndef EXCHANGE
# define EXCHANGE

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

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
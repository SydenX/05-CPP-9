#ifndef EXCHANGE
# define EXCHANGE

#include <iostream>
#include <vector>

class BitcoinExchange {
	private:
		std::vector db;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &ref);
		BitcoinExchange &operator=(BitcoinExchange const &ref);
		~BitcoinExchange();


}

#endif
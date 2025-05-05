/* **************************************************************************************************************** */
/*				                                    ⠤⣤⣤⣤⣄⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣤⠤⠤⠴⠶⠶⠶⠶	 */
/*				                                    ⢠⣤⣤⡄⣤⣤⣤⠄⣀⠉⣉⣙⠒⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠘⣉⢡⣤⡤⠐⣶⡆⢶⠀⣶⣶⡦	 */
/*	BitcoinExchange.cpp           	                ⣄⢻⣿⣧⠻⠇⠋⠀⠋⠀⢘⣿⢳⣦⣌⠳⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠞⣡⣴⣧⠻⣄⢸⣿⣿⡟⢁⡻⣸⣿⡿⠁   */
/*	                                                 ⠃⠙⢿⣧⣙⠶⣿⣿⡷⢘⣡⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣷⣝⡳⠶⠶⠾⣛⣵⡿⠋⠀    */
/*													     ⠉⠻⣿⣶⠂⠘⠛⠛⠛⢛⡛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠛⠀⠉⠒⠛⠀⠀⠀⠀    */
/*	By: mbentahi <Mohamadalaoui77@gmail.com>               ⣿⡇⠀⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	⠀ */
/*	                 								⠀⠀⠀⠀⠀ ⣿⡇⠀⠀⠀⠀⠀⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	 */
/*	Created: 4/30/2025, 10:19:24 AM        		⠀⠀⠀ ⠀⠀⠀  ⣿⡇⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  */
/*	Updated: 5/2/2025, 5:42:15 PM          		⠀⠀⠀ ⠀⠀⠀  ⢻⡁⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  */
/*													⠀⠀⠀⠀⠀⠘⡇                                                       */
/*													⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀	 */
/*                                                         ⠿                                                        */
/* **************************************************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename) : filename(filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: Could not open file" + filename);
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &c)
{
	*this = c;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &c)
{
	if (this == &c)
		return *this;
	this->data = c.data;
	this->inputData = c.inputData;
	this->filename = c.filename;
	this->input = c.input;
	this->dataBase = c.dataBase;

	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void trimmer(std::string *s)
{
	s->erase(0, s->find_first_not_of(" \t"));
	s->erase(s->find_last_not_of(" \t") + 1);
}

void BitcoinExchange::readDataBase()
{
	std::ifstream file(DATABASE_NAME);

	if (!file.is_open())
		throw std::runtime_error("Cannot Open File: " + std::string(DATABASE_NAME));

	std::string tmp;
	while (getline(file, tmp, '\n'))
	{
		dataBase += tmp + "\n";
	}
	file.close();
}

void BitcoinExchange::parseDataBase()
{
	std::stringstream stream(dataBase);
	std::string line;

	getline(stream, line);
	if (line.find("date,exchange_rate") == std::string::npos)
		throw std::runtime_error("Error: header incorrect 'date,exchange_rate'");

	while (getline(stream, line))
	{
		std::stringstream ss(line);
		if (getline(ss, date, ','))
		{
			trimmer(&date);
			if (getline(ss, value))
			{
				std::stringstream valueStream(value);
				float v;
				valueStream >> v;
				data[date] = v;
			}
			else
				data[date] = std::numeric_limits<float>::quiet_NaN();
		}
		else
		{
			date = line;
			trimmer(&date);
			data[date] = std::numeric_limits<float>::quiet_NaN();
		}
	}
}

bool isValidDate(const std::string &date)
{
	std::stringstream ss(date);
	int year, month, day;
	char dash1, dash2;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	if (!(ss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	if (dash1 != '-' || dash2 != '-')
		return false;
	if ((day < 1 || day > 31) || (month < 1 || month > 12))
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		bool isleap = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
		if (day > 29 || (day == 29 && !isleap))
			return false;
	}
	return true;
}

bool isValidValue(float value)
{
	if (value < 0 || value > 1000)
		return false;
	return true;
}

void find_closest_date(std::map<std::string, float> &data, const std::string &date, float value)
{
	std::map<std::string, float>::iterator it = data.lower_bound(date);

	if (it == data.begin() && date < it->first)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	if (it == data.end() || it->first != date)
		--it;
	std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
}

void BitcoinExchange::display()
{
	std::ifstream file(filename.c_str());

	std::string line;
	getline(file, line);
	if (line.find("date | value") == std::string::npos)
		throw std::runtime_error("Error: header incorrect 'date | value'");
	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		char pipe;
		float value;
		ss >> date >> pipe >> value;
		if (!isValidDate(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (!isValidValue(value))
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			if (data.find(date) != data.end())
				std::cout << date << " => " << value * data[date] << std::endl;
			else
				find_closest_date(data, date, value);
		}
	}
}
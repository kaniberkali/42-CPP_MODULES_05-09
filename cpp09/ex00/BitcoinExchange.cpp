/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:10:50 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/05 18:08:55 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>


BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(std::string inputsPath, std::string ratesPath)
{
	readBitcoinRates(ratesPath);
	readInputs(inputsPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		this->_bitcoinRates = copy._bitcoinRates;
		this->_inputs = copy._inputs;
	}
	return *this;
}

bool BitcoinExchange::pushBitcoinRate(std::string date, double value)
{
	Data data;
	data.date = date;
	data.value = value;
	_bitcoinRates.push_back(data);
	return true;
}

bool BitcoinExchange::pushInput(std::string date, double value)
{
	Data data;
	data.date = date;
	data.value = value;
	_inputs.push_back(data);
	return true;
}

bool BitcoinExchange::pushBadInput(std::string input)
{
	Data data;
	data.error = input.length() == 0 ? "Empty line" : input;
	_inputs.push_back(data);
	return true;
}

unsigned int BitcoinExchange::getTimeStamp(std::string date)
{
	unsigned int t = 0;

	t += std::atoi(date.substr(0, 4).c_str()) * 31536000;
	t += std::atoi(date.substr(5, 2).c_str()) * 2592000;
	t += std::atoi(date.substr(8, 2).c_str()) * 86400;

	return t;
}

Data BitcoinExchange::getBitcoinRate(std::string date)
{
	Data data;
	unsigned int min = getTimeStamp(date) - getTimeStamp(_bitcoinRates[0].date);
	for (std::vector<Data>::iterator it = _bitcoinRates.begin(); it != _bitcoinRates.end(); ++it)
	{
		if (getTimeStamp(date) - getTimeStamp(it->date) < min && getTimeStamp(date) - getTimeStamp(it->date) >= 0)
		{
			min = getTimeStamp(date) - getTimeStamp(it->date);
			data = *it;
			if (min == 0)
				break;
		}
	}
	return data;
}

Data BitcoinExchange::getInput(std::string date, double multiplier)
{
	Data data;
	for (std::vector<Data>::iterator it = _inputs.begin(); it != _inputs.end(); ++it)
	{
		if (it->date == date && multiplier == it->value)
		{
			data = *it;
			break;
		}
	}
	return data;
}

bool BitcoinExchange::isDouble(const std::string& str)
{
    std::istringstream iss(str);
    double temp;
    iss >> temp;
    return iss.eof() && !iss.fail();
}

bool BitcoinExchange::isValidDate(const std::string& str)
{
    if (str.size() != 10)
        return false;
    for (int i = 0; i < 10; ++i)
	{
        if (i == 4 || i == 7)
		{
            if (str[i] != '-')
                return false;
        }
		else
		{
            if (!isdigit(str[i]))
                return false;
        }
    }

    return true;
}

std::string BitcoinExchange::replaceAll(std::string str, std::string from, std::string to)
{
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length();
	}
	return str;
}

bool BitcoinExchange::isBadInput(std::string line)
{
	if (line.find("|"))
    	return !isValidDate(line.substr(0, line.find("|"))) || !isDouble(line.substr(line.find("|") + 1));
	return true;
}

std::vector<Data> BitcoinExchange::readBitcoinRates(std::string path)
{
	std::ifstream file(path);
	if (!file.is_open())
		throw FileErrorException();
	std::string line;
	if (!std::getline(file, line))
	{
		file.close();
		throw FileEmptyException();
	}
	while (std::getline(file, line))
	{
		line = replaceAll(line, " ", "");
		std::string date = line.substr(0, line.find(","));
		double value = std::atof(line.substr(line.find(",") + 1).c_str());
		pushBitcoinRate(date, value);
	}
	file.close();
	return _bitcoinRates;
}

std::vector<Data> BitcoinExchange::readInputs(std::string path)
{
	std::ifstream file(path);
	if (!file.is_open())
		throw FileErrorException();
	std::string line;
	if (!std::getline(file, line))
	{
		file.close();
		throw FileEmptyException();
	}
	while (std::getline(file, line))
	{
		if (isBadInput(replaceAll(line, " ", "")))
		{
			pushBadInput(line);
			continue;
		}
		line = replaceAll(line, " ", "");
		std::string date = line.substr(0, line.find("|"));
		double value = std::atof(line.substr(line.find("|") + 1).c_str());
		pushInput(date, value);
	}
	file.close();
	return _inputs;
}

bool BitcoinExchange::print(Data bitcoinRate, Data input)
{
	if (input.error.length() > 0)
	{
		std::cout << "Error: bad input => " << input.error << std::endl;
		return false;
	}
	else if (input.value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	else if (!(input.value >= 0 && input.value <= 1000))
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	else
		std::cout << input.date << " => " << input.value << " = " << bitcoinRate.value * input.value << std::endl;
	return true;
}

bool BitcoinExchange::print()
{
	for (std::vector<Data>::iterator it = _inputs.begin(); it != _inputs.end(); ++it)
	{
		Data bitcoinRate = getBitcoinRate(it->date);
		print(bitcoinRate, *it);
	}
	return true;
}

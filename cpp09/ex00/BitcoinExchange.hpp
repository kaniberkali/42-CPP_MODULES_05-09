/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:10:33 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/05 16:45:08 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>

struct Data 
{
    std::string date;
    double value;
	std::string error;
	Data() : date("Undefined"), value(0), error("") { };
};

class BitcoinExchange
{
	private:
		std::vector<Data> _bitcoinRates;
		std::vector<Data> _inputs;
	
		bool pushBitcoinRate(std::string date, double value);
		bool pushInput(std::string date, double value);
		bool pushBadInput(std::string input);

		bool isDouble(const std::string& str);
		bool isValidDate(const std::string& str);
		bool isBadInput(std::string line);

		std::string replaceAll(std::string str, std::string from, std::string to);
		unsigned int getTimeStamp(std::string date);
	public:
		Data getBitcoinRate(std::string date);
		Data getInput(std::string date, double multiplier);
		
		std::vector<Data> readBitcoinRates(std::string path = "data.csv");
		std::vector<Data> readInputs(std::string path = "input.txt");

		bool print(Data bitcoinRate, Data input);
		bool print();

		BitcoinExchange();
		BitcoinExchange(std::string inputsPath, std::string ratesPath = "data.csv");
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		class FileErrorException : public std::exception
		{
			virtual const char* what() const throw() { return "Error: could not open file."; };
		};

		class FileEmptyException : public std::exception
		{
			virtual const char* what() const throw() { return "Error: file is empty."; };
		};
};

#endif
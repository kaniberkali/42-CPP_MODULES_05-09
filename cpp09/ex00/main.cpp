/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:17:12 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/05 16:35:03 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange exchange;

		try
		{
			exchange.readBitcoinRates();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			exchange.readInputs(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		exchange.print();
	}
	else
		std::cout << "Error: could not open file." << std::endl;
	return 0;
}
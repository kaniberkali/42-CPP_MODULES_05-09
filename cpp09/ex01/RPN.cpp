/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:56:30 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/06 15:48:03 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::~RPN() { }

RPN::RPN(std::stack<double> number)
{
	this->numbers = number;
}

RPN::RPN(const RPN &var)
{
	*this = var;
}

RPN &RPN::operator=(const RPN &var)
{
	this->numbers = var.numbers;
	return (*this);
}

void RPN::calculate(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];

		if (c == ' ')
			continue;
		else if (isdigit(c))
		{
			int number = c - '0';
			numbers.push(number);
		}
		else if ((c == '+' || c == '-' || c == '*' || c == '/') && numbers.size() >= 2)
		{
			double b = numbers.top();
			numbers.pop();
			double a = numbers.top();
			numbers.pop();
			if (c == '+')
				numbers.push(a + b);
			else if (c == '-')
				numbers.push(a - b);
			else if (c == '*')
				numbers.push(a * b);
			else if (c == '/')
				numbers.push(a / b);
		}
		else
		{
			std::cout << "Error" << std::endl;
			return;
		}
	}

	if (numbers.size() == 1)
	{
		double result = numbers.top();
		numbers.pop();
		std::cout << result << std::endl;
	}
	else
		std::cout << "Error" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:53:55 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/05 16:56:22 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<double> numbers;
	public:
		RPN();
		RPN(std::stack<double> number);
		RPN(const RPN &var);
		~RPN();
		RPN &operator=(const RPN &var);
		void calculate(std::string input);
};

#endif
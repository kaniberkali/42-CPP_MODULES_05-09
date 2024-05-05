/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:57:16 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/05 17:40:50 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN rpn;

		rpn.calculate(av[1]);
	}
	else
		std::cout << "Error" << std::endl;
	return 0;
}
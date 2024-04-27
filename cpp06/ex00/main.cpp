/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:49:14 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/27 17:34:33 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char* av[])
{
    if (ac != 2)
    {
        std::cout << "Error: This program accepts only 1 argument!" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
	ScalarConverter::print();
    return 0;
}
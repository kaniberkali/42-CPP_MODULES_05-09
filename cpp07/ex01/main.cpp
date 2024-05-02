/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:01:59 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/02 16:57:10 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T const &param)
{
	std::cout << param << std::endl;
}

int main( void )
{
	int numbers[] = {0, 1, 2, 3, 4};
	iter(numbers, 5, print);

	std::string infos[] = {"https://kaniberk.com", "kaniberkali", "Ali Kanıberk"};
	iter(infos, 3, print);
	return 0;
}
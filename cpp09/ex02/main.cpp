/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:25:31 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/05 18:09:11 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "Error: need number." << std::endl;
	else
	{
		PmergeMe merge;
		merge.mergeMe(ac, av);
	}
	return 0;
}
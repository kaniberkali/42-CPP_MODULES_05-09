/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:47:40 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/04 11:33:23 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>

int main()
{
    std::vector<int> vec(5);
    std::deque<int> deque;

    for (size_t i = 1; i <= 5; ++i)
	{
        vec.push_back(i);
        deque.push_back(i);
        deque.push_front(i);
    }

    try
	{
        std::cout << ::easyfind(vec, 5) << std::endl;
        std::cout << ::easyfind(deque, 3) << std::endl;
        std::cout << ::easyfind(deque, 10) << std::endl;
    }
	catch (std::exception & exception)
	{
        std::cout << exception.what() << std::endl;
    }
    return 0;
}
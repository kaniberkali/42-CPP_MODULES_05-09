/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:31:08 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 13:13:49 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "--------------- Example 1 ---------------" << std::endl;
	try
	{
		Bureaucrat kaniberk("https://kaniberk.com", 0);
		std::cout << "This output will not appear" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 2 ---------------" << std::endl;
	try
	{
		Bureaucrat kaniberk("https://kaniberk.com", 151);
		std::cout << "This output will not appear" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 3 ---------------" << std::endl;

	try 
	{
		Bureaucrat kaniberk("https://kaniberk.com", 3);
		std::cout << kaniberk << std::endl;
		kaniberk.incrementGrade();
		std::cout << kaniberk << std::endl;
		kaniberk.incrementGrade();
		std::cout << kaniberk << std::endl;
		kaniberk.incrementGrade();
		std::cout << "This output will not appear" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 4 ---------------" << std::endl;
	try 
	{
		Bureaucrat kaniberk("https://kaniberk.com", 148);
		std::cout << kaniberk << std::endl;
		kaniberk.decrementGrade();
		std::cout << kaniberk << std::endl;
		kaniberk.decrementGrade();
		std::cout << kaniberk << std::endl;
		kaniberk.decrementGrade();
		std::cout << "This output will not appear" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 5 ---------------" << std::endl;
	try 
	{
		Bureaucrat kaniberk("kaniberk", 80);
		std::cout << kaniberk << std::endl;
		Bureaucrat kaniberk2("kaniberk2", 443);
		std::cout << kaniberk2 << std::endl;
		kaniberk = kaniberk2;
		std::cout << "kaniberk = kaniberk2"<< std::endl;
		std::cout << kaniberk << std::endl;
		std::cout << kaniberk2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 6 ---------------" << std::endl;
	try 
	{
		Bureaucrat kaniberk("kaniberk", 20);
		std::cout << kaniberk << std::endl;
		Bureaucrat kaniberk2("kaniberk2", 38);
		std::cout << kaniberk2 << std::endl;
		kaniberk = kaniberk2;
		std::cout << "kaniberk = kaniberk2"<< std::endl;
		std::cout << kaniberk << std::endl;
		std::cout << kaniberk2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

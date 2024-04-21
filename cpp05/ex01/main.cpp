/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:32:17 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 13:54:54 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "--------------- Example 1 ---------------" << std::endl;
	try
	{
		Form form("EXAMPLE FORM", 50, 100);
		std::cout << form << std::endl;
		Bureaucrat kaniberk("https://kaniberk.com", 0);
		std::cout << kaniberk << std::endl;
		std::cout << "This output will not appear" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------- Example 2 ---------------" << std::endl;
	try
	{
		Form form("EXAMPLE FORM", 50, 100);
		std::cout << form << std::endl;
		Bureaucrat kaniberk("https://kaniberk.com", 151);
		std::cout << kaniberk << std::endl;
		std::cout << "This output will not appear" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------- Example 3 ---------------" << std::endl;
	try
	{
		Form form("EXAMPLE FORM", 5, 0);
		std::cout << "This output will not appear" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------- Example 4 ---------------" << std::endl;
	try
	{
		Form form("EXAMPLE FORM", 5, 151);
		std::cout << "This output will not appear" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--------------- Example 5 ---------------" << std::endl;
	try
	{
		Form form("EXAMPLE FORM", 20, 45);
		Bureaucrat kaniberk("https://kaniberk.com", 35);
		std::cout << form << std::endl;
		std::cout << kaniberk << std::endl;
		kaniberk.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 6 ---------------" << std::endl;
	try
	{
		Form form("EXAMPLE FORM", 50, 100);
		std::cout << form << std::endl;
		Bureaucrat kaniberk("https://kaniberk.com", 49);
		std::cout << kaniberk << std::endl;
		kaniberk.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:09 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 17:29:49 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("Elon");
	PresidentialPardonForm pardon("42");

	std::cout << "--------------- Example 1 ---------------" << std::endl;
	try
	{
		Bureaucrat kaniberk("https://kaniberk.com", 150);
		kaniberk.executeForm(shrubbery);
		kaniberk.executeForm(robotomy);
		pardon.beSigned(kaniberk);
		kaniberk.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 2 ---------------" << std::endl;
	try
	{
		Bureaucrat kaniberk("https://kaniberk.com", 1);
		kaniberk.executeForm(shrubbery);
		kaniberk.executeForm(robotomy);
		pardon.beSigned(kaniberk);
		kaniberk.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 3 ---------------" << std::endl;
	try
	{
		Bureaucrat kaniberk("https://kaniberk.com", 50);
		shrubbery.beSigned(kaniberk);
		kaniberk.executeForm(shrubbery);
		robotomy.beSigned(kaniberk);
		kaniberk.executeForm(robotomy);
		pardon.beSigned(kaniberk);
		kaniberk.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------- Example 4 ---------------" << std::endl;
	try
	{
		Bureaucrat kaniberk("https://kaniberk.com", 1);
		shrubbery.beSigned(kaniberk);
		kaniberk.executeForm(shrubbery);
		robotomy.beSigned(kaniberk);
		kaniberk.executeForm(robotomy);
		pardon.beSigned(kaniberk);
		kaniberk.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}

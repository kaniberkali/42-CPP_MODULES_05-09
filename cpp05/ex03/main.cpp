/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:34:23 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 17:19:49 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Intern  someRandomIntern;
	AForm * forms[4] = {
		someRandomIntern.makeForm("ShrubberyCreationForm", "Ali"),
		someRandomIntern.makeForm("RobotomyRequestForm", "Home"),
		someRandomIntern.makeForm("PresidentialPardonForm", "Elon Musk"),
		someRandomIntern.makeForm("https://kaniberk.com", "Kanıberk")
	};
	
	try
	{
		int i = 0;
		Bureaucrat kaniberk("Ali Kanıberk", 3);
		std::cout  << kaniberk <<std::endl;
		while(forms[i])
		{
			std::cout << *forms[i]  << std::endl;
			forms[i]->beSigned(kaniberk);
			kaniberk.executeForm(*forms[i]);
			delete forms[i];
			i++;
		}
	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}
    return 0;
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:34:15 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 17:16:03 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

Intern::Intern(void) { }

Intern::~Intern(void) { }

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern &Intern::operator=(Intern const &intern)
{
	(void)intern;
	return (*this);
}

static AForm *createPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *createRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm *(*forms[])(const std::string target)  = {&createPresidentialPardonForm, &createRobotomyRequestForm, &createShrubberyCreationForm};
	std::string formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	for (int i = 0; i < 3; i++)
		if (name == formNames[i])
		{
			std::cout  << "Intern creates " << formNames[i] << std::endl;
			return forms[i](target);
		}
	std::cout << "Intern can not create a form called " << name << std::endl;
	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:46 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 17:38:02 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("Undefined") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm::AForm(src), _target(src.getTarget()) { }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm const	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrubberyCreationForm)
{
	AForm::operator=(shrubberyCreationForm);
	this->setTarget(shrubberyCreationForm.getTarget());
	return(*this);
}

void ShrubberyCreationForm::setTarget(const std::string & target)
{
	this->_target = target;
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	std::ofstream	outfile;
	outfile.open((this->getTarget() +  "_shrubbery").c_str());
	if (outfile.fail())
	{
		std::cout << "Could not open output file" << std::endl;
		return ;
	}
	outfile << TREE;
	outfile.close();
	std::cout << bureaucrat.getName() << " successfully created a shrubbery" << std::endl;
}

std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
	str << "Form's name: " << form.getName() << std::endl;
	str << "Signed: " << form.getSigned() << std::endl;
	str << "Sign Grade: " << form.getSignGrade() << std::endl;
	str << "Execute Grade: " << form.getExecuteGrade() << std::endl;
	str << "Form's target: " << form.getTarget() << std::endl;
	return (str);
}
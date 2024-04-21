/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:31:23 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 15:18:53 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Undefined"), _grade(150) { }

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat): _name(bureaucrat.getName()), _grade(bureaucrat.getGrade()) { }

Bureaucrat::~Bureaucrat(void) { }

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	if (getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	this->setGrade(bureaucrat.getGrade());
	return (*this);
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
		
}

const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int &Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->setGrade(this->getGrade() + 1);
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << "Bureaucrat name's "<< bureaucrat.getName() << ", grade is " << bureaucrat.getGrade()<< ".");
}
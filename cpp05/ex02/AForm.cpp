/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:32:42 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 15:18:53 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("Undefined"), _signed(false), _signGrade(50), _executeGrade(100) { }

AForm::AForm(const AForm &form): _name(form.getName()), _signed(form.getSigned()), _signGrade(form.getSignGrade()), _executeGrade(form.getExecuteGrade()) { }

AForm::~AForm(void) { }

AForm::AForm(const std::string &name, const int &signGrade, const int &executeGrade):_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (getSignGrade() < 1 || getExecuteGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (getSignGrade() > 150 || getExecuteGrade() > 150)
		throw AForm::GradeTooLowException();
}

const AForm &AForm::operator=(const AForm &form)
{
	this->setSigned(form.getSigned());
	return (*this);
}

void AForm::setSigned(bool isSigned)
{
	this->_signed = isSigned;
	
}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

bool const &AForm::getSigned(void) const
{
	return (this->_signed);
}
const int &AForm::getSignGrade(void) const{
	return (this->_signGrade);
}

const int &AForm::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade())
		throw(AForm::GradeTooLowException());
	else
		setSigned(true);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw(AForm::NotSignedException());
	else if (executor.getGrade() > getExecuteGrade())
		throw(AForm::GradeTooLowException());
	else
		beExecuted(executor);
}

std::ostream &operator<<(std::ostream &str, const AForm &form)
{
	str << "Form " << form.getName() << " could is signed";
	str << " with require grade " << form.getSignGrade() << " to sign and grade " << form.getExecuteGrade() << " to execute";
	return (str);
}

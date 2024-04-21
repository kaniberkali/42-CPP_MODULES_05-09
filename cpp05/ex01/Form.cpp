/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:31:55 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 15:14:57 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Undefined"), _signed(false), _signGrade(50), _executeGrade(100) { }

Form::Form(const Form &form): _name(form.getName()), _signed(form.getSigned()), _signGrade(form.getSignGrade()), _executeGrade(form.getExecuteGrade()) { }

Form::~Form(void){ }

Form::Form(const std::string &name, const int &signGrade, const int &executeGrade):_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (getSignGrade() < 1 || getExecuteGrade() < 1)
		throw Form::GradeTooHighException();
	else if (getSignGrade() > 150 || getExecuteGrade() > 150)
		throw Form::GradeTooLowException();
}

const Form 	&Form::operator=(const Form &form)
{
	this->setSigned(form.getSigned());
	return (*this);
}

void Form::setSigned(bool isSigned)
{
	this->_signed = isSigned;
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

bool const &Form::getSigned(void) const
{
	return (this->_signed);
}

const int &Form::getSignGrade(void) const
{
	return (this->_signGrade);
}
const int &Form::getExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade())
		throw(Form::GradeTooLowException());
	else
		setSigned(true);
}

std::ostream &operator<<(std::ostream &str, const Form &form)
{
	str << "Form " << form.getName() << " could is signed";
	str << " with require grade " << form.getSignGrade() << " to sign and grade " << form.getExecuteGrade() << " to execute";
	return (str);
}

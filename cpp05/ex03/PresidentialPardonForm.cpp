/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:27 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 15:38:14 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("PresidentialPardonForm", 25, 5), _target("Undefined") { }
PresidentialPardonForm::PresidentialPardonForm(const std::string & target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) { }
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm::AForm(src), _target(src.getTarget()) { }
PresidentialPardonForm::~PresidentialPardonForm(void){ }

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
	AForm::operator=(presidentialPardonForm);
	this->setTarget(presidentialPardonForm.getTarget());
	return (*this);
}

void PresidentialPardonForm::setTarget(const std::string &target)
{
	this->_target = target;
	
}

const std::string &PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	(void)bureaucrat;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	
}

std::ostream &operator<<(std::ostream &str, PresidentialPardonForm const &presidentialPardonForm)
{
	str << "Form's name: " << presidentialPardonForm.getName() << std::endl;
	str << "Signed: " << presidentialPardonForm.getSigned() << std::endl;
	str << "Sign Grade: " << presidentialPardonForm.getSignGrade() << std::endl;
	str << "Execute Grade: " << presidentialPardonForm.getExecuteGrade() << std::endl;
	str << "Form's target: " << presidentialPardonForm.getTarget() << std::endl;
	return (str);	
}
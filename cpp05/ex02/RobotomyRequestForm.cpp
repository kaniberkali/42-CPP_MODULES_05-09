/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:36 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 17:32:22 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("RobotomyRequestForm", 72, 45), _target("Undefined") { }
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) { }
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm): AForm::AForm(robotomyRequestForm), _target(robotomyRequestForm.getTarget()) { }
RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
	AForm::operator=(robotomyRequestForm);
	this->setTarget(robotomyRequestForm.getTarget());	
	return (*this);
}

void RobotomyRequestForm::setTarget(const std::string &target)
{
	this->_target = target;
}

const std::string &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::beExecuted(Bureaucrat const &executor) const
{
	srand((unsigned) time(NULL));
	(void)executor;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully 50\% of the time. " << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &robotomyRequestForm)
{
	str << "Form's name: " << robotomyRequestForm.getName() << std::endl;
	str << "Signed: " << robotomyRequestForm.getSigned() << std::endl;
	str << "Sign Grade: " << robotomyRequestForm.getSignGrade() << std::endl;
	str << "Execute Grade: " << robotomyRequestForm.getExecuteGrade() << std::endl;
	str << "Form's target: " << robotomyRequestForm.getTarget() << std::endl;
	return (str);
}

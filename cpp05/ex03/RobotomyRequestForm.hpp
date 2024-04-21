/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:42 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 17:37:43 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);
		~RobotomyRequestForm(void);
		RobotomyRequestForm const &operator=(RobotomyRequestForm const &robotomyRequestForm);
		void setTarget(const std::string &target);
		const std::string &getTarget(void) const;
		void beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form);
#endif
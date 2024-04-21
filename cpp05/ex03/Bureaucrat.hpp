/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:02 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 15:37:51 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class AForm;
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string & name, int grade);
		Bureaucrat(Bureaucrat const &bureaucrat);
		~Bureaucrat(void);
		Bureaucrat const &operator=(Bureaucrat const &bureaucrat);
		void setGrade(int grade);
		const std::string &getName(void) const;
		const int &getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm &form);
		void executeForm(const AForm &form);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw() { return ("Grade is too high (Bureaucrat)"); }
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw() { return ("Grade is too low (Bureaucrat)"); }
		};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);
#endif
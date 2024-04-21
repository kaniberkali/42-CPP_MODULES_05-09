/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:32:47 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 15:15:26 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>

class Bureaucrat;
class AForm{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		AForm(void);
		AForm(const std::string &name, const int &signGrade, const int &executeGrade);
		AForm(const AForm &copy);
		virtual ~AForm(void);
		const AForm	&operator=(const AForm &copy);
		void setSigned(bool isSigned);
		const std::string &getName(void) const;
		bool const &getSigned(void) const;
		const int &getSignGrade(void) const;
		const int &getExecuteGrade(void) const;
		void execute(Bureaucrat const &executor) const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void beExecuted(Bureaucrat const &executor) const = 0;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw() { return ("Grade is too high. (AForm)"); }
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw() { return ("Grade is too low. (AForm)"); }
		};
		class NotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw() { return ("Form is not signed. (AForm)"); }
		};
};

std::ostream &operator<<(std::ostream &str, const AForm &form);
#endif
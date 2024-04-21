/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:32:12 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 14:58:27 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
	public:
		Form(void);
		Form(const std::string &name, const int &signGrade, const int &executeGrade);
		Form(const Form &form);
		~Form(void);
		const Form	&operator=(const Form &form);
		void setSigned(bool isSigned);
		const std::string &getName(void) const;
		bool const &getSigned(void) const;
		const int &getSignGrade(void) const;
		const int &getExecuteGrade(void) const;
		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){ return ("Grade is too high (Form)"); }
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw(){ return ("Grade is too low (Form)"); }
		};
};

std::ostream &operator<<(std::ostream &str, const Form &form);
#endif
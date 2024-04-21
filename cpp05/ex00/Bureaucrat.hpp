/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:31:01 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 17:36:20 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(Bureaucrat const &bureaucrat);
		~Bureaucrat(void);
		Bureaucrat const &operator=(Bureaucrat const &bureaucrat);
		const std::string &getName(void) const;
		void setGrade(int grade);
		const int &getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw() { return ("Grade is too high"); }
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw() { return ("Grade is too low"); }
		};
};
std::ostream &operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif
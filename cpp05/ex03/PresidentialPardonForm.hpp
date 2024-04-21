/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:33:31 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 15:38:23 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class Bureaucrat;
class PresidentialPardonForm: public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string & target);
		PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
		~PresidentialPardonForm(void);
		PresidentialPardonForm & operator=(PresidentialPardonForm const &presidentialPardonForm);
		void setTarget(const std::string &target);
		const std::string &getTarget(void) const;
		void beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream & operator<<(std::ostream &str, PresidentialPardonForm const &presidentialPardonForm);
#endif
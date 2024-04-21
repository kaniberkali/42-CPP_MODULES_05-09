/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:34:19 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/21 17:37:35 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{	
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);
		Intern &operator=(Intern const &intern);
		AForm *makeForm(const std::string &name, const std::string &target);
};
#endif
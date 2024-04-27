/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:37:50 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/27 20:28:56 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

struct Data
{
	std::string id;
	std::string name;
	std::string surname;
	std::string username;
	std::string website;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &serializer);
		~Serializer();
		Serializer & operator=(Serializer const &serializer);
	public:
		static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
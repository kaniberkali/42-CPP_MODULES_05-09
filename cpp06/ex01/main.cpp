/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:38:23 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/27 18:17:51 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *user = new Data;

	user->id = "1";
	user->name = "Ali";
	user->surname = "Kanıberk";
	user->username = "akaniber";
	user->website = "https://kaniberk.com";

	std::cout << "User data: " << user << std::endl;
	uintptr_t serialized = Serializer::serialize(user);
	std::cout << "Serialized data: " << serialized << std::endl;
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized data: " << deserialized << std::endl;
	delete user;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:55:30 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/28 13:55:38 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int     main( void )
{
	srand(time(NULL));
    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();

    std::cout << "a* = ";
	identify(a);
    std::cout << "a& = ";
	identify(*a);

	std::cout << std::endl;
    std::cout << "b* = ";
	identify(b);
    std::cout << "b& = ";
	identify(*b);

	std::cout << std::endl;
    std::cout << "c* = ";
	identify(c);
    std::cout << "c& = ";
	identify(*c);
	
	std::cout << std::endl;
    std::cout << "d* = ";
	identify(d);
    std::cout << "d& = ";
	identify(*d);


    delete a;
    delete b;
    delete c;
    delete d;

    return (0);
}
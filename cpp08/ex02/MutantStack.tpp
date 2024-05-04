/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 10:51:46 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/04 11:06:29 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() { }

template<typename T>
MutantStack<T>::~MutantStack() { }

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& mutantstack)
{
	*this = mutantstack;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& other)
{
	this->std::stack<T> = std::stack<T>(other);
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin()
{
	return this->c.cbegin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend()
{
	return this->c.cend();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin()
{
	return this->c.crbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend()
{
	return this->c.crend();
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:46:07 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/02 16:51:28 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array(): _array(NULL), _size(0) { }

template<typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) { }

template<typename T>
Array<T>::~Array()
{
	if (_array) delete[] _array;
}

template<typename T>
Array<T>::Array(const Array& copy): _array(new T[copy._size]), _size(copy.size())
{
    for (size_t i = 0; i < copy._size; ++i)
        _array[i] = copy._array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array& copy)
{
    if (this != &copy)
    {
        if (_array)
            delete[] _array;
        _array = new T[copy._size];
        _size = copy.size;
        for (size_t i = 0; i < _size; ++i)
            _array[i] = copy._array[i];
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](const int index)
{
    if (index < 0 || index >= static_cast<int>(_size))
        throw std::runtime_error("Array index out of bounds");
    return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
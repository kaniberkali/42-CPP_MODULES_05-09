/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:25:14 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/05 18:08:37 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <cstring>

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(std::list<int> list, std::deque<int> deque) : _list(list), _deque(deque) { }

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	_list = other._list;
	_deque = other._deque;
	return *this;
}

bool PmergeMe::isInt(char *str)
{
	for (size_t i = 0; i < strlen(str); ++i) 
		if (!isdigit(str[i]))
			return false;
	return true;
}

void PmergeMe::printList(std::string title)
{
	std::cout << title;
	int i = 0;
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
	{
		if (_list.size() >= 7 && i == 4)
		{
			std::cout << "[...]";;
			break ;
		}
		std::cout << *it << " ";
		++i;
	}
	std::cout << std::endl;
}

void PmergeMe::pushNumbers(int ac, char** av)
{
	int n;
	for (int i = 1; i < ac; ++i)
	{
		n = atoi(av[i]);
		if (!isInt(av[i]) || n < 0)
			throw "Error: Invalid input.";
		_list.push_back(n);
		_deque.push_back(n);
	}
	printList("Before:  ");
	_size = ac - 1;
}

template<typename T>
void PmergeMe::insertionSort(T& A, int p, int r)
{
	typename T::iterator it = A.begin();
	typename T::iterator ite = A.begin();
	std::advance(it, p);
	std::advance(ite, r + 1);
    while (it != ite && it != A.end())
	{
        typename T::iterator current = it;
        int temp = *it;
        typename T::iterator prev = it;
		typename T::iterator next = prev;
		++next;
        while (prev != A.begin() && *(--prev) > temp)
		{
            *current = *prev;
            current = prev;
        }
        *current = temp;
		current = next;
		++it;
    }
}

template<typename T>
void merge(T& A, int p, int q, int r)
{
	T left;
    T right;

    typename T::iterator it = A.begin();
    std::advance(it, p);
    for (int i = p; i <= q; ++i)
	{
        left.push_back(*it);
        ++it;
    }

    it = A.begin();
    std::advance(it, q + 1);
    for (int i = q + 1; i <= r; ++i)
	{
        right.push_back(*it);
        ++it;
    }

    typename T::iterator leftIt = left.begin();
    typename T::iterator rightIt = right.begin();
    typename T::iterator mergedIt = A.begin();
    std::advance(mergedIt, p);

    while (leftIt != left.end() && rightIt != right.end())
	{
        if (*leftIt <= *rightIt)
		{
            *mergedIt = *leftIt;
            ++leftIt;
        }
		else
		{
            *mergedIt = *rightIt;
            ++rightIt;
        }
        ++mergedIt;
    }

    for (;leftIt != left.end(); ++leftIt, ++mergedIt)
        *mergedIt = *leftIt;

    for (;rightIt != right.end(); ++rightIt, ++mergedIt)
        *mergedIt = *rightIt;
}

template<typename T>
void PmergeMe::mergeInsert(T& A, int p, int r)
{
	if (r - p > K)
	{
		int q = (p + r) / 2;
		mergeInsert(A, p, q);
		mergeInsert(A, q + 1, r);
		merge(A, p, q, r);
	}
	else
		insertionSort(A, p, r);
}

void PmergeMe::printTime(timeval tv, std::string type)
{
	struct timeval tv2;

	gettimeofday(&tv2, 0);
	double timePased = ((double)tv2.tv_usec - (double)tv.tv_usec) / 1000000;
	std::cout << "Time to process a range of " << _size <<  " elements with "
	<< type << " " << std::fixed << timePased << " us." << std::endl;
}

void PmergeMe::mergeMe(int ac, char **av)
{
	pushNumbers(ac, av);
	struct timeval tv;

	gettimeofday(&tv, 0);
    mergeInsert(_list, 0, _list.size() - 1);
	printList("After:   ");
	printTime(tv, "std::list");
	gettimeofday(&tv, 0);
    mergeInsert(_deque, 0, _deque.size() - 1);
	printTime(tv, "std::deque");
}
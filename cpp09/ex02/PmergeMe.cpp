/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:25:14 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/06 16:43:33 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

PmergeMe::PmergeMe(std::list<int> list, std::deque<int> deque) : _list(list), _deque(deque) { }

PmergeMe::PmergeMe(const PmergeMe& pmergeme)
{
	*this = pmergeme;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeme)
{
	_list = pmergeme._list;
	_deque = pmergeme._deque;
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
			throw InvalidNumber();
		_list.push_back(n);
		_deque.push_back(n);
	}
	printList("Before:  ");
	_size = ac - 1;
}

template<typename T>
void PmergeMe::insertionSort(T& array, int start, int end)
{
	typename T::iterator it = array.begin();
	typename T::iterator itEnd = array.begin();
	std::advance(it, start);
	std::advance(itEnd, end + 1);
    while (it != itEnd && it != array.end())
	{
        typename T::iterator current = it;
        int temp = *it;
        typename T::iterator prev = it;
		typename T::iterator next = prev;
		++next;
        while (prev != array.begin() && *(--prev) > temp)
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
void PmergeMe::mergeArrays(T& array, int start, int middle, int end)
{
	T left;
    T right;

    typename T::iterator it = array.begin();
    std::advance(it, start);
    for (int i = start; i <= middle; ++i)
	{
        left.push_back(*it);
        ++it;
    }

    it = array.begin();
    std::advance(it, middle + 1);
    for (int i = middle + 1; i <= end; ++i)
	{
        right.push_back(*it);
        ++it;
    }

    typename T::iterator leftIt = left.begin();
    typename T::iterator rightIt = right.begin();
    typename T::iterator mergedIt = array.begin();
    std::advance(mergedIt, start);

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
void PmergeMe::mergeSort(T& array, int start, int end)
{
	if (end - start > K)
	{
		int middle = (start + end) / 2;
		mergeSort(array, start, middle);
		mergeSort(array, middle + 1, end);
		mergeArrays(array, start, middle, end);
	}
	else
		insertionSort(array, start, end);
}

void PmergeMe::printTime(timeval tv, std::string type)
{
	struct timeval tv2;

	gettimeofday(&tv2, 0);
	double timePased = ((double)tv2.tv_usec - (double)tv.tv_usec) / 1000000;
	std::cout << "Time to process a range of " << _size <<  " elements with "
	<< type << " " << std::fixed << timePased << " us." << std::endl;
}

void PmergeMe::performSorting(int ac, char **av)
{
	pushNumbers(ac, av);
	struct timeval tv;

	gettimeofday(&tv, 0);
    mergeSort(_list, 0, _list.size() - 1);
	printList("After:   ");
	printTime(tv, "std::list");
	gettimeofday(&tv, 0);
    mergeSort(_deque, 0, _deque.size() - 1);
	printTime(tv, "std::deque");
}

std::list<int> PmergeMe::getList()
{
	return _list;
}

std::deque<int> PmergeMe::getDeque()
{
	return _deque;
}

size_t PmergeMe::getSize()
{
	return _size;
}
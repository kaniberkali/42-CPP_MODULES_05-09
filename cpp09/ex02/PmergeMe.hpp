/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:24:50 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/05 18:05:03 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>
#include <sys/time.h>

#define K 6

class PmergeMe
{
	private:
		std::list<int> _list;
		std::deque<int> _deque;
		size_t _size;

		bool isInt(char *s);
	public:
		PmergeMe();
		PmergeMe(std::list<int> list, std::deque<int> deque);
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void pushNumbers(int ac, char **av);

		void printList(std::string title);
		void printTime(timeval tv, std::string type);

		void mergeMe(int ac, char **av);

		template<typename T>
		void mergeInsert(T& A, int p, int r);
		template<typename T>
		void insertionSort(T& A, int p, int r);
};

#endif
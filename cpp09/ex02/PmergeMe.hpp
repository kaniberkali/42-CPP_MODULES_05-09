/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:24:50 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/06 16:44:01 by akaniber         ###   ########.fr       */
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
		PmergeMe(const PmergeMe& pmergeme);
		PmergeMe& operator=(const PmergeMe& pmergeme);

		void pushNumbers(int ac, char **av);

		void printList(std::string title);
		void printTime(timeval tv, std::string type);

		void performSorting(int ac, char **av);
		template<typename T>
		void mergeSort(T& A, int p, int r);
		template<typename T>
		void insertionSort(T& array, int start, int end);
		template<typename T>
		void mergeArrays(T& array, int start, int middle, int end);

		std::list<int> getList();
		std::deque<int> getDeque();
		size_t getSize();

		class InvalidNumber : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Error: invalid number."; }
		};
};

#endif
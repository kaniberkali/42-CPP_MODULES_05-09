/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:02:34 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/04 10:50:31 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &span);
		~Span();
		Span &operator=(Span const &span);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		class VectorSizeExceededException : public std::exception
		{
			virtual const char *what() const throw() { return "Vector size exceeded"; };
		};

		class LongestSpanInsufficiencyException : public std::exception
		{
			virtual const char *what() const throw() { return "Insufficient elements to calculate longest span."; };
		};

		class ShortestSpanInsufficiencyException : public std::exception
		{
			virtual const char *what() const throw() { return "Insufficient elements to calculate shortest span."; };
		};
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:03:00 by akaniber          #+#    #+#             */
/*   Updated: 2024/05/04 11:40:44 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) { }

Span::Span(unsigned int n) : _n(n) { }

Span::Span(Span const &span) : _n(span._n), _v(span._v) { }

Span::~Span() { }

Span &Span::operator=(Span const &span)
{
	if (this != &span)
	{
		this->_n = span._n;
		this->_v = span._v;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw VectorSizeExceededException();
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw ShortestSpanInsufficiencyException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); ++i)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw LongestSpanInsufficiencyException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

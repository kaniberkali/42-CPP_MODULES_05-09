/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:42:38 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/27 20:29:33 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
class ScalarConverter
{
	private:
		static char _charValue;
		static int _intValue;
		static float _floatValue;
		static double _doubleValue;

		static bool _positiveInfinityFloat;
		static bool _positiveInfinity;

		static bool _negativeInfinityFloat;
		static bool _negativeInfinity;

		static bool _infinityFloat;
		static bool _infinity;

		static bool _nanFloat;
		static bool _nan;
	
		static bool _nonDisplayable;
		static bool _impossible;

		ScalarConverter();
		ScalarConverter(ScalarConverter const &scalarConverter);
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const &scalarConverter);
	public:
		static void convert(std::string input);

		static bool isInt(std::string input);
		static bool isFloat(std::string input);
		static bool isDouble(std::string input);
		static bool isChar(std::string input);
		static bool isPseudoLiteral(std::string input);

		static int toInt(std::string input);
		static float toFloat(std::string input);
		static double toDouble(std::string input);
		static char toChar(std::string input);
		static void toPseudoLiteral(std::string input);

		static int getInt();
		static char getChar();
		static float getFloat();
		static double getDouble();

		static bool isNan();
		static bool isNanFloat();
		static bool isPositiveInfinity();
		static bool isPositiveInfinityFloat();
		static bool isNegativeInfinity();
		static bool isNegativeInfinityFloat();
		static bool isNonDisplayable();
		static bool isImpossible();
		static bool isInfinity();
		static bool isInfinityFloat();

		static void print();
		static void printChar();
		static void printInt();
		static void printFloat();
		static void printDouble();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:27:04 by akaniber          #+#    #+#             */
/*   Updated: 2024/04/27 17:34:39 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::_charValue = 0;
int ScalarConverter::_intValue = 0;
float ScalarConverter::_floatValue = 0;
double ScalarConverter::_doubleValue = 0;
bool ScalarConverter::_positiveInfinityFloat = false;
bool ScalarConverter::_positiveInfinity = false;
bool ScalarConverter::_negativeInfinityFloat = false;
bool ScalarConverter::_negativeInfinity = false;
bool ScalarConverter::_nanFloat = false;
bool ScalarConverter::_nan = false;
bool ScalarConverter::_nonDisplayable = false;
bool ScalarConverter::_impossible = false;
bool ScalarConverter::_infinityFloat = false;
bool ScalarConverter::_infinity = false;

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(ScalarConverter const &scalarConverter)
{
	*this = scalarConverter;
}

ScalarConverter::~ScalarConverter() { }

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &scalarConverter)
{
	if (this != &scalarConverter)
	{
		_charValue = scalarConverter._charValue;
		_intValue = scalarConverter._intValue;
		_floatValue = scalarConverter._floatValue;
		_doubleValue = scalarConverter._doubleValue;
		_positiveInfinityFloat = scalarConverter._positiveInfinityFloat;
		_positiveInfinity = scalarConverter._positiveInfinity;
		_negativeInfinityFloat = scalarConverter._negativeInfinityFloat;
		_negativeInfinity = scalarConverter._negativeInfinity;
		_nanFloat = scalarConverter._nanFloat;
		_nan = scalarConverter._nan;
		_nonDisplayable = scalarConverter._nonDisplayable;
		_impossible = scalarConverter._impossible;
	}
	return *this;
}

bool ScalarConverter::isInt(std::string input)
{
	try
	{
		for (size_t i = 0; i < input.length(); i++)
		{
			if (i == 0 && (input[i] == '-' || input[i] == '+'))
				continue;
			if (!isdigit(input[i]))
				return false;
		}
		long long result = std::stoll(input);
		return (result >= INT_MIN && result <= INT_MAX);
	}
	catch (std::exception &e)
	{
		return false;
	}
}

bool ScalarConverter::isFloat(std::string input)
{
	if (input[0] == '-' || input[0] == '+')
		input = input.substr(1);
    if (input.empty())
		return false;
    bool hasDot = false;
    bool hasE = false;
    bool hasSuffix = false;
    for (size_t i = 0; i < input.size(); ++i)
	{
        char c = input[i];
        if (std::isdigit(c))
            continue;
        else if (c == '.') 
		{
            if (hasDot || hasE)
                return false;
            hasDot = true;
        }
		else if (c == 'e' || c == 'E')
		{
            if (hasE || !std::isdigit(input[0]))
                return false;
            hasE = true;
            if (i + 1 < input.size() && (input[i + 1] == '-' || input[i + 1] == '+'))
                ++i;
        }
		else if (c == 'f' || c == 'F')
		{
            if (hasSuffix || c != input.back())
                return false;
            hasSuffix = true;
        }
		else if (c == '-' || c == '+')
		{
            if (i != 0 && (input[i - 1] != 'e' && input[i - 1] != 'E'))
                return false;
        }
		else
            return false;
    }
	try
	{
		if (std::isdigit(input[0]))
		{
			long long result = std::stof(input);
			return (result >= INT_MIN && result <= INT_MAX);
		}
		return false;
	}
	catch (std::exception &e)
	{
		return false;
	}
}

bool ScalarConverter::isDouble(std::string input)
{
	try
	{
		if (input[0] == '-' || input[0] == '+')
			input = input.substr(1);
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]) || input[i] == '.')
				return false;
		}
		long long result = std::stod(input);
		if (result >= INT_MIN && result <= INT_MAX)
			return true;
		return false;
	}
	catch (std::exception &e)
	{
		return false;
	}
}

bool ScalarConverter::isChar(std::string input)
{
	return (input.length() == 1 && !isdigit(input[0]) && isascii(input[0]));
}

bool ScalarConverter::isPseudoLiteral(std::string input)
{
	return (input == "nan" || input == "+inf" || input == "-inf" || input == "nanf" || input == "+inff" || input == "-inff" || input == "inff" || input == "inf");
}

char ScalarConverter::toChar(std::string input)
{
	if (isChar(input))
	{
		_charValue = input[0];
		_intValue = static_cast<int>(_charValue);
		_floatValue = static_cast<float>(_charValue);
		_doubleValue = static_cast<double>(_charValue);
	}
	return _charValue;
}

int ScalarConverter::toInt(std::string input)
{
	if (isInt(input))
	{
		_intValue = std::stoi(input);
		_charValue = static_cast<char>(_intValue);
		_floatValue = static_cast<float>(_intValue);
		_doubleValue = static_cast<double>(_intValue);
	}
	return _intValue;
}

float ScalarConverter::toFloat(std::string input)
{
	if (isFloat(input))
	{
		_floatValue = std::stof(input);
		_intValue = static_cast<int>(_floatValue);
		_charValue = static_cast<char>(_intValue);
		_doubleValue = static_cast<double>(_floatValue);
	}
	return _floatValue;
}

double ScalarConverter::toDouble(std::string input)
{
	if (isDouble(input))
	{
		_doubleValue = std::stod(input);
		_intValue = static_cast<int>(_doubleValue);
		_charValue = static_cast<char>(_intValue);
		_floatValue = static_cast<float>(_doubleValue);
	}
	return _doubleValue;
}

void ScalarConverter::toPseudoLiteral(std::string input)
{
	if (input == "nan")
	{
		_nan = true;
		_nanFloat = true;
	}
	else if (input == "+inf")
	{
		_positiveInfinity = true;
		_positiveInfinityFloat = true;
	}
	else if (input == "-inf")
	{
		_negativeInfinity = true;
		_negativeInfinityFloat = true;
	}
	else if (input == "inf" || input == "inff")
	{
		_infinity = true;
		_infinityFloat = true;
	}
	else if (input == "nanf")
		_nanFloat = true;
	else if (input == "+inff")
		_positiveInfinityFloat = true;
	else if (input == "-inff")
		_negativeInfinityFloat = true;
	_impossible = true;
}

void ScalarConverter::convert(std::string input)
{
	if (!input.empty())
	{
		if (isInt(input))
			toInt(input);
		else if (isFloat(input))
			toFloat(input);
		else if (isDouble(input))
			toDouble(input);
		else if (isChar(input))
			toChar(input);
		else if (isPseudoLiteral(input))
			toPseudoLiteral(input);
		else
			_impossible = true;
	}
}

void ScalarConverter::printChar()
{
	std::cout << "char: ";
	if (_impossible)
		std::cout << "impossible" << std::endl;
	else if (_nonDisplayable)
		std::cout << "Non displayable" << std::endl;
	else
	{
		if (_charValue < 32 || _charValue > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << _charValue << "'" << std::endl;
	}
}

void ScalarConverter::printInt()
{
	std::cout << "int: ";
	if (_impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _intValue << std::endl;
}

void ScalarConverter::printFloat()
{
	std::cout << "float: ";
	if (_nanFloat || _nan)
		std::cout << "nanf" << std::endl;
	else if (_positiveInfinityFloat)
		std::cout << "+inff" << std::endl;
	else if (_negativeInfinityFloat)
		std::cout << "-inff" << std::endl;
	else if (_infinityFloat)
		std::cout << "inff" << std::endl;
	else if (_impossible)
		std::cout << "impossible" << std::endl;
	else
	{
		if (floor(_floatValue) == _floatValue)
			std::cout << _floatValue << ".0f" << std::endl;
		else
			std::cout << _floatValue << "f" << std::endl;
	}
}

void ScalarConverter::printDouble()
{
	std::cout << "double: ";
	if (_nan || _nanFloat)
		std::cout << "nan" << std::endl;
	else if (_positiveInfinity)
		std::cout << "+inf" << std::endl;
	else if (_negativeInfinity)
		std::cout << "-inf" << std::endl;
	else if (_infinity)
		std::cout << "inf" << std::endl;
	else if (_impossible)
		std::cout << "impossible" << std::endl;
	else
	{
		if (floor(_doubleValue) == _doubleValue)
			std::cout << _doubleValue << ".0" << std::endl;
		else
			std::cout << _doubleValue << std::endl;
	}
}

void ScalarConverter::print()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

int ScalarConverter::getInt()
{
	return _intValue;
}

char ScalarConverter::getChar()
{
	return _charValue;
}

float ScalarConverter::getFloat()
{
	return _floatValue;
}

double ScalarConverter::getDouble()
{
	return _doubleValue;
}

bool ScalarConverter::isNan()
{
	return _nan;
}

bool ScalarConverter::isNanFloat()
{
	return _nanFloat;
}

bool ScalarConverter::isPositiveInfinity()
{
	return _positiveInfinity;
}

bool ScalarConverter::isPositiveInfinityFloat()
{
	return _positiveInfinityFloat;
}

bool ScalarConverter::isNegativeInfinity()
{
	return _negativeInfinity;
}

bool ScalarConverter::isNegativeInfinityFloat()
{
	return _negativeInfinityFloat;
}

bool ScalarConverter::isNonDisplayable()
{
	return _nonDisplayable;
}

bool ScalarConverter::isImpossible()
{
	return _impossible;
}

bool ScalarConverter::isInfinity()
{
	return _infinity;
}

bool ScalarConverter::isInfinityFloat()
{
	return _infinityFloat;
}

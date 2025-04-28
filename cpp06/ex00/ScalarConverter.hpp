/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:08:35 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/22 17:55:08 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
	std::string scalar;
	int i;
	char c;
	float f;
	double d;
	ScalarConverter(std::string scalar);
public:

	ScalarConverter(ScalarConverter const &o);
	ScalarConverter &operator=(ScalarConverter const &o);
	~ScalarConverter();

	static void convert(const std::string &literal);
};

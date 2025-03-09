/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:08:35 by mbentahi          #+#    #+#             */
/*   Updated: 2025/03/09 01:09:39 by mbentahi         ###   ########.fr       */
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

public:

	ScalarConverter(std::string scalar);
	ScalarConverter(ScalarConverter const &o);
	ScalarConverter &operator=(ScalarConverter const &o);
	~ScalarConverter();

	void convert();
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:25:46 by mbentahi          #+#    #+#             */
/*   Updated: 2024/10/07 22:33:53 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>
# include <cmath>

class Fixed
{
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(int const value);
		Fixed(const float value);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		Fixed operator+(Fixed const &a);
		Fixed operator-(Fixed const &a);
		Fixed operator*(Fixed const &a);
		Fixed operator/(Fixed const &a);
		bool operator>(Fixed const &a) const;
		bool operator<(Fixed const &a) const;
		bool operator>=(Fixed const &a);
		bool operator<=(Fixed const &a);
		bool operator==(Fixed const &a);
		bool operator!=(Fixed const &a);
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		int getRawBits(void) const;
		void setRawBits(int const raw);	
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);
#endif
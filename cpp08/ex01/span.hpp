/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:43:49 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/20 21:00:09 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
class Span
{
	private:
		unsigned int N;
		int *Array;
		unsigned int counter;
	public:
		Span();
		Span(unsigned int);
		Span(Span const &);
		Span &operator=(Span const &);
		~Span();
		void addNumber(int);
		void addNumber(std::vector<int>::iterator begin,std::vector<int>::iterator end);
		int longestSpan();
		int shortestSpan();
		void show();
};
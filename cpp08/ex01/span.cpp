/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:43:56 by mbentahi          #+#    #+#             */
/*   Updated: 2025/07/14 08:58:58 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : N(0), Array(NULL), counter(0)
{
}

Span::Span(unsigned int n) : N(n), counter(0)
{
	Array = new int[N];
}

Span::Span(Span const &c)
{
	*this = c;
}

Span &Span::operator=(Span const &c)
{
	if (this == &c)
		return *this;
	this->N = c.N;
	if (this->Array)
		delete[] Array;
	this->Array = new int[this->N];
	this->counter = c.counter;
	for (unsigned int i = 0; i < N; i++)
		this->Array[i] = c.Array[i];
	return *this;
}

Span::~Span()
{
	delete[] Array;
}

void Span::show()
{
	for (unsigned int i = 0; i < counter; i++)
		std::cout << "Array[" << i << "] : " << this->Array[i] << std::endl;
}

void Span::addNumber(int n)
{
	if (counter >= N)
		throw std::runtime_error("size exceeded");
	this->Array[counter] = n;
	counter++;
}

int Span::shortestSpan()
{
	if (counter < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> sortedArray(Array, Array + counter);
	std::sort(sortedArray.begin(), sortedArray.end());

	int shortest = INT_MAX;
	for (size_t i = 1; i < sortedArray.size(); i++)
	{
		int diff = sortedArray[i] - sortedArray[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan()
{
	if (counter < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int minElement = *std::min_element(Array, Array + counter);
	int maxElement = *std::max_element(Array, Array + counter);

	return maxElement - minElement;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (counter + std::distance(begin, end) > N)
		throw std::runtime_error("size exceeded");
	for (std::vector<int>::iterator it = begin; it != end; ++it)
	{
		this->Array[counter] = *it;
		counter++;
	}
}
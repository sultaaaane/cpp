/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:42:33 by mbentahi          #+#    #+#             */
/*   Updated: 2025/06/23 10:34:26 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	~MutantStack() {}

	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}

	iterator begin() { return this->c.begin(); }
	const_iterator begin() const { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator end() const { return this->c.end(); }
};
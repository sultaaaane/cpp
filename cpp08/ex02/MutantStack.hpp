/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:42:33 by mbentahi          #+#    #+#             */
/*   Updated: 2025/07/14 10:40:29 by mbentahi         ###   ########.fr       */
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
	iterator end() { return this->c.end(); }
};
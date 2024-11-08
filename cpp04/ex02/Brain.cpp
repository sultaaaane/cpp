/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:39:34 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/08 11:09:10 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &c)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = c;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &c)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &c)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = c.getIdea(i);
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
}

void Brain::setallIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:10:16 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/15 15:10:38 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	t_data *new_data;

	new_data = global_data();
	if (new_data->ptr)
		ft_lstclear_free(&new_data);
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < count; i++)
	{
		// if (inventory[i])
		// 	delete inventory[i];
		inventory[i] = 0;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	t_data *new_data;

	new_data = global_data();
	if (this->count < 4)
	{
		std::cout << "Learning " << m->getType() << std::endl;
		this->inventory[this->count] = m;
		ft_lstadd_back_free(&new_data, init_data(this->inventory[this->count]));
		this->count++;
	}
	else
		std::cout << "Inventory is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->count; i++)
	{
		if (this->inventory[i]->getType() == type)
			return (this->inventory[i]->clone());
	}
	return (0);
}
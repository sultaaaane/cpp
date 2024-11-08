/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:01:18 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/08 11:10:26 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int numAnimals = 10;
	Animal* animals[numAnimals];
	for (int i = 0; i < numAnimals / 2; ++i) {
		animals[i] = new Dog();
	}
	for (int i = numAnimals / 2; i < numAnimals; ++i) {
		animals[i] = new Cat();
	}
	for (int i = 0; i < numAnimals; ++i) {
		delete animals[i];
	}
	return 0;
}
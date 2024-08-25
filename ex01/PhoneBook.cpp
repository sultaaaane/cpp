/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:13:21 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/16 13:51:22 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

void PhoneBook::addContact(Contact contact)
{
	if (this->nbContacts < 8)
	{
		this->contacts[this->nbContacts] = contact;
		this->nbContacts++;
	}
	else
	{
		// this->nbContacts = 0;
		this->contacts[0] = contact;
	}
}

PhoneBook::PhoneBook()
{
	this->nbContacts = 0;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void PhoneBook::searchContact()
{
	int i;
	int index;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	i = 0;
	std::cout << " index    |first name| last name| nickname " << std::endl;
	while (i < this->nbContacts)
	{
		std::cout << "here" << std::endl;
		std::cout << std::setw(10) << i << "|";
		firstName = this->contacts[i].getFirstName();
		lastName = this->contacts[i].getLastName();
		nickName = this->contacts[i].getNickName();
		if (firstName.length() > 10)
		{
			firstName = firstName.substr(0, 9);
			firstName += ".";
			std::cout << firstName << "|";
		}
		else	
			std::cout << std::setw(10) << firstName << "|";
		if (lastName.length() > 10)
		{
			lastName = lastName.substr(0, 9);
			lastName += ".";
			std::cout << lastName << "|";
		}
		else
			std::cout << std::setw(10) << lastName << "|";
		if (nickName.length() > 10)
		{
			nickName = nickName.substr(0, 9);
			nickName += ".";
			std::cout << nickName  << std::endl;
		}
		else
			std::cout << std::setw(10) << nickName  << std::endl;
		i++;
	}
	std::cout << "Enter the index of the contact you want to see: "<< std::endl;
	std::cin >> index;
	if (std::cin.eof())
		return ;
	if (index >= this->nbContacts || index < 0 || index >= 8)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	firstName = this->contacts[index].getFirstName();
	lastName = this->contacts[index].getLastName();
	nickName = this->contacts[index].getNickName();
	phoneNumber = this->contacts[index].getPhoneNumber();
	darkestSecret = this->contacts[index].getDarkestSecret();
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nick name: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
	
}

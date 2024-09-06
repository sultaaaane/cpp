/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:13:21 by mbentahi          #+#    #+#             */
/*   Updated: 2024/09/05 17:05:10 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

void PhoneBook::addContact(Contact contact)
{
	if (this->nbContacts < 8)
	{
		this->contacts[this->nbContacts] = contact;
		this->nbContacts++;
		if (this->nbinc < 8)
			this->nbinc++;
	}
	else
	{
		this->nbContacts = 0;
		this->contacts[this->nbContacts] = contact;
		this->nbContacts++;
	}
}

PhoneBook::PhoneBook()
{
	this->nbContacts = 0;
	this->nbinc = 0;
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
	while (i < this->nbinc)
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
	if (std::cin.fail())
	{
		std::cout << "Invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (index >= this->nbinc || index < 0 || index >= 8)
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

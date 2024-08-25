/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:04:11 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/15 17:12:13 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
	return (this->firstName);
}

std::string Contact::getLastName()
{
	return (this->lastName);
}

std::string Contact::getNickName()
{
	return (this->nickName);
}

std::string Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}

Contact::Contact(std::string firstName,std::string lastName,std::string nickName,std::string phoneNumber,std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	return ;
}

Contact::~Contact()
{
	return ;
}

Contact::Contact()
{
	return ;
}

int isNumber(std::string str)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

Contact Contact::setContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	std::cout << "Enter the first name: " << std::endl;
	std::cin >> firstName;
	if(std::cin.eof())
		return (Contact("", "", "", "", ""));
	if (isNumber(firstName))
	{
		std::cout << "Error: First name must be a string" << std::endl;
		return (Contact("", "", "", "", ""));
	}
	std::cout << "Enter the last name: " << std::endl;
	std::cin >> lastName;
	if(std::cin.eof())
		return (Contact("", "", "", "", ""));
	if (isNumber(lastName))
	{
		std::cout << "Error: Last name must be a string" << std::endl;
		return (Contact("", "", "", "", ""));
	}
	std::cout << "Enter the nick name: " << std::endl;
	std::cin >> nickName;
	if(std::cin.eof())
		return (Contact("", "", "", "", ""));
	if (isNumber(nickName))
	{
		std::cout << "Error: Nick name must be a string" << std::endl;
		return (Contact("", "", "", "", ""));
	}
	std::cout << "Enter the phone number: " << std::endl;
	std::cin >> phoneNumber;
	if(std::cin.eof())
		return (Contact("", "", "", "", ""));
	if (!isNumber(phoneNumber))
	{
		std::cout << "Error: Phone number must be a number" << std::endl;
		return (Contact("", "", "", "", ""));
	}
	std::cout << "Enter the darkest secret: " << std::endl;
	std::cin >> darkestSecret;
	if(std::cin.eof())
		return (Contact("", "", "", "", ""));	
	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: Empty field" << std::endl;
		return (Contact("", "", "", "", ""));
	}
	Contact contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	return (contact);
}

bool Contact::isValid()
{
	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() ||
			 darkestSecret.empty())
		return false;
	if (!isNumber(phoneNumber) || isNumber(firstName) || isNumber(lastName) || isNumber(nickName))
		return false;
	if (phoneNumber.length() < 10 || phoneNumber.length() > 15)
		return false;
	return true;
}
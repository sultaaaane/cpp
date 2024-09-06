/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:33:38 by mbentahi          #+#    #+#             */
/*   Updated: 2024/09/05 16:57:41 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_HPP
#define PHONE_HPP

#include <iostream>
#include <string>
#include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	
	public:
		Contact();
		Contact(std::string firstName,std::string lastName,std::string nickName,std::string phoneNumber,std::string darkestSecret);
		~Contact();
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickName(std::string nickName);
		void setPhoneNumber(std::string phoneNumber);
		void setDarkestSecret(std::string darkestSecret);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		bool isValid();
		Contact setContact();
};

class PhoneBook
{
	private:
		Contact contacts[8];
		int nbContacts;
		int nbinc;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact contact);
		void searchContact();
};

#endif
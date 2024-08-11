/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:53:33 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/11 19:21:43 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command: " << std::endl;
        std::getline(std::cin, command);
        if (std::cin.eof())
			return 1;
        if (command == "ADD")
        {
            Contact contact;
            contact = contact.setContact();
            if (contact.isValid())
            {
                phoneBook.addContact(contact);
                std::cout << "Contact added" << std::endl;
            }
            else
                std::cout << "Invalid contact input. Contact not added." << std::endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
            std::cout << "Search completed" << std::endl;
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting program" << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Try: 'ADD' or 'SEARCH' or 'EXIT'" << std::endl;
    }
    return (0);
}

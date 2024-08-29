/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:53:33 by mbentahi          #+#    #+#             */
/*   Updated: 2024/08/29 12:16:53 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;
    int i = 0;
    
    while (1)
    {
        std::cout << "Enter a command: " << std::endl;
        while (1)
        {
            std::getline(std::cin, command, '\n');
            if (std::cin.eof())
		    	return 1;
            if (command.empty())
                std::cout << "Invalid command. Try: 'ADD' or 'SEARCH' or 'EXIT'" << std::endl;
            else
                break;
        }
        if (command == "ADD")
        {
            Contact contact;
            contact = contact.setContact();
            if (contact.isValid())
            {
                phoneBook.addContact(contact);
                std::cout << "Contact added" << std::endl;
                i++;
            }
            else
                std::cout << "Invalid contact input. Contact not added." << std::endl;
        }
        else if (command == "SEARCH")
        {
            if (i == 0)
            {
                std::cout << "No contacts to search" << std::endl;
                continue;
            }
            phoneBook.searchContact();
            std::cout << "Search completed" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

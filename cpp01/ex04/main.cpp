/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:52:14 by mbentahi          #+#    #+#             */
/*   Updated: 2024/09/08 11:43:10 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int ac,char **av)
{
	std::fstream file;
	std::string s1,s2;
	std::string filename;
	
	if (ac != 4)
	{
		std::cout << "usage : <filename> , <first string> , <second string> ." << std::endl;
		return 0;
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "they need to equal something ." << std::endl;
		return 0;
	}
	file.open(filename.c_str(), std::ios::in);
	if (!file.is_open())
	{
		std::cout << "file not found." << std::endl;
		return 0;
	}
	file.close();
	Sed sed(filename);
	sed.replace(s1,s2);
	return 0;
}

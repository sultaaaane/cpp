/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:38:01 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/20 11:10:47 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	std::deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(5);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator it = easyfind(lst, 6);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::deque<int>::iterator it = easyfind(deq, 2);
		std::cout << "Found in deque: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
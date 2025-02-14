/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:14:29 by mbentahi          #+#    #+#             */
/*   Updated: 2025/02/08 12:28:13 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	// {
	// 	try
	// 	{
	// 		Bureaucrat a;
	// 		Form b;

	// 		std::cout << a;
	// 		std::cout << b;
	// 		b.beSigned(a);
	// 		std::cout << b;
	// 		a.signForm(b);
	// 	}
	// 	catch(std::exception &e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	{
		try
		{
			Bureaucrat a("Assistant", 150);
			Bureaucrat b("CEO", 1);
			std::cout << a;
			std::cout << b;
			Form c("Rent Contract", 1145, 100);

			std::cout << c;

			// c.beSigned(a);
			a.signForm(c);
			std::cout << c;
			c.beSigned(b);
			std::cout << c;
			b.signForm(c);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	// try
	// {
	// 	Bureaucrat bur("John", 11);
	// 	Bureaucrat bur2("Doe", 150);

	// 	Form form("Form", 20, 1);

	// 	std::cout << bur;
	// 	std::cout << bur2 << std::endl;

	// 	std::cout << form << std::endl;
	// 	form.beSigned(bur);
	// 	std::cout << form << std::endl;
	// 	bur.signForm(form);

	// 	std::cout <<  std::endl;

	// 	form.beSigned(bur2);
	// 	std::cout << form << std::endl;
	// 	bur2.signForm(form);
	// 	// form.beSigned(bur2);
	// 	// std::cout << form << std::endl;
	// 	// bur2.signForm(form);

	// }
	// catch (std::exceptio& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// return 0;
}
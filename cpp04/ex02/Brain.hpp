/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:39:41 by mbentahi          #+#    #+#             */
/*   Updated: 2024/11/07 17:30:17 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <fcntl.h>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &c);
		virtual ~Brain();
		Brain &operator=(const Brain &c);
		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
		void setallIdeas(std::string idea);
};
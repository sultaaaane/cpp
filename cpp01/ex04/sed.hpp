/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:52:29 by mbentahi          #+#    #+#             */
/*   Updated: 2024/09/01 18:41:16 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <limits>
# include <cctype>
# include <cstdlib>
# include <iomanip>
#include <fcntl.h>

class Sed
{
	private:
		std::string filename;
		std::fstream file;
		std::fstream replace_file;
	public:
		Sed(std::string filename);
		~Sed();
		std::string get_filecontent();
		void replace(std::string s1,std::string s2);
		void change_in_file();
};

#endif
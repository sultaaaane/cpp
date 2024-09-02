/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:52:35 by mbentahi          #+#    #+#             */
/*   Updated: 2024/09/02 09:39:59 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

Sed::Sed(std::string filename)
{
	this->filename = filename;
	this->file.open(filename.c_str(), std::ios::in);
	if (!this->file.is_open())
	{
		std::cout << "file not found ." << std::endl;
		exit(0);
	}
	this->replace_file.open(filename.append(".replace").c_str(), std::ios::out);
}

Sed::~Sed()
{
	this->file.close();
	this->replace_file.close();
}

std::string Sed::get_filecontent()
{
	std::string content;
	std::string line;

	while (std::getline(this->file, line))
	{
		if (!this->file.eof()) {
			content.append(line);
			content.append("\n");
		} else {
			content.append(line);
		}
	}
	return content;
}

void Sed::replace(std::string s1, std::string s2)
{
	std::string content = this->get_filecontent();
	std::string replacer;
	size_t pos = 0 , prev_pos = 0;

	while ((pos = content.find(s1, prev_pos)) != std::string::npos)
	{
		replacer.append(content, prev_pos , pos - prev_pos);
		replacer.append(s2);
		prev_pos = pos + s1.length();
	}
	replacer.append(content, prev_pos, content.length() - prev_pos);
	this->replace_file << replacer;
}

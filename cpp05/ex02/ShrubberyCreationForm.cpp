/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:38:43 by mbentahi          #+#    #+#             */
/*   Updated: 2025/02/13 16:36:21 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : Form(copy), target(copy.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	if (this != &copy)
	{
		this->target = copy.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec() || executor.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	
	std::string filename = this->target + "_shrubbery";
	
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw "Cannot open file";
	file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠒⡄⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠂⢿⠇⣨⠆⠀⣠⠋⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠣⢤⣇⠀⠀⠐⠤⢼⡿⡅⡠⠀⢀⠀⢡⣾⡅⠀⠀⠀⠀⢀⠀⣆⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠀⡤⢀⠀⠀⡀⠀⠀⠀⣇⣠⠄⠀⠀⣿⠀⠀⠀⠤⠴⢀⠼⠀⠀⠈⢉⠉⣹⡀⠀⠀⠀⠀⠀⠉⣹⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢲⣿⢾⣀⠀⡧⣶⠊⠀⠸⢿⠓⢤⣄⣹⣆⣠⠀⠀⠀⠀⡀⠀⡄⠀⠈⣽⠇⠀⠀⠀⡀⠀⣸⠋⠉⠒⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠰⣀⣔⠀⢀⣭⣅⣠⣷⠃⠈⢹⠏⠱⡴⠧⣶⣤⠔⠈⣟⣿⣿⡇⠀⠀⠀⠙⢼⣷⣠⣾⡟⠁⢠⣴⣏⠀⣸⣧⠀⢠⣤⠊⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠤⠤⠽⢻⠉⢳⠀⠀⠀⠀⠑⠲⠓⠄⡠⠃⠀⡸⠛⠳⣆⠈⠻⠮⠿⣦⡀⠓⠒⣩⣿⠟⠵⣋⡒⠉⢩⠃⠘⣏⠀⡟⠙⡟⢀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠠⠀⠞⠒⠈⠀⠀⠀⠀⠀⠀⠀⢠⡀⠀⢰⣃⣀⠀⠿⣦⠀⠀⠐⢿⣷⣠⣞⣿⣿⠛⠛⠋⠉⠒⠊⠁⠈⠁⢀⠈⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠉⠒⠸⣵⡷⡄⠀⢘⡶⠘⣄⣖⡁⢈⠃⠩⠉⠋⠐⠑⠄⠀⠀⠀⠀⠀⢚⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣄⣦⡔⠁⠀⠰⣄⢀⣠⠋⠀⠰⡚⠉⣧⡄⠘⢻⠀⠙⡄⠀⠀⠀⠸⡀⣠⡄⠀⠀⡠⠄⡀⠈⠉⠀⠀⠀⡄⢀⠀⠀⠀⢠⣀⣤⡄⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠠⠤⣞⣑⠎⠀⠀⠀⠀⠈⠣⢤⠜⠀⠀⠹⢿⡤⡞⠉⡏⡇⠀⠀⠀⢀⣀⡝⠻⡤⠂⠱⣾⡄⠀⠀⠀⠓⠢⢯⡷⣀⠀⢀⡴⢆⣼⣃⡆" << std::endl <<
"⠀⢢⣧⠀⠀⠀⠀⣜⡑⠲⣿⢅⡠⠀⠀⠙⢷⣤⡀⠀⠰⢀⣦⡬⠂⠀⠀⠀⢯⣷⣀⠀⣷⣧⠄⠀⢀⠀⠈⠱⣎⠀⠈⠩⢠⡗⠂⠀⠀⠘⢤⣾⠀⣜⡴⠟⠁⠀⠀⠈⠀" << std::endl <<
"⠀⢨⠏⢰⠒⠖⣲⠙⣿⣾⠧⣼⣄⠀⠘⢆⣰⣟⣷⣖⠢⢤⠋⠡⠂⠀⠀⠀⢈⡾⣿⠷⣿⣿⣿⠁⠀⠀⠀⡰⢻⣶⣧⢠⡟⠀⡀⠀⠀⣠⣟⣿⡞⣋⡄⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠈⣻⠿⣈⣯⠒⢿⠯⢉⡟⡟⠛⠻⢟⣦⣤⣛⢣⠀⣻⣧⠀⠙⣷⡄⠀⠀⢈⠓⠀⢈⣷⢻⢿⣦⠂⠀⠀⠀⠣⠼⣟⣿⣟⡎⠀⢳⣻⢄⣠⣋⠿⢷⠘⠤⣶⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠑⠴⠃⠸⠓⠣⠤⠋⠉⠀⠀⠀⠘⠈⠙⠿⡏⠈⡻⠋⠁⣄⣈⣻⠟⠢⢼⣹⣏⠀⠉⢿⠸⣿⣷⠀⠀⡀⠀⢰⣿⠟⠁⣀⡏⠉⣹⡀⣹⠣⣀⠜⢩⠿⣡⡊⠀⠀⠀⠀" << std::endl <<
"⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢶⣳⡖⠺⡞⠯⢵⣀⣀⡔⠉⠈⡦⣴⠻⣷⣿⣷⣀⢸⣥⠄⠾⢇⣠⢞⣫⢿⣮⣭⣍⣀⣀⣠⣴⣯⡶⣏⡇⠀⠀⠀⠀" << std::endl <<
"⠠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠒⠴⠊⠁⢀⣠⣶⣶⠿⠿⠷⠷⢤⣤⣷⡟⢧⠹⣿⡃⠈⡹⠋⢃⣀⣼⠕⠋⠉⠉⠀⠀⠀⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⡀⢸⢤⡄⠀⠀⠀⣠⣵⡶⠛⠋⠀⠀⠀⠀⠀⠀⠀⢫⣄⣷⣖⢓⢿⣿⣫⣧⣤⢼⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⡟⠙⣄⡠⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠤⢎⣨⡏⠘⣿⣿⡟⡵⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠺⣄⣀⡼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⣷⠀⣿⡿⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⣿⠀⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⡯⢀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⡸⠀⣼⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl <<
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣧⠃⣼⡟⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl ;


}
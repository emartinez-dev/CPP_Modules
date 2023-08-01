/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:00:28 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 18:28:26 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <exception>
#include <fstream>
#include <ios>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm():AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):\
	AForm("Shrubbery Creation Form", 145, 137, target)
{
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy):\
	AForm(copy)
{
}

ShrubberyCreationForm	\
	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return *this;
}

void  ShrubberyCreationForm::doExecute(void) const
{
	std::string	  filename;
	std::ofstream outfile;
	std::string	  ascii_tree;

	ascii_tree =
        "                                               .\n"
        "                                   .         ;\n"
        "      .              .              ;%     ;;\n"
        "        ,           ,                :;%  %;\n"
        "         :         ;                   :;%;     .,\n"
        "          ,;     %;            ;        %;'    ,;\n"
        "            ;%;  %%;        ,     %;    ;%;    ,%'\n"
        "             %;%;      ,  ;       %;  ;%;   ,%;'\n"
        "              ;%;        ;%;        % ;%;  ,%;'\n"
        "               `%;.     ;%;         `;%%;.%;'\n"
        "                 `:;%.    ;%%.        ;@@%;'\n"
        "                    `:%;.  :;bd%;     %@@%;\n"
        "                      `@%:.  :;%.    ;@@%;\n"
        "                        `@%.  `@%.  ;@@%;\n"
        "                          `@%%. `@%%;@@%;\n"
        "                            ;@%. :@%%'%%;\n"
        "                              %@bd%%%bd%:\n"
        "                                #@%%%%%;%\n"
        "                                %@@%%%::;\n"
        "                                %@@@%(o);  . '\n"
        "                                %@@@o%;:(.,'\n"
        "                            `.. %@@@o%::;\n"
        "                               `)@@@o%::;\n"
        "                                %@@(o)::;\n"
        "                               .%@@@@%::;\n"
        "                             ;%@@@@%%:;;;.\n"
        "                         ...;%@@@@@%%:;;;;,..";

	filename = this->getTarget() + "_shrubbery";
	outfile.open(filename, std::ios::out);
	if (!outfile)
	{
		std::cout << "There was a problem creating the file" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
		outfile << ascii_tree << std::endl;

	std::cout << "The tree '" << getTarget() << "' has been created succesfully" << std::endl;
	outfile.close();
	
}


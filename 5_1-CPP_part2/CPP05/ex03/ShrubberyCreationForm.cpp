/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:17:27 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 14:42:00 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Default ShrubberyCreation Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreation with target Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	std::cout << "ShrubberyCreation copy Constructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
	if (this != &a)
		this->_target = a._target;
	return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const &exe) const
{
	try
	{
		this->check_exec(exe);
		std::ofstream _outfile((this->_target + "_shrubbery").c_str());
		if (_outfile.fail())
			throw ExeFailException();
		else
		{
			_outfile << "            .        +          .      .          .     " << std::endl
			<< "     .            _        .                    .                " << std::endl
			<< "  ,              /;-._,-.____        ,-----.__                   " << std::endl
			<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,               " << std::endl
			<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /               " << std::endl
			<< "                      ,    `./  \\:. `.   )==-'  .               " << std::endl
			<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .          " << std::endl
			<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o                  " << std::endl
			<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .            " << std::endl
			<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7         " << std::endl
			<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/        " << std::endl
			<< "              \\:  `  X` _| _,\\/'   .-'                         " << std::endl
			<< ".               \":._:`\\____  /:'  /      .           .         " << std::endl
			<< "                    \\::.  :\\/:'  /              +              " << std::endl
			<< "   .                 `.:.  /:'  }      .                         " << std::endl
			<< "           .           ):_(:;   \\           .                   " << std::endl
			<< "                      /:. _/ ,  |                                " << std::endl
			<< "                   . (|::.     ,`                  .             " << std::endl
			<< "     .                |::.    {\\                                " << std::endl
			<< "                      |::.\\  \\ `.                              " << std::endl
			<< "                      |:::(\\    |                               " << std::endl
			<< "              O       |:::/{ }  |                  (o            " << std::endl
			<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`          " << std::endl
			<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~       " << std::endl;
			_outfile.close();
			std::cout << exe.getName() << " executed " << this->getName() << std::endl;
	}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i)
{
	o << "| Name of form : " << i.getName() << " | level to sign : " << i.getLevelSign() << " | level to execute : " << i.getLevelExe() << std::endl << std::endl;
	return o;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreation destructor called" << std::endl;
}

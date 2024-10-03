/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:50 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 14:25:14 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("test"), _signed(0), _levelSign(0), _levelExe(0)
{
	std::cout << "Default Form Constructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("error form: grade too high !!!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("error form: grade too low !!!");
}

Form::Form(std::string name, int levelSign, int levelExe) : _name(name)
{
	std::cout << "Form's name and levels initialized" << std::endl;
	if (levelExe > 150 || levelSign > 150)
		throw GradeTooLowException();
	if (levelExe < 1 || levelSign < 1)
		throw GradeTooHighException();
	if (levelSign >= 1 && levelSign <= 150)
		this->_levelSign = levelSign;
	if (levelExe >= 1 && levelExe <= 150)
		this->_levelExe = levelExe;
}

std::string Form::getName( void )
{
	return (_name);
}

int Form::getLevelSign( void )
{
	return (_levelSign);
}

int Form::getLevelExe( void )
{
	return (_levelExe);
}

void Form::beSigned(Bureaucrat &bob)
{
	if (bob.getGrade() <= this->_levelSign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}


std::ostream &operator<<(std::ostream &o, Form &i)
{
	o << std::endl << "| Name of form : " << i.getName() << " | level to sign : " << i.getLevelSign() << " | level to execute : " << i.getLevelExe() << std::endl << std::endl;

	return o;
}

Form::~Form()
{
	std::cout << "Default Form destructor called" << std::endl;
}

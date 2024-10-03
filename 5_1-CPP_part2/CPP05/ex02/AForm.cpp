/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:50 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 11:08:03 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("test"), _signed(false), _levelSign(0), _levelExe(0)
{
	std::cout << "Default Form Constructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("error form: grade too high !!!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("error form: grade too low !!!");
}

const char* AForm::ExeFailException::what() const throw()
{
	return ("error form: form failed to execute !!!");
}

AForm::AForm(std::string name, int levelSign, int levelExe) : _name(name), _signed(false)
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

AForm &AForm::operator=(AForm const &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_levelExe = copy._levelExe;
		this->_levelSign = copy._levelSign;
		this->_signed = copy._signed;
	}
	return *this;
}

std::string AForm::getName( void ) const
{
	return (_name);
}

bool AForm::getSigned( void ) const
{
	return (_signed);
}

int AForm::getLevelSign( void ) const
{
	return (_levelSign);
}

int AForm::getLevelExe( void ) const
{
	return (_levelExe);
}

bool AForm::beSigned(Bureaucrat const &bob)
{
	if (bob.getGrade() <= this->_levelSign)
		this->_signed = 1;
	return (this->_signed);
}

void AForm::check_exec(Bureaucrat const &exe) const
{
	if (this->getSigned() == true)
		throw ExeFailException();
	else if (this->getLevelExe() < exe.getGrade())
		throw ExeFailException();
}

void	AForm::restart_sign( void )
{
	if (this->_signed == 1)
		this->_signed = 0;
}

std::ostream &operator<<(std::ostream &o, AForm &i)
{
	o << std::endl << "| Name of form : " << i.getName() << " | level to sign : " << i.getLevelSign() << " | level to execute : " << i.getLevelExe() << std::endl << std::endl;

	return o;
}

AForm::~AForm()
{
	std::cout << "Default Form destructor called" << std::endl;
}

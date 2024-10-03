/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:43 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 14:21:16 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(0)
{
	std::cout << "Default Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade >= 1 && grade <= 150)
	{
		this->_grade = grade;
		std::cout << "Name and grade initialized" << std::endl;
	}
	else if (grade < 1)
		throw GradeTooHighException();
	else
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a)
{
	if (this != &a)
	{
		this->_name = a._name;
		this->_grade = a._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &i)
{
	o << std::endl << i.getName() << ", Bureaucrat grade : " << i.getGrade() << std::endl << std::endl;

	return o;
}

std::string Bureaucrat::getName( void ) const
{
	return (_name);
}

int Bureaucrat::getGrade( void ) const
{
	return (_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("error bureaucrat: grade too high !!!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("error bureaucrat: grade too low !!!");
}

void	Bureaucrat::downGrade( void )
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	if (this->_grade < 150 && this->_grade >= 1)
		this->_grade++;
	std::cout << "Downgrade succesfull" << std::endl;
}

void	Bureaucrat::upGrade( void )
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	if (this->_grade <= 150 && this->_grade > 1)
		this->_grade--;
	std::cout << "Upgrade succesfull" << std::endl;
}

void Bureaucrat::signForm( Form &f )
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->getName() << " could not signed " << f.getName() << " because only Bureaucrat with level " << f.getLevelSign() << " can sign and " << this->getName() << " is level " << this->getGrade() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor called" << std::endl;
}
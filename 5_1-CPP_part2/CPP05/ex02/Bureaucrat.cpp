/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:43 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 11:32:04 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(0)
{
	std::cout << "Default Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat's Name and grade initialized" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
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
}

void	Bureaucrat::upGrade( void )
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	if (this->_grade <= 150 && this->_grade > 1)
		this->_grade--;
}

void Bureaucrat::signForm( AForm &f )
{
	if (f.getLevelSign() >= this->getGrade())
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	else
		std::cout << this->getName() << " could not signed " << f.getName() << " because only Bureaucrat with level " << f.getLevelSign() << " can sign and " << this->getName() << " is level " << this->getGrade() << std::endl;
}

void	Bureaucrat::executeForm( AForm &f ) 
{
	try
	{
		f.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor called" << std::endl;
}
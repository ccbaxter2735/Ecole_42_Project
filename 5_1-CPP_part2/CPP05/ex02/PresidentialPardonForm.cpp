/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:23:58 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 14:40:45 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentPardonForm", 25, 5)
{
	std::cout << "Default PresidentialPardon Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardon with target Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm::AForm("PresidentPardonForm", 25, 5), _target(copy.getTarget())
{
	std::cout << "PresidentialPardon copy Constructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
	if (this != &a)
		this->_target = a._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &exe) const
{
	try
	{
		this->check_exec(exe);
		std::cout << this->_target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
		std::cout << exe.getName() << " executed " << this->getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i)
{
	o << "| Name of form : " << i.getName() << " | level to sign : " << i.getLevelSign() << " | level to execute : " << i.getLevelExe() << std::endl << std::endl;
	return o;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardon destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:23:15 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 14:41:23 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "Default RobotomyForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyForm with target Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
	std::cout << "RobotomyForm copy Constructor called" << std::endl;
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
	if (this != &a)
		this->_target = a._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &exe) const
{
	try
	{
		this->check_exec(exe);
		std::cout << "Makes some drilling noises !!!" << std::endl;
		std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
		std::cout << exe.getName() << " executed " << this->getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i)
{
	o << "| Name of form : " << i.getName() << " | level to sign : " << i.getLevelSign() << " | level to execute : " << i.getLevelExe() << std::endl << std::endl;
	return o;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default RobotomyForm destructor called" << std::endl;
}

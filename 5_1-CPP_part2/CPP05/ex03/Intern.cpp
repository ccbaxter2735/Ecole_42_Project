/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:55:40 by terussar          #+#    #+#             */
/*   Updated: 2024/02/14 20:23:16 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
	std::cout << "Default Intern Constructor called" << std::endl;
}
Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "Default intern copy Constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &a)
{
	(void) a;
	return (*this);
}

AForm *Intern::makeForm(std::string nameForm, std::string target)
{
	std::string	tab[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int			i = 0;
	AForm		*form_created;

	while (i < 3)
	{
		if (nameForm == tab[i])
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			form_created = new RobotomyRequestForm(target);
			break;
		case 1:
			form_created = new PresidentialPardonForm(target);
			break;
		case 2:
			form_created = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << "Intern CANNOT create " << nameForm << std::endl;
			form_created = NULL;
	}
	if (form_created != NULL)
		std::cout << "Intern creates " << nameForm << std::endl;
	return (form_created);
}

Intern::~Intern( void )
{
	std::cout << "Default Intern destructor called" << std::endl;
}

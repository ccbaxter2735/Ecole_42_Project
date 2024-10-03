/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:19 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 14:42:23 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	PresidentialPardonForm form1("Nuclear strike");
	RobotomyRequestForm form2("oubliette");
	ShrubberyCreationForm form3("world tree");
	Bureaucrat manu("President Macron", 1);
	Bureaucrat toto("Thomas Lereux normal person", 100);
	
	std::cout << std::endl << "Form's tests" << std::endl;
	// ------- test manu ----------

	manu.signForm(form1);
	manu.executeForm(form1);
	std::cout << form1 << std::endl;
	manu.signForm(form2);
	manu.executeForm(form2);
	std::cout << form2 << std::endl;
	manu.signForm(form3);
	manu.executeForm(form3);
	std::cout << form3 << std::endl;
	std::cout << std::endl;
	
	// ------ test toto -----------
	toto.signForm(form1);
	toto.executeForm(form1);
	toto.signForm(form2);
	toto.executeForm(form2);
	toto.signForm(form3);
	toto.executeForm(form3);
	std::cout << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:19 by terussar          #+#    #+#             */
/*   Updated: 2024/02/14 19:58:31 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	Intern someRandomIntern;
	Intern someRandomIntern2;
	AForm* rrf;
	AForm* rrf2;
	PresidentialPardonForm form1("Nuclear strike");
	RobotomyRequestForm form2("oubliette");
	ShrubberyCreationForm form3("world tree");
	Bureaucrat manu("President Macron", 1);
	Bureaucrat toto("Thomas Lereux normal person", 100);
	
	std::cout << std::endl << "Form's tests" << std::endl;
	// ------- test manu ----------

	manu.signForm(form1);
	manu.executeForm(form1);
	manu.signForm(form2);
	manu.executeForm(form2);
	manu.signForm(form3);
	manu.executeForm(form3);
	std::cout << std::endl;
	
	// ------ test toto -----------
	toto.signForm(form1);
	toto.executeForm(form1);
	toto.signForm(form2);
	toto.executeForm(form2);
	toto.signForm(form3);
	toto.executeForm(form3);
	std::cout << std::endl;

	// ------ test intern ---------
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete (rrf);
	std::cout << std::endl;
	rrf2 = someRandomIntern2.makeForm("Ultimate form", "ailleurs");
	delete (rrf2);
	std::cout << std::endl;
	
	return (0);
}

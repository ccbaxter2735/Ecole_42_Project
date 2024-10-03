/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:24:12 by terussar          #+#    #+#             */
/*   Updated: 2024/02/13 18:17:54 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm( const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &a);
	std::string	getTarget( void ) const;
	virtual void execute(Bureaucrat const &exe) const;
	virtual ~PresidentialPardonForm();
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &form);

#endif

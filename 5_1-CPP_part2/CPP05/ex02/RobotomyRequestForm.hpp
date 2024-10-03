/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:23:26 by terussar          #+#    #+#             */
/*   Updated: 2024/02/13 18:55:45 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm( const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
	std::string	getTarget( void ) const;
	virtual void execute(Bureaucrat const &exe) const;
	virtual ~RobotomyRequestForm();
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &form);

#endif

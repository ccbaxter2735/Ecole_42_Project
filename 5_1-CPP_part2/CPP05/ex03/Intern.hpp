/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:55:51 by terussar          #+#    #+#             */
/*   Updated: 2024/02/14 19:20:01 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern
{
private:

public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &a);
	AForm *makeForm(std::string nameForm, std::string target);
	static const std::string form[];
	~Intern();
};

#endif
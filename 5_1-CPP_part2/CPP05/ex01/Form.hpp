/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:40 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 14:25:35 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	_name;
		bool				_signed;
		int					_levelSign;
		int					_levelExe;
	public:
		Form();
		Form(std::string name, int levelSign, int levelExe);
		Form(const Form &copy);
		std::string getName( void );
		int getLevelSign( void );
		int getLevelExe( void );
		void beSigned(Bureaucrat &bob);
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		~Form();
};

std::ostream &operator<<(std::ostream &o, Form &i);

#endif
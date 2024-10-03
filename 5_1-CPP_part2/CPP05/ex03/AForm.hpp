/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:40 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 11:12:12 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	_name;
		bool				_signed;
		int					_levelSign;
		int					_levelExe;
		AForm();
	public:
		AForm(std::string name, int levelSign, int levelExe);
		AForm(const AForm &copy);
		virtual AForm &operator=(AForm const &copy);
		std::string		getName( void ) const;
		int						getLevelSign( void ) const;
		int						getLevelExe( void ) const;
		bool					getSigned( void ) const;
		void					check_exec(Bureaucrat const &exe) const;
		bool					beSigned(Bureaucrat const &bob);
		void					restart_sign( void );
		virtual void	execute(Bureaucrat const &b) const = 0;
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
		class ExeFailException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		virtual ~AForm();
};
std::ostream &operator<<(std::ostream &o, AForm &i);

#endif
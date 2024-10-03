/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:55 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 09:58:09 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	protected:
		std::string _name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &a);
		std::string getName( void ) const;
		int 	getGrade( void ) const;
		void	downGrade( void );
		void	upGrade( void );
		void	signForm( Form &f );
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
		~Bureaucrat();
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);


#endif
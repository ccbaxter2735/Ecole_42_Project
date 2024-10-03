/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:32 by terussar          #+#    #+#             */
/*   Updated: 2024/02/23 17:45:34 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <stdint.h>

typedef struct s_Data
{
	int nb;
	std::string str;
} Data;

class Serializer
{
	private:
		Serializer( void );
		Serializer(const Serializer &copy);
	public:
		Serializer &operator=(const Serializer &copy);
		static uintptr_t serialize(Data* ptr); 
		// static sinon ne peux pas etre appeler sans objet dans main
		static Data *deserialize(uintptr_t raw);
		~Serializer();
};



#endif
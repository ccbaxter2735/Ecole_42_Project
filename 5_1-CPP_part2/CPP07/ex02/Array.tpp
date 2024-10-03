/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:58:35 by terussar          #+#    #+#             */
/*   Updated: 2024/03/27 21:16:04 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <class T>
Array<T>::Array( void )
{
	std::cout << "Default Constructor called" << std::endl;
	this->_size = 0;
	this->_array = NULL;
}

template <class T>
Array<T>::Array( unsigned int n )
{
	std::cout << "Default Constructor initialize parameter called" << std::endl;
	this->_size = n;
	this->_array = new T[n];
	if (this->_array == NULL)
		throw Array<T>::InvalidIndex();
}

template <class T>
Array<T>::Array( const Array<T> &copy )
{
	this->_size = copy._size;
	if (this->_size == 0)
	{
		this->_array = NULL;
		return ;
	}
	else
	{
		this->_array = new T[this->_size];
		if (this->_array == NULL)
			throw Array<T>::InvalidIndex();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = copy._array[i];
	}
	std::cout << "Copy Constructor called" << std::endl;
}

template <class T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template <class T>
Array<T>::~Array()
{
	std::cout << "Default Destructor called" << std::endl;
	if (this->_array != NULL)
		delete [] this->_array;
}

template <class T>
Array<T> & Array<T>::operator=(Array<T> const &copy)
{
	if (this != &copy)
	{
		if (this->_array)
			delete this->_array;
		this->_size = copy._size;
		if (this->_size == 0)
			this->_array = NULL;
		else
		{
			this->_array = new T[this->_size];
			if (this->_array == NULL)
				throw std::exception();
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = copy._array[i];
		}
	}
}

template <class T>
T & 			Array<T>::operator[](unsigned int n) const
{
	if (n >= this->_size)
		throw Array<T>::InvalidIndex();
	return (this->_array[n]);
}

template<class T> 
const char *Array<T>::InvalidIndex::what() const throw()
{
	return ("Invalid array size");
}

#endif

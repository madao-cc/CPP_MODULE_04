/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:11:23 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/03 15:22:35 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(std::string name) : _type(name)
{
	std::cout << GREEN << "Animal " << this->_type << " constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << GREEN << "Animal " << src._type << " copy constructor called" << RESET << std::endl;
	*this = src;
}
Animal::~Animal()
{
	std::cout << GREEN << "Animal destructor called" << RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	std::cout << GREEN << "Animal " << src._type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

std::string const	&Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal " << this->_type << " makes a sound" << std::endl;
}

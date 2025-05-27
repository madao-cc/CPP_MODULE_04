/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:11:23 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/23 20:03:36 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown")
{
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
	std::cout << GREEN << "Animal " << this->type << " constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << GREEN << "Animal " << src.type << " copy constructor called" << RESET << std::endl;
	*this = src; // This is were the deep copy is done
	// this->type = src.type; // This is a shallow copy
}
Animal::~Animal()
{
	std::cout << GREEN << "Animal destructor called" << RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	std::cout << GREEN << "Animal " << src.type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

std::string const	&Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal " << this->type << " makes a sound" << std::endl;
}

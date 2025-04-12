/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:41:35 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/03 16:05:11 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unknown_but_Wrong")
{
	std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : _type(name)
{
	std::cout << GREEN << "WrongAnimal " << this->_type << " constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << GREEN << "WrongAnimal " << src._type << " copy constructor called" << RESET << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << GREEN << "WrongAnimal " << src._type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

std::string const	&WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << this->_type << " makes a sound" << std::endl;
}
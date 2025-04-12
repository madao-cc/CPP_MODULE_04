/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:11:23 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/03 15:22:35 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Unknown")
{
	std::cout << GREEN << "AAnimal default constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(std::string name) : _type(name)
{
	std::cout << GREEN << "AAnimal " << this->_type << " constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << GREEN << "AAnimal " << src._type << " copy constructor called" << RESET << std::endl;
	*this = src;
}
AAnimal::~AAnimal()
{
	std::cout << GREEN << "AAnimal destructor called" << RESET << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &src)
{
	std::cout << GREEN << "AAnimal " << src._type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

std::string const	&AAnimal::getType() const
{
	return (this->_type);
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal " << this->_type << " makes a sound" << std::endl;
}

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

AAnimal::AAnimal() : type("Unknown")
{
	std::cout << GREEN << "AAnimal default constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(std::string name) : type(name)
{
	std::cout << GREEN << "AAnimal " << this->type << " constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << GREEN << "AAnimal " << src.type << " copy constructor called" << RESET << std::endl;
	*this = src;
}
AAnimal::~AAnimal()
{
	std::cout << GREEN << "AAnimal destructor called" << RESET << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &src)
{
	std::cout << GREEN << "AAnimal " << src.type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

std::string const	&AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal " << this->type << " makes a sound" << std::endl;
}

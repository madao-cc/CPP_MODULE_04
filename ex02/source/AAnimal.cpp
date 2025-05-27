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

AAnimal::AAnimal() : type("Animal")
{
	std::cout << GREEN << "AAnimal constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << GREEN << "AAnimal copy constructor called" << RESET << std::endl;
	*this = src;
}
AAnimal::~AAnimal()
{
	std::cout << GREEN << "AAnimal destructor called" << RESET << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &src)
{
	std::cout << GREEN << "AAnimal assignation operator called" << RESET << std::endl;
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
	std::cout << "AAnimal makes an animal's generic sound" << std::endl;
}

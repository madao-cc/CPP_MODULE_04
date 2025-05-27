/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:41:35 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:38:36 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Animal_but_Wrong")
{
	std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << GREEN << "WrongAnimal copy constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	std::cout << GREEN << "WrongAnimal assignation operator called" << RESET << std::endl;
	return (*this);
}

std::string const	&WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a sound" << std::endl;
}
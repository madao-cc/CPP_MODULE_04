/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:21:34 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:38:06 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << BLUE << "Dog constructor called" << RESET << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src) : Animal()
{
	*this = src;
	std::cout << BLUE << "Dog copy constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog destructor called" << RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	std::cout << BLUE << "Dog assignation operator called" << RESET << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "Dog says: Woof!" << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:21:34 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/20 16:46:08 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
	this->type = "Dog";
}

Dog::Dog(std::string name) : Animal()
{
	this->type = name;
	std::cout << BLUE << "Dog " << this->type << " constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
	std::cout << BLUE << "Dog " << src.type << " copy constructor called" << RESET << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog destructor called" << RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << BLUE << "Dog " << src.type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "Dog " << this->type << " says: Woof!" << RESET << std::endl;
}

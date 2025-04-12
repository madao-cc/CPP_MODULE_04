/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:21:34 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/02 14:36:06 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
	this->_type = "Dog";
}

Dog::Dog(std::string name) : Animal()
{
	this->_type = name;
	std::cout << BLUE << "Dog " << this->_type << " constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
	std::cout << BLUE << "Dog " << src._type << " copy constructor called" << RESET << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << BLUE << "Dog destructor called" << RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << BLUE << "Dog " << src._type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "Dog " << this->_type << " says: Woof!" << RESET << std::endl;
}

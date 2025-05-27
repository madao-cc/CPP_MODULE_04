/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:15 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/20 16:46:08 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;
	this->type = "Cat";
}

Cat::Cat(std::string name) : Animal()
{
	this->type = name;
	std::cout << YELLOW << "Cat " << this->type << " constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat &src) : Animal()
{
	std::cout << YELLOW << "Cat " << src.type << " copy constructor called" << RESET << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << YELLOW << "Cat " << src.type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << YELLOW << "Cat " << this->type << " says: Meow!" << RESET << std::endl;
}

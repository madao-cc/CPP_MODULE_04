/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:15 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:37:08 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << YELLOW << "Cat constructor called" << RESET << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal()
{
	*this = src;
	std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	std::cout << YELLOW << "Cat assignation operator called" << RESET << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << YELLOW << "Cat says: Meow!" << RESET << std::endl;
}

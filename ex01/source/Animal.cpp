/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:11:23 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:46:49 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
}


Animal::Animal(const Animal &src)
{
	*this = src; // This is where the deep copy is done
	// this->type = src.type; // This is a shallow copy
	std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
}
Animal::~Animal()
{
	std::cout << GREEN << "Animal destructor called" << RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	std::cout << GREEN << "Animal assignation operator called" << RESET << std::endl;
	return (*this);
}

std::string const	&Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes an animal's generic sound" << std::endl;
}

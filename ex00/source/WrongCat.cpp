/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:45:46 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/20 16:46:08 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Unknown_Cat_but_Wrong")
{
	std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name)
{
	std::cout << GREEN << "WrongCat " << this->type << " constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << GREEN << "WrongCat " << src.type << " copy constructor called" << RESET << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << GREEN << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	std::cout << GREEN << "WrongCat " << src.type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat " << this->type << " says: mEOoUWe! 🥴" << std::endl;
}
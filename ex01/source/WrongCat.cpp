/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:45:46 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:41:57 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "Cat_but_Wrong";
	std::cout << GREEN << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	*this = src;
	std::cout << GREEN << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << GREEN << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	std::cout << GREEN << "WrongCat assignation operator called" << RESET << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat says: mEOoUWe! 🥴" << std::endl;
}
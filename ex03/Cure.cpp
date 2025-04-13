/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:36:04 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 19:14:56 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
	this->_type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	this->_type = "cure"; // Could be: this->_type = src._type; but for safety we force it to "cure"
	*this = src;
	return ;
}

Cure &Cure::operator=(const Cure &src)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

AMateria *Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	return new Cure(*this);
	// From the code in the Github
	// return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}

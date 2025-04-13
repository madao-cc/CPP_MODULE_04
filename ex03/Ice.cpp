/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:56:29 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 19:14:34 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Ice::Ice()
{
	this->_type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
	this->_type = "ice"; // Could be: this->_type = src._type; but for safety we force it to "ice"
	*this = src;
	return ;
}

Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

AMateria *Ice::clone() const
{
	std::cout << "Ice clone called" << std::endl;
	return new Ice(*this);
	// From the code in the Github
	// return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:05:09 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 16:12:47 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(const AMateria & src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
	return ;
}

AMateria &AMateria::operator=(const AMateria & src)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria parameter constructor called" << std::endl;
	return ;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Throw nothing to " << target.getName() << std::endl;
}

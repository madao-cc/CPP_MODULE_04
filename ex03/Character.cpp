/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:14:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 16:32:18 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->_name = "Default";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
	return ;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character parameter constructor called for " << this->_name << std::endl;
	return ;
}

Character::Character(const Character & src)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	*this = src;
	return ;
}

Character &Character::operator=(const Character & src)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called for " << this->_name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		// This was the piece of code from the github page
		// if (array[i] != NULL)
		//	delete array[i];
	}
	return ;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << this->_name << " equipped " << materia->getType() << std::endl;
			break;
		}
		// This was the piece of code from the github page
		// if (array[i] == nullptr)
		// {
		// 	array[i] = materia;
		//	break;
	}
	return ;
}

void Character::unequip(int index)
{
	if (index < 0 || index > 3)
		return ;
	if (this->_inventory[index])
	{
		std::cout << this->_name << " unequipped " << this->_inventory[index]->getType() << std::endl;
		this->_inventory[index] = NULL;
	}
	return ;
}

void Character::use(int index, ICharacter& target)
{
	if (index < 0 || index > 3)
		return ;
	if (this->_inventory[index])
	{
		std::cout << this->_name << " used " << this->_inventory[index]->getType() << " on " << target.getName() << std::endl;
		this->_inventory[index]->use(target);
	}
	return ;
}
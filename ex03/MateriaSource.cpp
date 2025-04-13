/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:57:49 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 19:03:25 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
	return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			if (src._materia[i])
				this->_materia[i] = src._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
	return ;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = materia->clone();
			std::cout << "MateriaSource learned " << materia->getType() << " materia" << std::endl;
			return ;
		}
		// From the code in the Github
		// if(array[i] == nullptr)
		// {
		// 	array[i] = materia;
		//	break;
		// }
	}
	std::cout << "MateriaSource can't learn more materia" << std::endl;
	return ;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
		{
			std::cout << "MateriaSource created " << type << " materia" << std::endl;
			return this->_materia[i]->clone();
		}
	}
	std::cout << "MateriaSource can't create " << type << " materia" << std::endl;
	return NULL;
}
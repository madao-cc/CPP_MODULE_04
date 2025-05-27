/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:53:01 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/22 16:03:33 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << GREEN << "Brain destructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << GREEN << "Brain assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << RED << "Index out of range" << RESET << std::endl;
		return ("");
	}
	return (this->ideas[index]);
}

/* std::string const &Brain::getIdeaAdress(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << RED << "Index out of range" << RESET << std::endl;
		return ("");
	}
	return (this->ideas[index]);
} */

void Brain::setIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100)
	{
		std::cout << RED << "Index out of range" << RESET << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

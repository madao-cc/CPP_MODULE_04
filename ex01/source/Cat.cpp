/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:15 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:48:38 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << YELLOW << "Cat constructor called" << RESET << std::endl;
	this->type = "Cat";
	this->_idea = new Brain();
	if (!this->_idea)
	{
		std::cout << RED << "Cat Brain allocation failed" << RESET << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &src) : Animal()
{
	std::cout << YELLOW << "Cat copy constructor called" << RESET << std::endl;
	this->_idea = new Brain(*src._idea); // Deep copy of Brain
	if (!this->_idea)
	{
		std::cerr << RED << "Cat Brain allocation failed" << RESET << std::endl;
		exit(1);
	}
	this->type = src.type;
}

Cat::~Cat()
{
	delete this->_idea;
	std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << YELLOW << "Cat assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->type = src.type;
		if (this->_idea)
			delete this->_idea;
		this->_idea = new Brain(*src._idea); // Deep copy of Brain
		if (!this->_idea)
		{
			std::cout << RED << "Cat Brain allocation failed" << RESET << std::endl;
			exit(1);
		}
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << YELLOW << "Cat says: Meow!" << RESET << std::endl;
}

void	Cat::getIdea(int index) const
{
    if (this->_idea)
    {
        if (index < 0 || index >= 100)
        {
            std::cout << RED << "Index out of range" << RESET << std::endl;
            return;
        }
        if (!this->_idea->getIdea(index).empty())
            std::cout << "Idea " << index << ": " << this->_idea->getIdea(index) << std::endl;
        else
            std::cout << "Idea " << index << " is empty." << std::endl;
    }
    else
    {
        std::cout << RED << "No Brain found for this Cat!" << RESET << std::endl;
    }
}

void	Cat::getIdeas() const
{
	if (this->_idea)
	{
		for (int i = 0; i < 100; i++)
		{
			if (!this->_idea->getIdea(i).empty()) // Only print non-empty ideas
				this->getIdea(i);
		}
	}
	else
	{
		std::cout << RED << "No Brain found for this Cat!" << RESET << std::endl;
	}
}

void	Cat::setIdea(int index, std::string idea)
{
	if (this->_idea)
		this->_idea->setIdea(index, idea);
}
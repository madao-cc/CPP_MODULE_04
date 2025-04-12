/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:15 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/09 14:59:27 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << YELLOW << "Cat default constructor called" << RESET << std::endl;
	this->_type = "Cat";
	this->_idea = new Brain();
	if (!this->_idea)
	{
		std::cout << RED << "Cat Brain allocation failed" << RESET << std::endl;
		exit(1);
	}
}

Cat::Cat(std::string name) : AAnimal()
{
	this->_type = name;
	std::cout << YELLOW << "Cat " << this->_type << " constructor called" << RESET << std::endl;
	this->_idea = new Brain();
	if (!this->_idea)
	{
		std::cout << RED << "Cat Brain allocation failed" << RESET << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &src) : AAnimal()
{
	std::cout << YELLOW << "Cat " << src._type << " copy constructor called" << RESET << std::endl;
	this->_idea = new Brain(*src._idea); // Deep copy of Brain
	if (!this->_idea)
	{
		std::cerr << RED << "Cat Brain allocation failed" << RESET << std::endl;
		exit(1);
	}
	this->_type = src._type;
}

Cat::~Cat()
{
	delete this->_idea;
	std::cout << YELLOW << "Cat destructor called" << RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &src)
{
	std::cout << YELLOW << "Cat " << src._type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
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
	std::cout << YELLOW << "Cat " << this->_type << " says: Meow!" << RESET << std::endl;
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
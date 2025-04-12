/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:21:34 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/09 14:59:27 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
	this->_type = "Dog";
	this->_idea = new Brain();
	if (!this->_idea)
	{
		std::cout << RED << "Dog Brain allocation failed" << RESET << std::endl;
		exit(1);
	}
}

Dog::Dog(std::string name) : AAnimal()
{
	this->_type = name;
	std::cout << BLUE << "Dog " << this->_type << " constructor called" << RESET << std::endl;
	this->_idea = new Brain();
	if (!this->_idea)
	{
		std::cout << RED << "Dog Brain allocation failed" << RESET << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &src) : AAnimal()
{
	std::cout << BLUE << "Dog " << src._type << " copy constructor called" << RESET << std::endl;
	this->_idea = new Brain(*src._idea); // Deep copy of Brain
	if (!this->_idea)
	{
		std::cerr << RED << "Dog Brain allocation failed" << RESET << std::endl;
		exit(1);
	}
	this->_type = src._type;
}

Dog::~Dog()
{
	delete this->_idea;
	std::cout << BLUE << "Dog destructor called" << RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &src)
{
	std::cout << BLUE << "Dog " << src._type << " assignation operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_idea)
			delete this->_idea;
		this->_idea = new Brain(*src._idea); // Deep copy of Brain
		if (!this->_idea)
		{
			std::cout << RED << "Dog Brain allocation failed" << RESET << std::endl;
			exit(1);
		}
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "Dog " << this->_type << " says: Woof!" << RESET << std::endl;
}

void	Dog::getIdea(int index) const
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
		std::cout << RED << "No Brain found for this Dog!" << RESET << std::endl;
	}
}

void	Dog::getIdeas() const
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
		std::cout << RED << "No Brain found for this Dog!" << RESET << std::endl;
	}
}

void	Dog::setIdea(int index, std::string idea)
{
	if (this->_idea)
		this->_idea->setIdea(index, idea);
}	
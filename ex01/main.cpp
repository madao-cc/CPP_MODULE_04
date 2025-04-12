/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:22:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/09 14:27:17 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << MAGENTA << "=== Testing Deep Copy ===" << RESET << std::endl;

	// Create a Dog and set some ideas
	Dog* dog1 = new Dog();
	dog1->setIdea(0, "I want to play!");
	dog1->setIdea(1, "I need food!");
	dog1->setIdea(2, "I love my owner!");

	// Create a copy of the Dog
	Dog* dog2 = new Dog(*dog1);

	// Modify the original Dog's ideas
	dog1->setIdea(0, "I want to sleep!");
	dog1->setIdea(1, "I need a walk!");
	dog1->setIdea(2, "I love chasing squirrels!");
	dog1->setIdea(3, "I want to bark!");
	dog1->setIdea(4, "I need to dig!");

	// Print ideas from both Dogs
	std::cout << CYAN << "Dog 1 Ideas:" << RESET << std::endl;
	dog1->getIdeas();

	std::cout << CYAN << "Dog 2 Ideas (should remain unchanged):" << RESET << std::endl;
	dog2->getIdeas();

	delete dog1;
	delete dog2;

	std::cout << std::endl;

	// Create a Cat and set some ideas
	Cat* cat1 = new Cat();
	cat1->setIdea(0, "I want to climb!");
	cat1->setIdea(1, "I need a nap!");
	cat1->setIdea(2, "I love scratching furniture!");
	cat1->setIdea(3, "I want to chase a laser pointer!");
	cat1->setIdea(4, "I need to groom myself!");

	// Create a copy of the Cat
	Cat* cat2 = new Cat(*cat1);

	// Modify the original Cat's ideas
	cat1->setIdea(0, "I want to chase a mouse!");

	// Print ideas from both Cats
	std::cout << CYAN << "Cat 1 Ideas:" << RESET << std::endl;
	cat1->getIdeas();

	std::cout << CYAN << "Cat 2 Ideas (should remain unchanged):" << RESET << std::endl;
	cat2->getIdeas();

	delete cat1;
	delete cat2;

	std::cout << std::endl;
	
	std::cout << MAGENTA << "=== End of Tests ===" << RESET << std::endl;

	return 0;
}
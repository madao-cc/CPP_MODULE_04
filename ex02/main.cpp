/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:22:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/09 15:22:56 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << MAGENTA << "=== Testing Polymorphism with AAnimal pointers ===" << RESET << std::endl;

	// Create an array of AAnimal pointers that hold concrete objects.
	const int numAnimals = 4;
	AAnimal* animals[numAnimals];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	// Loop through the array, print type and call makeSound()
	for (int i = 0; i < numAnimals; i++)
	{
		std::cout << animals[i]->getType() << " makes sound: ";
		animals[i]->makeSound();
	}

	// Free memory from the polymorphic array
	for (int i = 0; i < numAnimals; i++)
	{
		delete animals[i];
	}

	std::cout << std::endl;
    
	// -----------------------------
	// Test deep copy functionality for Dog
	// -----------------------------
	std::cout << MAGENTA << "=== Testing Deep Copy for Dog ===" << RESET << std::endl;

	Dog* dog1 = new Dog();
	dog1->setIdea(0, "I want to play!");
	dog1->setIdea(1, "I need food!");
	dog1->setIdea(2, "I love my owner!");

	// Create a deep copy of dog1
	Dog* dog2 = new Dog(*dog1);

	// Modify dog1's ideas; dog2's ideas should remain unchanged
	dog1->setIdea(0, "I want to sleep!");
	dog1->setIdea(1, "I need a walk!");
	dog1->setIdea(2, "I love chasing squirrels!");
	dog1->setIdea(3, "I want to bark!");
	dog1->setIdea(4, "I need to dig!");

	std::cout << CYAN << "Dog 1 Ideas:" << RESET << std::endl;
	dog1->getIdeas();

	std::cout << CYAN << "Dog 2 Ideas (should remain unchanged):" << RESET << std::endl;
	dog2->getIdeas();

	delete dog1;
	delete dog2;

	std::cout << std::endl;

	// -----------------------------
	// Test deep copy functionality for Cat
	// -----------------------------
	std::cout << MAGENTA << "=== Testing Deep Copy for Cat ===" << RESET << std::endl;

	Cat* cat1 = new Cat();
	cat1->setIdea(0, "I want to climb!");
	cat1->setIdea(1, "I need a nap!");
	cat1->setIdea(2, "I love scratching furniture!");
	cat1->setIdea(3, "I want to chase a laser pointer!");
	cat1->setIdea(4, "I need to groom myself!");

	// Create a deep copy of cat1
	Cat* cat2 = new Cat(*cat1);

	// Modify cat1's ideas; cat2's ideas should remain unchanged
	cat1->setIdea(0, "I want to chase a mouse!");

	std::cout << CYAN << "Cat 1 Ideas:" << RESET << std::endl;
	cat1->getIdeas();

	std::cout << CYAN << "Cat 2 Ideas (should remain unchanged):" << RESET << std::endl;
	cat2->getIdeas();

	delete cat1;
	delete cat2;

	std::cout << MAGENTA << "=== End of Tests ===" << RESET << std::endl;
	return 0;
}

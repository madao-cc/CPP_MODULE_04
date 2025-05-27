/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:22:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:54:19 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>


int main()
{
	std::cout << MAGENTA << "=== Animal Array Test ===" << RESET << std::endl << std::endl;

	Animal* animals[10];

	// Fill half with Dogs, half with Cats
	for (int i = 0; i < 10 / 2; ++i)
	{
		animals[i] = new Dog();
	}
	for (int i = 10 / 2; i < 10; ++i)
	{
		animals[i] = new Cat();
	}

	std::cout << std::endl << MAGENTA << "=== Deep Copy Test: Dog ===" << RESET << std::endl << std::endl;
	Dog* dog1 = new Dog();
	dog1->setIdea(0, "Play fetch!");
	dog1->setIdea(1, "Eat food!");
	std::cout << CYAN << "Dog1 Ideas:" << RESET << std::endl;
	dog1->getIdeas();

	Dog* dog2 = new Dog(*dog1); // Deep copy
	std::cout << "Changing Dog1's idea[0] to 'Sleep!'" << std::endl;
	dog1->setIdea(0, "Sleep!");
	std::cout << CYAN << "Dog1 Ideas (after change):" << RESET << std::endl;
	dog1->getIdeas();
	std::cout << CYAN << "Dog2 Ideas (should be unchanged):" << RESET << std::endl;
	dog2->getIdeas();

	delete dog1;
	delete dog2;

	std::cout << std::endl << MAGENTA << "=== Deep Copy Test: Cat ===" << RESET << std::endl << std::endl;
	Cat* cat1 = new Cat();
	cat1->setIdea(0, "Climb tree!");
	cat1->setIdea(1, "Nap time!");
	std::cout << CYAN << "Cat1 Ideas:" << RESET << std::endl;
	cat1->getIdeas();

	Cat* cat2 = new Cat(*cat1); // Deep copy
	std::cout << "Changing Cat1's idea[0] to 'Chase mouse!'" << std::endl;
	cat1->setIdea(0, "Chase mouse!");
	std::cout << CYAN << "Cat1 Ideas (after change):" << RESET << std::endl;
	cat1->getIdeas();
	std::cout << CYAN << "Cat2 Ideas (should be unchanged):" << RESET << std::endl;
	cat2->getIdeas();

	delete cat1;
	delete cat2;

	std::cout << std::endl << MAGENTA << "=== Deleting Animal Array ===" << RESET << std::endl << std::endl;
	for (int i = 0; i < 10; ++i)
		delete animals[i];

	// --- Failing/Incorrect Tests Below ---

	std::cout << std::endl << RED << "=== Failing/Incorrect Tests ===" << RESET << std::endl << std::endl;

	// 1. Accessing out-of-bounds idea index (should fail or warn)
	Dog* failDog = new Dog();
	std::cout << YELLOW << "Trying to set idea at index 200 (out of bounds):" << RESET << std::endl;
	failDog->setIdea(200, "This should not work!");
	std::cout << YELLOW << "Trying to get idea at index 200 (out of bounds):" << RESET << std::endl;
	failDog->getIdea(200);

	// 2. Shallow copy test (simulate what would go wrong)
	Dog* shallowDog1 = new Dog();
	shallowDog1->setIdea(0, "Original idea");
	Dog* shallowDog2 = shallowDog1; // Shallow copy (pointer copy)
	std::cout << YELLOW << "Shallow copy: changing shallowDog1's idea to 'Changed idea'" << RESET << std::endl;
	shallowDog1->setIdea(0, "Changed idea");
	std::cout << "shallowDog2's idea (should be 'Changed idea' if shallow): ";
	shallowDog2->getIdea(0);
	delete shallowDog1;
	// delete shallowDog2; // Would cause double free if uncommented

    return 0;
}
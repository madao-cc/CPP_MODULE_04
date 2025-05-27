/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:22:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:43:33 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << MAGENTA << "=== Testing Animal, Dog, and Cat ===" << RESET << std::endl << std::endl;

	const Animal* myAnimal = new Animal();
	const Animal* myDog = new Dog();
	const Animal* myCat = new Cat();

	std::cout << CYAN << myDog->getType() << RESET << " " << std::endl;
	std::cout << YELLOW << myCat->getType() << RESET << " " << std::endl;

	myDog->makeSound(); // Should output the Cat sound
	myCat->makeSound(); // Should output the Dog sound
	myAnimal->makeSound(); // Should output the Animal sound

	delete myAnimal;
	delete myDog;
	delete myCat;

	std::cout << std::endl;

	std::cout << MAGENTA << "=== Testing ActualCat and ActualDog ===" << RESET << std::endl << std::endl;

	const Dog* actualDog = new Dog();
	const Cat* actualCat = new Cat();

	std::cout << CYAN << actualDog->getType() << RESET << " " << std::endl;
	std::cout << YELLOW << actualCat->getType() << RESET << " " << std::endl;

	actualDog->makeSound(); // Should output the Dog sound
	actualCat->makeSound(); // Should output the Cat sound

	delete actualDog;
	delete actualCat;
	
	std::cout << std::endl;
	
	std::cout << MAGENTA << "=== Testing WrongAnimal and WrongCat ===" << RESET << std::endl << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongPussy = new WrongCat();
	const WrongCat* actualWrongCat = new WrongCat();

	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << YELLOW << wrongPussy->getType() << RESET << " " << std::endl;
	std::cout << YELLOW << actualWrongCat->getType() << RESET << " " << std::endl;

	wrongAnimal->makeSound(); // Will output the WrongAnimal sound
	wrongPussy->makeSound(); // Will output the WrongAnimal sound (not the WrongCat sound)
	actualWrongCat->makeSound(); // Will output the WrongCat sound

	delete wrongAnimal;
	delete wrongPussy;
	delete actualWrongCat;

	return 0;
}

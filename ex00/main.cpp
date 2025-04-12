/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:22:08 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/03 16:29:14 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* int main()
{
	// Animal a; //? Cannot instantiate abstract class
	Animal *animal = new Animal("George");
	animal->makeSound();
	delete animal;

	Animal *dog = new Dog("Oscar");
	dog->makeSound();
	delete dog;

	Animal *cat = new Cat("Duarte");
	cat->makeSound();
	delete cat;

	return (0);
} */

int main()
{
	std::cout << MAGENTA << "=== Testing Animal, Dog, and Cat ===" << RESET << std::endl;

	const Animal* myAnimal = new Animal();
	const Animal* myDog = new Dog();
	const Animal* myCat = new Cat();

	std::cout << CYAN << myDog->getType() << RESET << " " << std::endl;
	std::cout << CYAN << myCat->getType() << RESET << " " << std::endl;

	myDog->makeSound(); // Should output the Cat sound
	myCat->makeSound(); // Should output the Dog sound
	myAnimal->makeSound(); // Should output the Animal sound

	delete myAnimal;
	delete myDog;
	delete myCat;

	std::cout << std::endl;

	std::cout << MAGENTA << "=== Testing WrongAnimal and WrongCat ===" << RESET << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongPussy = new WrongCat();

	std::cout << CYAN << wrongPussy->getType() << RESET << " " << std::endl;

	wrongPussy->makeSound(); // Will output the WrongAnimal sound (not the WrongCat sound)
	wrongAnimal->makeSound(); // Will output the WrongAnimal sound

	delete wrongAnimal;
	delete wrongPussy;

	return 0;
}

/* int main()
{
	std::cout << MAGENTA << "=== Testing Animal and Dog ===" << RESET << std::endl;

	// Create an Animal object
	const Animal *animal = new Animal();
	std::cout << CYAN << "Animal Type: " << animal->getType() << RESET << std::endl;
	animal->makeSound();
	delete animal;

	std::cout << std::endl;

	// Create a Dog object
	const Animal *dog = new Dog();
	std::cout << CYAN << "Dog Type (as Animal): " << dog->getType() << RESET << std::endl;
	dog->makeSound(); // This will call Dog's makeSound()
	delete dog;

	std::cout << std::endl;

	// Create a Dog object directly
	const Dog *actualDog = new Dog();
	std::cout << CYAN << "Dog Type: " << actualDog->getType() << RESET << std::endl;
	actualDog->makeSound(); // This will call Dog's makeSound()
	delete actualDog;
	
	std::cout << std::endl;

	std::cout << MAGENTA << "=== Testing Cat ===" << RESET << std::endl;
	// Create a Cat object
	const Animal *cat = new Cat();
	std::cout << CYAN << "Cat Type (as Animal): " << cat->getType() << RESET << std::endl;
	cat->makeSound(); // This will call Cat's makeSound()
	delete cat;

	std::cout << std::endl;

	// Create a Cat object directly
	const Cat *actualCat = new Cat();
	std::cout << CYAN << "Cat Type: " << actualCat->getType() << RESET << std::endl;
	actualCat->makeSound(); // This will call Cat's makeSound()
	delete actualCat;

	std::cout << std::endl;

	// Create a Dog object with a name
	const Dog *namedDog = new Dog("Buddy");
	std::cout << CYAN << "Named Dog Type: " << namedDog->getType() << RESET << std::endl;
	namedDog->makeSound(); // This will call Dog's makeSound()
	delete namedDog;

	std::cout << std::endl;

	// Create a Cat object with a name
	const Cat *namedCat = new Cat("Whiskers");
	std::cout << CYAN << "Named Cat Type: " << namedCat->getType() << RESET << std::endl;
	namedCat->makeSound(); // This will call Cat's makeSound()
	delete namedCat;

	std::cout << std::endl;

	// Create a Dog object using the copy constructor
	const Dog *copiedDog = new Dog(*actualDog);
	std::cout << CYAN << "Copied Dog Type: " << copiedDog->getType() << RESET << std::endl;
	copiedDog->makeSound(); // This will call Dog's makeSound()
	delete copiedDog;

	std::cout << std::endl;

	// Create a Cat object using the copy constructor
	const Cat *copiedCat = new Cat(*actualCat);
	std::cout << CYAN << "Copied Cat Type: " << copiedCat->getType() << RESET << std::endl;
	copiedCat->makeSound(); // This will call Cat's makeSound()
	delete copiedCat;

	std::cout << std::endl;

	// Create a Dog object using the assignment operator
	Dog *assignedDog = new Dog();
	*assignedDog = *actualDog;
	std::cout << CYAN << "Assigned Dog Type: " << assignedDog->getType() << RESET << std::endl;
	assignedDog->makeSound(); // This will call Dog's makeSound()
	delete assignedDog;

	std::cout << std::endl;

	// Create a Cat object using the assignment operator
	Cat *assignedCat = new Cat();
	*assignedCat = *actualCat;
	std::cout << CYAN << "Assigned Cat Type: " << assignedCat->getType() << RESET << std::endl;
	assignedCat->makeSound(); // This will call Cat's makeSound()
	delete assignedCat;

	std::cout << std::endl;

	// Create a Dog object with a name using the assignment operator
	Dog *assignedNamedDog = new Dog("Charlie");
	*assignedNamedDog = *namedDog;
	std::cout << CYAN << "Assigned Named Dog Type: " << assignedNamedDog->getType() << RESET << std::endl;
	assignedNamedDog->makeSound(); // This will call Dog's makeSound()
	delete assignedNamedDog;

	std::cout << std::endl;

	// Create a Cat object with a name using the assignment operator
	Cat *assignedNamedCat = new Cat("Mittens");
	*assignedNamedCat = *namedCat;
	std::cout << CYAN << "Assigned Named Cat Type: " << assignedNamedCat->getType() << RESET << std::endl;
	assignedNamedCat->makeSound(); // This will call Cat's makeSound()
	delete assignedNamedCat;

	std::cout << std::endl;

	std::cout << MAGENTA << "=== Testing WrongAnimal and WrongCat ===" << RESET << std::endl;

	// Create a WrongAnimal object
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	std::cout << CYAN << "WrongAnimal Type: " << wrongAnimal->getType() << RESET << std::endl;
	wrongAnimal->makeSound();
	delete wrongAnimal;

	std::cout << std::endl;

	// Create a WrongCat object
	const WrongAnimal *wrongCat = new WrongCat();
	std::cout << CYAN << "WrongCat Type (as WrongAnimal): " << wrongCat->getType() << RESET << std::endl;
	wrongCat->makeSound(); // This will call WrongAnimal's makeSound() if it's not virtual
	delete wrongCat;

	std::cout << std::endl;

	// Create a WrongCat object directly
	const WrongCat *actualWrongCat = new WrongCat();
	std::cout << CYAN << "WrongCat Type: " << actualWrongCat->getType() << RESET << std::endl;
	actualWrongCat->makeSound(); // This will call WrongCat's makeSound()
	delete actualWrongCat;

	std::cout << MAGENTA << "=== End of Tests ===" << RESET << std::endl;

	return 0;
} */
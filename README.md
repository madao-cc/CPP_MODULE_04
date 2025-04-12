# CPP Module 04 – Subtype Polymorphism, Abstract Classes, and Interfaces

In this module, we advance our object‐oriented programming skills in C++ by dealing with subtype polymorphism and designing classes that rely on abstract classes and interfaces. The exercises guide you through the following topics:

- **Exercise 00: Polymorphism** – Creating a class hierarchy for animals using virtual functions and demonstrating proper polymorphic behavior.  
- **Exercise 01: I don't want to set the world on fire** – Incorporating deep copies and dynamic memory management by adding a Brain to derived classes.  
- **Exercise 02: Abstract class** – Preventing direct instantiation of the base class by making it abstract.  
- **Exercise 03: Interface & recap** – Implementing interfaces via pure abstract classes (for example, with Materia and Character classes) to simulate polymorphic behavior in a flexible manner.

*(Reference: citeturn5file0)*

---

## Table of Contents

- [Introduction & Overview](#introduction--overview)
- [Key Concepts](#key-concepts)
- [Exercise 00: Polymorphism](#exercise-00-polymorphism)
- [Exercise 01: I don't want to set the world on fire](#exercise-01-i-dont-want-to-set-the-world-on-fire)
- [Exercise 02: Abstract class](#exercise-02-abstract-class)
- [Exercise 03: Interface & recap](#exercise-03-interface--recap)

---

## Introduction & Overview

This module focuses on advanced polymorphism in C++:
- You will explore how virtual functions enable runtime polymorphism.
- You will learn to create abstract classes to serve as base types that cannot be instantiated.
- You will design interfaces (using pure abstract classes) to specify contracts for concrete classes.

By the end of this module, you’ll be able to build flexible, extensible designs where objects can be manipulated using base-class pointers or references with the assurance that the correct derived behavior is invoked.

---

## Key Concepts

### Subtype Polymorphism  
Subtype polymorphism allows base-class pointers or references to refer to objects of derived classes. It is achieved in C++ using virtual functions. Virtual functions ensure that when you call a method through a base-class pointer, the derived class's override is executed.

### Abstract Classes  
An abstract class is a class that contains at least one pure virtual function. They cannot be instantiated directly, and they define an interface that derived classes must implement. This forces the concrete subclasses to provide the actual implementations for the abstract behaviors.

### Interfaces in C++ (via Pure Abstract Classes)  
Even though C++98 does not have the keyword “interface,” you can simulate one by declaring a class that contains only pure virtual functions. This approach is widely used to define contracts for classes without dictating how these contracts are fulfilled.

### Deep Copy and Resource Management  
When a class manages dynamic memory (e.g., allocating a Brain for animals), copying must ensure that the new object gets its own copy of the data. A deep copy prevents two objects from sharing the same dynamically allocated memory.

---

## Exercise 00: Polymorphism

### Objective

Implement a simple base class called `Animal` with a protected string attribute `type`. Then, derive two classes – `Dog` and `Cat` – that set their `type` to "Dog" and "Cat", respectively, and override the `makeSound()` function to output an appropriate sound. Also, implement `WrongAnimal` and `WrongCat` to show what happens when virtual functions are not used.

### Code Examples

**Animal.hpp**
```cpp
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;
public:
    Animal() : type("Animal") {
        std::cout << "Animal created" << std::endl;
    }
    virtual ~Animal() {
        std::cout << "Animal destroyed" << std::endl;
    }
    virtual void makeSound() const {
        std::cout << "Animal sound" << std::endl;
    }
    std::string getType() const { return type; }
};

#endif
```

**Dog.hpp**
```cpp
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog() {
        type = "Dog";
        std::cout << "Dog created" << std::endl;
    }
    virtual ~Dog() {
        std::cout << "Dog destroyed" << std::endl;
    }
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

#endif
```

**Cat.hpp**
```cpp
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat() {
        type = "Cat";
        std::cout << "Cat created" << std::endl;
    }
    virtual ~Cat() {
        std::cout << "Cat destroyed" << std::endl;
    }
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

#endif
```

**WrongAnimal.hpp**
```cpp
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal() : type("WrongAnimal") {
        std::cout << "WrongAnimal created" << std::endl;
    }
    ~WrongAnimal() {
        std::cout << "WrongAnimal destroyed" << std::endl;
    }
    void makeSound() const {
        std::cout << "WrongAnimal sound" << std::endl;
    }
    std::string getType() const { return type; }
};

#endif
```

**WrongCat.hpp**
```cpp
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat() {
        type = "WrongCat";
        std::cout << "WrongCat created" << std::endl;
    }
    ~WrongCat() {
        std::cout << "WrongCat destroyed" << std::endl;
    }
    // Note: Not overriding with virtual; hence, when called through WrongAnimal pointer, the base method is used.
    void makeSound() const {
        std::cout << "Meow? (Wrong sound)" << std::endl;
    }
};

#endif
```

### Explanation

- **Virtual Functions:** In the correct hierarchy, the use of `virtual` in `makeSound()` guarantees that `Dog` and `Cat` output their own sounds even when accessed via an `Animal*`.  
- **Absence of Virtual:** In the `WrongAnimal`/`WrongCat` example, if you call `makeSound()` on a `WrongAnimal*` pointing to a `WrongCat`, it calls the base version, demonstrating the importance of virtual functions.

---

## Exercise 01: I don't want to set the world on fire

### Objective

Add a `Brain` class to represent the ideas of animals. The `Dog` and `Cat` classes should now have a private pointer to a `Brain`. This exercise emphasizes dynamic memory allocation, deep copying, and ensuring proper deletion to avoid memory leaks.

### Code Examples

**Brain.hpp**
```cpp
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif
```

**Brain.cpp**
```cpp
#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    return (index >= 0 && index < 100) ? ideas[index] : "";
}
```

**Updated Dog.hpp (with Brain)**
```cpp
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;
public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();

    void makeSound() const override;
    void setBrainIdea(int index, const std::string &idea);
    std::string getBrainIdea(int index) const;
};

#endif
```

**Dog.cpp (with deep copy)**
```cpp
#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog with Brain created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;  // Deep copy of brain
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setBrainIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
    return brain->getIdea(index);
}
```

*A similar implementation should be applied to the `Cat` class.*

### Explanation

- **Dynamic Allocation:** Each `Dog` or `Cat` creates its own `Brain` dynamically.
- **Deep Copy:** Copy constructor and assignment operator ensure that the brain is copied deeply (i.e., each animal has its own copy of ideas).
- **Resource Management:** The destructor deletes the dynamically allocated `Brain` to avoid memory leaks.

---

## Exercise 02: Abstract Class

### Objective

Make the `Animal` class abstract so that it cannot be instantiated directly. This is done by turning at least one member function (e.g., `makeSound()`) into a pure virtual function.

### Code Examples

**Animal.hpp (modified to be abstract)**
```cpp
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;
public:
    Animal() : type("Animal") {
        std::cout << "Animal created" << std::endl;
    }
    virtual ~Animal() {
        std::cout << "Animal destroyed" << std::endl;
    }
    virtual void makeSound() const = 0; // Pure virtual function
    std::string getType() const { return type; }
};

#endif
```

### Explanation

- **Pure Virtual Function:** The declaration of `makeSound() = 0;` makes `Animal` abstract. This prevents the creation of generic Animal objects while enforcing that all derived classes implement their own version of `makeSound()`.

---

## Exercise 03: Interface & Recap

### Objective

Implement interfaces using pure abstract classes. In this exercise, you will create an abstract base class for Materia (`AMateria`) along with concrete classes (`Ice` and `Cure`). You will also implement the interfaces for characters using an interface class (`ICharacter`) and a source for Materia (`IMateriaSource`).

### Code Examples

**AMateria.hpp**
```cpp
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"  // Forward declaration for ICharacter

class AMateria {
protected:
    std::string type;
public:
    AMateria(const std::string &type);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif
```

**AMateria.cpp**
```cpp
#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter &target) {
    std::cout << "Using materia on " << target.getName() << std::endl;
}
```

**Ice.hpp**
```cpp
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    virtual ~Ice();

    virtual AMateria* clone() const;
    virtual void use(ICharacter &target);
};

#endif
```

**Ice.cpp**
```cpp
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
```

**Cure.hpp**
```cpp
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    virtual ~Cure();

    virtual AMateria* clone() const;
    virtual void use(ICharacter &target);
};

#endif
```

**Cure.cpp**
```cpp
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
```

**ICharacter.hpp (Interface)**
```cpp
#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include "AMateria.hpp"

class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif
```

**Character.hpp (Concrete Implementation)**
```cpp
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];
public:
    Character(const std::string &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    virtual ~Character();

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
```

*Implement the Character methods in a corresponding Character.cpp ensuring deep copies of equipped Materias.*

**IMateriaSource.hpp (Interface)**
```cpp
#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(const std::string &type) = 0;
};

#endif
```

**MateriaSource.hpp (Concrete Implementation)**
```cpp
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* learned[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource &operator=(const MateriaSource &other);
    virtual ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(const std::string &type);
};

#endif
```

### Explanation

- **Interfaces via Pure Abstract Classes:**  
  `ICharacter` and `IMateriaSource` serve as interfaces. They declare methods that must be implemented in concrete classes such as `Character` and `MateriaSource`.  
- **Polymorphic Cloning:**  
  The `clone()` method in `AMateria` is pure virtual, forcing derived classes (i.e., `Ice` and `Cure`) to implement cloning. This is crucial for creating new instances based solely on type information.
- **Usage Pattern:**  
  A typical main function will create a MateriaSource, learn Materias, create Materias from it, equip a Character, and then use them on a target character.

Example main usage:
```cpp
int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return 0;
}
```

When run, the program should output:
```
* shoots an ice bolt at bob *
* heals bob's wounds *
```

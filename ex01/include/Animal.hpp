/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:25:07 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:44:37 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"


class	Animal
{
	protected:
		std::string type;
	public:
		// Constructors
		Animal();
		// Copy Constructor
		Animal(const Animal &src);
		// Destructor
		virtual ~Animal();
		
		//~Animal(); //? See why?
		
		// Assignation Operator
		Animal	&operator=(const Animal &src);
		// Getters
		std::string const	&getType() const;
		// Member functions
		virtual void	makeSound() const;
		// virtual void	makeSound() const;		
};

#endif

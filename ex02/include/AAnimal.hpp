/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:25:07 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/09 14:55:25 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

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

class	AAnimal
{
	protected:
		std::string type;
	public:
		// Constructors
		AAnimal();
		AAnimal(std::string name);
		// Copy Constructor
		AAnimal(const AAnimal &src);
		// Destructor
		virtual ~AAnimal();
		
		//~AAnimal(); //? See why?
		
		// Assignation Operator
		AAnimal	&operator=(const AAnimal &src);
		// Getters
		std::string const	&getType() const;
		// Member functions
		virtual void	makeSound() const = 0; // Pure virtual function to make AAnimal an abstract class
		// virtual void	makeSound() const;		
};

#endif

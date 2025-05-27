/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:10:28 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/02 14:15:49 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
	private:
	
	public:
		// Constructors
		Dog();
		Dog(std::string name);
		// Copy Constructor
		Dog(const Dog &src);
		// Destructor
		~Dog();
		// Assignation Operator
		Dog	&operator=(const Dog &src);
		// Member functions
		void	makeSound() const;
};

#endif
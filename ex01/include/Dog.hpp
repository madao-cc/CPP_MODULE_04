/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:10:28 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:44:43 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain	*_idea;
	public:
		// Constructors
		Dog();
		// Copy Constructor
		Dog(const Dog &src);
		// Destructor
		~Dog();
		// Assignation Operator
		Dog	&operator=(const Dog &src);
		// Member functions
		void	makeSound() const;
		// Getters
		void	getIdea(int index) const;
		void	getIdeas() const;
		// Setters
		void	setIdea(int index, std::string idea);
};

#endif
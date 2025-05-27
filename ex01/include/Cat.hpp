/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:05:34 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:44:40 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class	Cat : public Animal
{
	private:
		Brain	*_idea;
	public:
		// Constructors
		Cat();
		// Copy Constructor
		Cat(const Cat &src);
		// Destructor
		~Cat();
		// Assignation Operator
		Cat	&operator=(const Cat &src);
		// Member functions
		void	makeSound() const;
		// Getters
		void	getIdea(int index) const;
		void	getIdeas() const;
		// Setters
		void	setIdea(int index, std::string idea);
};

#endif
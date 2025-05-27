/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:05:34 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:31:52 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	private:
	
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
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:30:22 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/03 15:42:29 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class	WrongAnimal
{
	protected:
		std::string	_type;
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(std::string name);
		// Copy constructor
		WrongAnimal(const WrongAnimal &src);
		// Destructor
		~WrongAnimal();
		// Assignment operator
		WrongAnimal	&operator=(const WrongAnimal &src);
		// Getters
		std::string const	&getType() const;
		// Member functions
		void	makeSound() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:35:48 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/03 15:36:28 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		// Constructors
		WrongCat();
		WrongCat(std::string name);
		// Copy constructor
		WrongCat(const WrongCat &src);
		// Destructor
		~WrongCat();
		// Assignment operator
		WrongCat &operator=(const WrongCat &src);
		void	makeSound() const;
};

#endif
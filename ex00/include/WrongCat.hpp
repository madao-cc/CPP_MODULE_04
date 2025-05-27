/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:35:48 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/27 09:31:59 by madao-da         ###   ########.fr       */
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
		// Copy constructor
		WrongCat(const WrongCat &src);
		// Destructor
		~WrongCat();
		// Assignment operator
		WrongCat &operator=(const WrongCat &src);
		void	makeSound() const;
};

#endif
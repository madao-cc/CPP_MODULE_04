/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:52:30 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 15:56:00 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:
	
	public:
		Cure();
		Cure(const Cure &src);
		Cure &operator=(const Cure &src);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter&target);
};

#endif
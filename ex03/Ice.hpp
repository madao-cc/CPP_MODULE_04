/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:58:55 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 16:00:54 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice();
		Ice(const Ice &src);
		Ice &operator=(const Ice &src);
		~Ice();
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
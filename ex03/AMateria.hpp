/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:45:29 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 18:56:10 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(const AMateria & src);
		AMateria(std::string const & type);
		AMateria & operator=(const AMateria & src);
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		virtual	AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
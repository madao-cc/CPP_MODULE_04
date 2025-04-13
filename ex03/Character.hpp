/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:04:20 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/04/13 15:51:24 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		AMateria* _inventory[4];
		std::string _name;
	public:
		Character();
		Character(const Character & src);
		Character(std::string name);
		Character &operator=(const Character & src);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* materia);
		void unequip(int index);
		void use(int index, ICharacter& target);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:50:38 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/22 16:03:33 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class Brain
{
	private:
		std::string	ideas[100];
	public:
		// Constructors
		Brain();
		// Copy Constructor
		Brain(const Brain &src);
		// Destructor
		virtual	~Brain();
		// Assignation Operator
		Brain &operator=(const Brain &src);
		// Getters
		std::string getIdea(int index) const;
		// const std::string	&getIdeaAdress(int index) const;
		// Setters
		void	setIdea(int index, std::string idea);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:47:08 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 18:20:54 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_ideas;
public:
	Dog(void);
	Dog(std::string const ideas[]);
	Dog(std::string const &type, std::string const ideas[]);
	Dog(Dog const &other);
	~Dog(void);
	Dog	&operator=(Dog const &other);
public:
	void	makeSound(void) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:53:15 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 16:51:00 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called." << std::endl;
}

Cure	&Cure::operator=(Cure const &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}

	std::cout << "Cure copy assignment operator called." << std::endl;
	return (*this);
}

Cure	*Cure::clone(void)
{
	std::cout << "Cure clone method called." << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter &type)
{
	std::cout << "Cure: * heals" << type.getName() << "’s wounds *" << std::endl;
}

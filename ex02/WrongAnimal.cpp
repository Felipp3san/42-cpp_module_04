/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:06:56 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 23:17:11 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("Animal")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{
	std::cout << "WrongAnimal parameterized constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
	{
		_type = other._type;
	}

	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "** [wrong animal] no sound... **" << std::endl;
}

std::string	const &WrongAnimal::getType(void) const
{
	return (_type);
}

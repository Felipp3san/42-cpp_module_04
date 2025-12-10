/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:46:39 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 23:08:45 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string const &type) : _type(type)
{
	std::cout << "Animal parameterized constructor called." << std::endl;
}

Animal::Animal(Animal const &other) : _type(other._type)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal	&Animal::operator=(Animal const &other)
{
	if (this != &other)
	{
		_type = other._type;
	}

	std::cout << "Animal copy assignment operator called." << std::endl;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "** no sound **" << std::endl;
}

std::string	const &Animal::getType(void) const
{
	return (_type);
}

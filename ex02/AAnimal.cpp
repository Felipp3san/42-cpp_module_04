/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:46:39 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 20:07:44 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string const &type) : _type(type)
{
	std::cout << "Animal parameterized constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) : _type(other._type)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called." << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &other)
{
	if (this != &other)
	{
		_type = other._type;
	}

	std::cout << "Animal copy assignment operator called." << std::endl;
	return (*this);
}

std::string	const &AAnimal::getType(void) const
{
	return (_type);
}

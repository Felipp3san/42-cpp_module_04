/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 23:09:17 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 23:13:51 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(std::string const &type) : WrongAnimal(type)
{
	std::cout << "WrongCat parameterized constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}

	std::cout << "WrongCat copy assignment operator called." << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

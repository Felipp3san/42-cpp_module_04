/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:46:50 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 23:25:07 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(std::string const &type) : Animal(type)
{
	std::cout << "Cat parameterized constructor called." << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat	&Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}

	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

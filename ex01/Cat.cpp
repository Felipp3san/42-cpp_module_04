/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:46:50 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 18:21:31 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) :
	Animal("Cat"),
	_ideas(new Brain())
{
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(std::string const ideas[]) :
	Animal("Cat"),
	_ideas(new Brain(ideas))
{
	std::cout << "Dog parameterized constructor called." << std::endl;
}

Cat::Cat(std::string const &type, std::string const ideas[]) :
	Animal(type),
	_ideas(new Brain(ideas))
{
	std::cout << "Cat parameterized constructor called." << std::endl;
}

Cat::Cat(Cat const &other) :
	Animal(other),
	_ideas(new Brain(*other._ideas))
{
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void)
{
	delete _ideas;
	std::cout << "Cat destructor called." << std::endl;
}

Cat	&Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _ideas;
		_ideas = new Brain(*other._ideas);
	}

	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

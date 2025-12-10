/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:49:52 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 18:21:32 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) :
	Animal("Dog"),
	_ideas(new Brain())
{
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(std::string const ideas[]) :
	Animal("Dog"),
	_ideas(new Brain(ideas))
{
	std::cout << "Dog parameterized constructor called." << std::endl;
}

Dog::Dog(std::string const &type, std::string const ideas[]) :
	Animal(type),
	_ideas(new Brain(ideas))
{
	std::cout << "Dog parameterized constructor called." << std::endl;
}

Dog::Dog(Dog const &other) :
	Animal(other),
	_ideas(new Brain(*other._ideas))
{
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void)
{
	delete _ideas;
	std::cout << "Dog destructor called." << std::endl;
}

Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _ideas;
		_ideas = new Brain(*other._ideas);
	}

	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

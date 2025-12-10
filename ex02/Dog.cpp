/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:49:52 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 19:58:05 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) :
	AAnimal("Dog"),
	_ideas(new Brain())
{
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(std::string const ideas[]) :
	AAnimal("Dog"),
	_ideas(new Brain(ideas))
{
	std::cout << "Dog parameterized constructor called." << std::endl;
}

Dog::Dog(std::string const &type, std::string const ideas[]) :
	AAnimal(type),
	_ideas(new Brain(ideas))
{
	std::cout << "Dog parameterized constructor called." << std::endl;
}

Dog::Dog(Dog const &other) :
	AAnimal(other),
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
		AAnimal::operator=(other);
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

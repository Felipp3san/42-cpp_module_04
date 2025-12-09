/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:49:52 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 23:25:13 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(std::string const &type) : Animal(type)
{
	std::cout << "Dog parameterized constructor called." << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog	&Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}

	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

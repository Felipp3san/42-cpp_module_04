/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:43:48 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 17:46:35 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(std::string const ideas[])
{
	for (size_t i = 0; i < SIZE; i++)
	{
		_ideas[i] = ideas[i];
	}
	std::cout << "Brain parameterized constructor called." << std::endl;
}

Brain::Brain(Brain const &other)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain	&Brain::operator=(Brain const &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < SIZE; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}

	std::cout << "Brain copy assignment operator called." << std::endl;
	return (*this);
}

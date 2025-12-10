/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:55:12 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 18:23:22 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::string	const dogIdeas[100] = {
		"Chasing the mailman",
		"Barking at strangers",
		"Digging holes in the yard",
		"Wagging tail happily",
		"Chewing on a bone"
	};

	std::string	const catIdeas[100] = {
		"Sleeping on the keyboard",
		"Chasing laser pointer",
		"Knocking things off the table",
		"Purring loudly",
		"Scratching the couch"
	};

	Animal	*animals[] = {
		new Dog(dogIdeas),
		new Dog(dogIdeas),
		new Cat(catIdeas),
		new Cat(catIdeas)
	};

	std::cout << animals[0]->getType() << std::endl;
	animals[0]->makeSound();
	std::cout << animals[3]->getType() << std::endl;
	animals[3]->makeSound();

	for (size_t i = 0; i < 4; i++)
		delete animals[i];

	return (0);
}

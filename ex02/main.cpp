/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:55:12 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/10 20:08:33 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	// AAnimal const *animal = new AAnimal(); // Error: cannot instantiate object from abstract class
	AAnimal const *dog = new Dog();
	AAnimal const *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	//animal->makeSound();

	//delete animal;
	delete cat;
	delete dog;

	return (0);
}

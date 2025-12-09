/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:55:12 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/09 23:19:54 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal const *animal = new Animal();
	Animal const *dog = new Dog();
	Animal const *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();

	delete animal;
	delete cat;
	delete dog;

	// Empty & random type
	Animal const *noTypeCat = new Cat("");
	Animal const *randomTypeCat = new Cat("Whale");
	Animal const *noTypeDog = new Dog("");
	Animal const *randomTypeDog = new Dog("Horse");

	std::cout << noTypeCat->getType() << std::endl;
	std::cout << randomTypeCat->getType() << std::endl;
	std::cout << noTypeDog->getType() << std::endl;
	std::cout << randomTypeDog->getType() << std::endl;

	delete noTypeCat;
	delete randomTypeCat;
	delete noTypeDog;
	delete randomTypeDog;

	// WrongAnimal && WrongCat
	WrongAnimal const *wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound(); // will output the wrong animal sound!

	delete wrongCat;

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:57:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 20:41:20 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

static void printHeader(std::string const &title)
{
	std::cout << "\n" << title << "\n============" << std::endl;
}

void	Test1(void)
{
	// ----------------------------------------------------------
	printHeader("Test 1: Basic Materia Types");
	// ----------------------------------------------------------
	
	// AMateria	materia; // Cant instantiate abstract class
	
	Ice			a1;
	Ice			b1(a1);
	Ice			c1;
	AMateria	*ice = new Ice();

	c1 = b1;

	Cure		a2;
	Cure		b2(a2);
	Cure		c2;
	AMateria	*cure = new Cure();

	c2 = b2;
	*cure = *ice; // cure object should mantain it's type (do not copy ).

	AMateria *materias[] = {
		new Ice(),
		new Cure()
	};

	std::cout << materias[0]->getType() << std::endl;
	std::cout << materias[1]->getType() << std::endl;
	std::cout << cure->getType() << std::endl;

	delete ice;
	delete cure;
	delete materias[0];
	delete materias[1];
}

void	Test2(void)
{
	// ----------------------------------------------------------
	printHeader("Test 2: Constructing Characters");
	// ----------------------------------------------------------
	
	Character	ch1;
	Character	ch2("Bob");
	Character	ch3("Ron");
	Character	ch4(ch2);
	Character	ch5;

	ch1.equip(new Ice());
	ch1.equip(new Ice());
	ch1.equip(new Cure());
	ch1.equip(new Cure());

	ch5 = ch1;
	ch5 = ch1; // Copy again to see it previous items in inv were deleted.

	std::cout << ch1.getName() << std::endl;
	std::cout << ch2.getName() << std::endl;
	std::cout << ch3.getName() << std::endl;
	std::cout << ch4.getName() << std::endl;
	std::cout << ch5.getName() << std::endl;

	ch5.listEquipments();
}

void	Test3(void)
{
	// ----------------------------------------------------------
	printHeader("Test 3: Using/Unequipping with Empty Inventory");
	// ----------------------------------------------------------
	
	Character	ch1("Bob");
	Character	ch2("Ron");

	ch1.listEquipments(); // Empty inventory
	ch1.use(0, ch2);
	ch1.use(-10, ch2); // Out of range
	ch1.use(10, ch2); // Out of range
	ch1.unequip(0);
}

void	Test4(void)
{
	// ----------------------------------------------------------
	printHeader("Test 4: Equip → Use → Unequip");
	// ----------------------------------------------------------
	
	Character	ch1("Bob");
	Character	ch2("Ron");
	
	ch1.equip(new Ice());
	ch1.listEquipments(); // One Materia equipped in slot 1
	ch1.use(0, ch2); // Success.
	ch1.use(10, ch2); // Out of range
	ch1.use(-10, ch2); // Out of range
	ch1.unequip(0); // Success.
	ch1.unequip(0); // Trying to unequip a second time. Should fail.
}

void	Test5(void)
{
	// ----------------------------------------------------------
	printHeader("Test 5: Multiple Equip & Unequip");
	// ----------------------------------------------------------

	Character	ch1("Bob");
	Character	ch2("Ron");

	ch1.equip(new Ice());
	ch1.equip(new Cure());
	ch1.equip(new Ice());
	ch1.equip(new Ice());
	ch1.equip(new Ice()); // Inventory is full, should fail.

	ch1.listEquipments(); // Full inventory

	ch1.unequip(0);
	ch1.listEquipments(); // First slot empty

	ch1.unequip(1);
	ch1.unequip(3);
	ch1.listEquipments(); // Second and last slots empty

	ch1.unequip(2);
	ch1.listEquipments(); // All slots empty
}

void	Test6(void)
{
	// ----------------------------------------------------------
	printHeader("Test 6: Deep Copy of Character");
	// ----------------------------------------------------------
	
	Character	*ch1 = new Character("Bob");

	ch1->equip(new Ice());
	ch1->equip(new Cure());
	ch1->equip(new Cure());
	ch1->equip(new Ice());
	ch1->listEquipments(); // Full inventory
	
	Character	clone = *ch1;
	delete ch1;

	clone.listEquipments(); // Full inventory (but Materias have diff addresses)
}

void	Test7(void)
{
	// ----------------------------------------------------------
	printHeader("Test 7: Constructing MateriaSource");
	// ----------------------------------------------------------
	
	MateriaSource	ms1;
	MateriaSource	ms2(ms1);
	MateriaSource	*ms3 = new MateriaSource();

	ms3->learnMateria(new Ice());
	ms3->learnMateria(new Cure());

	ms1 = *ms3;
	ms1 = *ms3; // Copying a second time to verify if previous materias were deleted.
	
	delete ms3;
	
	ms1.listMaterias();
}

void	Test8(void)
{
	// ----------------------------------------------------------
	printHeader("Test 8: Learning/Creating Materia");
	// ----------------------------------------------------------
	
	MateriaSource	*ms1 = new MateriaSource();

	ms1->learnMateria(new Ice());
	ms1->learnMateria(new Cure());
	ms1->listMaterias();

	AMateria	*m = ms1->createMateria("ice");
	AMateria	*m2 = ms1->createMateria("cure");
	AMateria	*m3 = ms1->createMateria("inexistent");

	std::cout << (m ? m->getType() : "NULL") << std::endl;
	std::cout << (m2 ? m2->getType() : "NULL") << std::endl;
	std::cout << (m3 ? m3->getType() : "NULL") << std::endl;

	delete m;
	delete m2;
	delete m3;
	delete ms1;
}

void	Test9(void)
{
	// ----------------------------------------------------------
	printHeader("Test 9: Full test");
	// ----------------------------------------------------------
	
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int	main(void)
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();

	return (0);
}

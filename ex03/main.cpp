/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:57:01 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 19:02:29 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

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
	
	Ice	a1;
	Ice	b1(a1);
	Ice	c1;

	c1 = b1;

	Cure	a2;
	Cure	b2(a2);
	Cure	c2;

	c2 = b2;

	AMateria *materias[] = {
		new Ice(),
		new Cure()
	};

	std::cout << materias[0]->getType() << std::endl;
	std::cout << materias[1]->getType() << std::endl;

	delete materias[0];
	delete materias[1];
}

void	Test2(void)
{
	// ----------------------------------------------------------
	printHeader("Test 2: Constructing Characters");
	// ----------------------------------------------------------
	
	Ice			ice;
	Cure		cure;

	Character	ch1;
	Character	ch2("Bob");
	Character	ch3("Ron");
	Character	ch4(ch2);
	Character	ch5;

	ch1.equip(&ice);
	ch1.equip(&ice);
	ch1.equip(&cure);
	ch1.equip(&cure);

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
	Ice			ice;
	
	ch1.equip(&ice);
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

	Ice			ice;
	Cure		cure;
	Character	ch1("Bob");
	Character	ch2("Ron");

	ch1.equip(&ice);
	ch1.equip(&cure);
	ch1.equip(&cure);
	ch1.equip(&ice);
	ch1.equip(&ice); // Inventory is full, should fail.

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
	
	Ice			ice;
	Cure		cure;
	Character	*ch1 = new Character("Bob");

	ch1->equip(&ice);
	ch1->equip(&cure);
	ch1->equip(&cure);
	ch1->equip(&ice);
	ch1->listEquipments(); // Full inventory
	
	Character	clone = *ch1;
	delete ch1;

	clone.listEquipments(); // Full inventory (but Materias have diff addresses)
}

int	main(void)
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return (0);
}

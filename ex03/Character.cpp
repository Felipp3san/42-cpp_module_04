/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:19:29 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 18:56:22 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(void) :
	_name("Unnamed"),
	_slotsInUse(0),
	_discarded(0)
{
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;
	
	std::cout
		<< "Character default constructor called."
		<< std::endl;
}

Character::Character(std::string const &name) :
	_name(name),
	_slotsInUse(0),
	_discarded(0)
{
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;

	std::cout
		<< "Character parameterized constructor called."
		<< std::endl;
}

Character::Character(Character const &other) :
	_name(other._name),
	_slotsInUse(other._slotsInUse),
	_discarded(other._discarded)
{
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}

	for (int i = 0; i < other._discarded; i++)
		_floor[i] = other._floor[i]->clone();

	std::cout
		<< "Character copy constructor called."
		<< std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < INV_SIZE; i++)
		delete _inventory[i];

	for (int i = 0; i < _discarded; i++)
		delete _floor[i];

	std::cout
		<< "Character destructor called."
		<< std::endl;
}

Character	&Character::operator=(Character const &other)
{
	if (this != &other)
	{
		_name = other._name;
		_slotsInUse = other._slotsInUse;

		for (int i = 0; i < INV_SIZE; i++)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}

		for (int i = 0; i < INV_SIZE; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}

		for (int i = 0; i < _discarded; i++)
			delete _floor[i];

		_discarded = other._discarded;
		for (int i = 0; i < _discarded; i++)
		{
			_floor[i] = other._floor[i]->clone();
		}
	}

	std::cout
		<< "Character copy assignment operator called."
		<< std::endl;

	return (*this);
}

std::string	const	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	if (_slotsInUse == INV_SIZE)
	{
		std::cout
			<< "Character: " << _name
			<< " inventory is full." << std::endl;
		return ;
	}

	if (m == NULL)
	{
		std::cout
			<< "Character: " << _name
			<< " tried to equip an inexistent Materia." << std::endl;
		return ;
	}

	for (int i = 0; i < INV_SIZE; i++)
	{
		if (!_inventory[i])
		{
			_inventory[_slotsInUse++] = m->clone();
			break ;
		}
	}

	std::cout
		<< "Character: " << _name
		<< " equipped a Materia." << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > INV_SIZE)
	{
		std::cout
			<< "Index out of range."
			<< std::endl;
		return ;
	}

	if (!_inventory[idx])
	{
		std::cout
			<< "Character: " << _name
			<< " has no Materia in that slot." 
			<< std::endl;
		return ;
	}
	
	_floor[_discarded++] = _inventory[idx];
	_inventory[idx] = NULL;
	_slotsInUse--;

	std::cout
		<< "Character: " << _name
		<< " unequiped a Materia." 
		<< std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > INV_SIZE)
	{
		std::cout
			<< "Index out of range."
			<< std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout
			<< "Character: " << _name
			<< " has no Materia in that slot."
			<< std::endl;
		return ;
	}

	std::cout
		<< "Character: " << _name
		<< " used a Materia."
		<< std::endl;

	_inventory[idx]->use(target);
}

void	Character::listEquipments(void) const
{
	std::cout
		<< "=== Inventory ==="
		<< std::endl;

	for (int i = 0; i < INV_SIZE; i++)
	{
		std::cout
			<< (_inventory[i] ? _inventory[i]->getType() : "EMPTY");

		if (i != INV_SIZE -1)
		{
			std::cout
				<< " || ";
		}
	}

	std::cout
		<< std::endl;
}

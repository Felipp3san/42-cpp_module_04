/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alme <fde-alme@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:13:48 by fde-alme          #+#    #+#             */
/*   Updated: 2025/12/11 20:15:36 by fde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : _storedMaterias(0)
{
	for (int i = 0; i < SIZE; i++)
		_materias[i] = NULL;

	std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other) :
	_storedMaterias(other._storedMaterias)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
	}

	std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < SIZE; i++)
		delete _materias[i];

	std::cout << "MateriaSource destructor called." << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < _storedMaterias; i++)
		{
			delete _materias[i];
			_materias[i] = NULL;
		}

		_storedMaterias = other._storedMaterias;
		for (int i = 0; i < SIZE; i++)
		{
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
		}
	}

	std::cout << "MateriaSource copy assignment operator called." << std::endl;
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *materia)
{
	if (_storedMaterias == SIZE)
		return ;

	_materias[_storedMaterias++] = materia->clone();
	delete materia;

	std::cout
		<< "MateriaSource learnMateria called."
		<< std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (_materias[i] && type == _materias[i]->getType())
			return (_materias[i]->clone());
	}

	std::cout
		<< "MateriaSource createMateria called."
		<< std::endl;

	return (0);
}

void	MateriaSource::listMaterias(void) const
{
	std::cout
		<< "=== Materias ==="
		<< std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout
			<< (_materias[i] ? _materias[i]->getType() : "EMPTY");

		if (i != SIZE-1)
		{
			std::cout
				<< " || ";
		}
	}

	std::cout
		<< std::endl;
}

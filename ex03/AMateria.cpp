
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("none")
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria parameterized constructor called." << std::endl;
}

AMateria::AMateria(AMateria const &other) : _type(other._type)
{
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	(void) other;
	// Do not copy _type, since it's bound to the Class.

	std::cout << "AMateria copy assignment operator called." << std::endl;
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &type)
{
	(void) type;
}

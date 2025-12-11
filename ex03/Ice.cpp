
#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
	std::cout << "Ice copy constructor called." << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called." << std::endl;
}

Ice	&Ice::operator=(Ice const &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}

	std::cout << "Ice copy assignment operator called." << std::endl;
	return (*this);
}

Ice	*Ice::clone(void)
{
	std::cout << "Ice clone method called." << std::endl;

	return (new Ice(*this));
}

void	Ice::use(ICharacter	&type)
{
	std::cout << "Ice: * shoots an ice bolt at "
		<< type.getName() << " *"
		<< std::endl;
}

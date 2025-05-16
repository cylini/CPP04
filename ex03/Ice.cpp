#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
	}
	std::cout << "Ice assignment operator called" << std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const// clone method
{
	std::cout << "Ice clone called" << std::endl;
	return new Ice(*this);// create a new Ice object
}

void Ice::use(ICharacter &target)// use method
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;// use the target's name
}

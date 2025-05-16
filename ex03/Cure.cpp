#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
	}
	std::cout << "Cure assignment operator called" << std::endl;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const// clone method
{
	std::cout << "Cure clone called" << std::endl;
	return new Cure(*this);// create a new Cure object
}

void Cure::use(ICharacter &target)// use method
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;// use the target's name
}

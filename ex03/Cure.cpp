#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &src) : AMateria(src) { *this = src; }

Cure &Cure::operator=(Cure const &copy)
{
	AMateria::operator=(copy);
	return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
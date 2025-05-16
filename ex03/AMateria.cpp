#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria default")//constructor par défaut
{
	std::cout << "🥛 Default AMateria created" << std::endl;
}

AMateria::AMateria(const std::string &type) : _type(type)//constructor avec type
{
	std::cout << "🥛 AMateria of type '" << _type << "' constructed" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)//constructor de copie
{
	std::cout << "🥛 AMateria copy-constructed with type '" << _type << "'" << std::endl;
}

// Assignment
AMateria &AMateria::operator=(const AMateria &other)//opérateur d'assignation
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "🥛 AMateria assigned with type '" << _type << "'" << std::endl;
	return *this;
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "🥛 AMateria of type '" << _type << "' destroyed" << std::endl;
}

// Getter
const std::string &AMateria::getType() const//getter pour le type
{
	return _type;
}

// Virtual method
void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "🥛 AMateria base use() called (no effect)" << std::endl;
}


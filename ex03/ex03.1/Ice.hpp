#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &src);
	Ice &operator=(Ice const &copy);
	/* virtual */ ~Ice();

	/* virtual */ AMateria *clone() const;
	/* virtual */ void use(ICharacter &target);
};

#endif
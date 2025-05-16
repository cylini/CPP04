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
	~Ice();

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
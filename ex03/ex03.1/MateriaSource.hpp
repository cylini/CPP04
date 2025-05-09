#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materia[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &src);
	MateriaSource &operator=(MateriaSource const &copy);
	/* virtual */ ~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif
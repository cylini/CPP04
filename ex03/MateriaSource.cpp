#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_materia[i] = 0;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src) // copy constructor
{
	for (int i = 0; i < 4; ++i)
	{
		if (src._materia[i])
			_materia[i] = src._materia[i]->clone(); // deep copy
		else
			_materia[i] = 0; // set to null
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) // assignment operator
{
	if (this != &src)
	{
		for (int i = 0; i < 4; ++i) // iterate through the array
		{
			delete _materia[i];							// delete the existing materia
			if (src._materia[i])						// check if the source materia is not null
				_materia[i] = src._materia[i]->clone(); // clone the materia
			else
				_materia[i] = 0; // set to null
		}
		std::cout << "MateriaSource assignment operator called" << std::endl;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		delete _materia[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m) // learn a materia
{
	if (!m) // check if the materia is null
		return;

	for (int i = 0; i < 4; ++i)
	{
		if (!_materia[i])
		{
			_materia[i] = m;											   // store the materia
			std::cout << "Learned materia: " << m->getType() << std::endl; // print the type of the materia
			return;
		}
	}
	std::cout << "Cannot learn more materias: inventory full" << std::endl;
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type) // create a materia
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materia[i] && _materia[i]->getType() == type) // check if the materia type matches
		{
			std::cout << "Created materia: " << type << std::endl;
			return _materia[i]->clone();// clone the materia
		}
	}
	std::cout << "Unknown materia type: " << type << std::endl;
	return 0;
}
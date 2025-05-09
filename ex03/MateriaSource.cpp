#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src._materia[i])
			_materia[i] = src._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_materia[i])
			{
				delete _materia[i];
				_materia[i] = NULL;
			}
			if (copy._materia[i])
				_materia[i] = copy._materia[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materia[i])
		{
			delete _materia[i];
			_materia[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = m->clone();
			break;
		}
	}
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}

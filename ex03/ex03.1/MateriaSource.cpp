#include "MateriaSource.hpp"

////constructor & destructor
// MateriaSource::MateriaSource()
// {
// 	for (int i = 0; i < 4; i++)
// 		_materia[i] = NULL;
// 	std::cout << "💧MateriaSource default constructor called" << std::endl;
// }

// // deep copy _materia
// MateriaSource::MateriaSource(const MateriaSource &src) : IMateriaSource(src)
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (src._materia[i])
// 			this->_materia[i] = src._materia[i]->clone();
// 		else
// 			this->_materia[i] = NULL;
// 	}
// 	std::cout << "💧MateriaSource " << _materia << " copy constructor called" << std::endl;
// }

// // deep copy
// // cleanup before assign!!!
// MateriaSource &MateriaSource::operator=(const MateriaSource &src)
// {
// 	// cleanup!! set to NULL!
// 	for (int i = 0; i < 4; i++)
// 	{
// 		delete _materia[i];
// 		_materia[i] = NULL;
// 	}

// 	// assign
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (src._materia[i])
// 			this->_materia[i] = src._materia[i]->clone();
// 	}
// 	std::cout << "💧MateriaSource " << _materia << " assign operator called" << std::endl;
// 	return (*this);
// }

// // delete prototypes!!!
// MateriaSource::~MateriaSource()
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (_materia[i])
// 		{
// 			delete _materia[i];
// 			_materia[i] = NULL;
// 		}
// 	}
// 	std::cout << "💧MateriaSource destructor called" << std::endl;
// }

// ////member funcs

// // learnMateria
// //  Clean up the original materia object if it's not equipped
// void MateriaSource::learnMateria(AMateria *m)
// {
// 	if (!m)
// 		return;

// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (_materia[i] == NULL)
// 		{
// 			_materia[i] = m;
// 			std::cout << "💧MateriaSource " << _materia[i]->getType() << " learned" << std::endl;
// 			return;
// 		}
// 	}
// 	std::cout << "❌MateriaSource already full" << std::endl;
// 	delete m;
// }

// // createMateria
// AMateria *MateriaSource::createMateria(std::string const &type)
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (this->_materia[i] && _materia[i]->getType() == type)
// 		{
// 			std::cout << "MateriaSource " << _materia[i]->getType() << " created" << std::endl;
// 			return (this->_materia[i]->clone());
// 		}
// 	}
// 	std::cout << "❌Didn't find the type. Ensure you write 'cure' or 'ice'." << std::endl;
// 	return (NULL);
// }
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_materia[i] = 0;
	std::cout << "MateriaSource: default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src._materia[i])
			_materia[i] = src._materia[i]->clone();
		else
			_materia[i] = 0;
	}
	// for (int i = 0; i < 4; ++i)
	// {

	// }
	// _materia[i] = src._materia[i] ? src._materia[i]->clone() : 0;
	std::cout << "MateriaSource: copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete _materia[i];
			if (src._materia[i])
				_materia[i] = src._materia[i]->clone();
			else
				_materia[i] = 0;
		}
		// for (int i = 0; i < 4; ++i)
		// {
		// 	delete _materia[i];
		// 	_materia[i] = src._materia[i] ? src._materia[i]->clone() : 0;
		// }
		std::cout << "MateriaSource: assignment operator called" << std::endl;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		delete _materia[i];
	std::cout << "MateriaSource: destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
	{
		if (!_materia[i])
		{
			_materia[i] = m;
			std::cout << "Learned materia: " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Cannot learn more materias: inventory full" << std::endl;
	delete m;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materia[i] && _materia[i]->getType() == type)
		{
			std::cout << "Created materia: " << type << std::endl;
			return _materia[i]->clone();
		}
	}
	std::cout << "Unknown materia type: " << type << std::endl;
	return 0;
}
#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const &src) { *this = src; }

Character &Character::operator=(Character const &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (copy._inventory[i])
				_inventory[i] = copy._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	// for (int i = 0; i < 4; i++)
	// 	delete _inventory[i];
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i]; // Libère chaque materia
			this->_inventory[i] = 0;
		}
	}
}
// Character::~Character()
// {
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		if (_materia[i]) // Si l'élément est non NULL, le supprimer
// 		{
// 			delete _materia[i];
// 			_materia[i] = NULL;
// 		}
// 	}
// }

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = 0;
	std::cout << "Character " << _name << " constructor called" << std::endl;
}

Character::Character(const Character &src) : _name(src._name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone(); // deep copy
		else
			_inventory[i] = 0;
	}
	std::cout << "Character " << _name << " copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < 4; ++i)
		{
			delete _inventory[i];
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone(); // deep copy
			else
				_inventory[i] = 0;
		}
		std::cout << "Character " << _name << " assignment called" << std::endl;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		delete _inventory[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

const std::string &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)// Equip a materia
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) // Check if the inventory slot is empty
	{
		if (_inventory[i] == 0) // If the slot is empty
		{
			_inventory[i] = m;// Equip the materia
			std::cout << _name << " equipped " << m->getType() << std::endl;// Print the message
			return;
		}
	}
	std::cout << _name << "'s inventory is full, cannot equip" << std::endl;
	delete m;
}

void Character::unequip(int idx)//unequip a materia
{
	if (idx >= 0 && idx < 4 && _inventory[idx])// Check if the index is valid and the slot is occupied
	{
		std::cout << _name << " unequipped " << _inventory[idx]->getType() << std::endl;// Print the message
		_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])//
	{
		_inventory[idx]->use(target);
	}
	else
	{
		std::cout << _name << " can't use slot " << idx << std::endl;
	}
}

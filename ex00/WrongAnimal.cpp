#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	_type = "WrongAnimal";
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
	// _type = copy._type;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << " makes sound : WrongAnimal sound !" << std::endl;
}
std::string const &WrongAnimal::getType() const
{
	return _type;
}
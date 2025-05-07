#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
	// _type = copy._type;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}
void WrongCat::makeSound() const
{
	std::cout << "WrongCat " << _type << " makes sound : MeowMeowMeow !" << std::endl;
}
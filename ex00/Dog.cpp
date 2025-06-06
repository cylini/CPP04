#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}
Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = copy._type;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}
void Dog::makeSound() const
{
	std::cout << this->_type << " makes sound : Woof !" << std::endl;
}
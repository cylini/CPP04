#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}
Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = copy._type;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}
void Cat::makeSound() const
{
	std::cout << this->_type << " makes sound : Meow !" << std::endl;
}
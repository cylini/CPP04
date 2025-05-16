#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}
Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = copy._type;
	_brain = new Brain(*copy._brain);
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}
Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	return *this;
}
void Cat::makeSound() const
{
	std::cout << this->_type << " makes sound : Meow !" << std::endl;
}
Brain &Cat::getBrain() const
{
	return *_brain;
}

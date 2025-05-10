#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}
Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = copy._type;

	_brain = new Brain(*copy._brain);
	// _brain = new Brain();
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}
Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		_type = copy._type;
		delete (_brain);
		_brain = new Brain(*copy._brain);
	}
	return *this;
}
void Dog::makeSound() const
{
	std::cout << "Dog " << _type << " makes sound : Woof !" << std::endl;
}
Brain &Dog::getBrain() const
{
	return *_brain;
}
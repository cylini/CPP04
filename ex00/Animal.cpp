#include "Animal.hpp"

Animal::Animal() : _type("Default Animal")
{
	std::cout << "Animal default constructor called and named " << _type << std::endl;
}
Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "Animal copy constructor called and named" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called " << std::endl;
}
Animal &Animal::operator=(const Animal &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}
void Animal::makeSound() const
{
	std::cout << "An animal make a sound" << std::endl;
}
std::string const &Animal::getType() const
{
	return _type;
}
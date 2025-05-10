#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called named " << _type << std::endl;
}
AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type)
{
	std::cout << "AAnimal copy constructor called named" << std::endl;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called named " << std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	if (this != &copy)
	{
		_type = copy._type; //
	}
	return *this;
}
void AAnimal::makeSound() const
{
	std::cout << "An AAnimal make a sound" << std::endl;
}
std::string const &AAnimal::getType() const
{
	return _type; //
}
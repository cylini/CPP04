#include "AMateria.hpp"
// #include "ICharacter.hpp"

AMateria::AMateria() : _type("type") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &src) { *this = src; }

AMateria &AMateria::operator=(AMateria const &copy)
{
	if (this != &copy)
		_type = copy._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target)
{
	(void)target;
}

// AMateria::AMateria(const std::string const &type) : _type(type)
// {
// 	std::cout << "AMateria " << this->_type << " constructor called" << std::endl;
// }
// AMateria::AMateria(AMateria const &src)
// {
// 	std::cout << "AMateria " << this->_type << " copy constructor called" << std::endl;
// 	*this = src;
// }
// AMateria &AMateria::operator=(AMateria const &copy)
// {
// 	std::cout << "AMateria " << this->_type << " copy assignment operator called" << std::endl;
// 	if (this != &copy)
// 		this->_type = copy._type;
// 	return *this;
// }
// AMateria::~AMateria()
// {
// 	std::cout << "AMateria " << this->_type << " destructor called" << std::endl;
// }
// std::string const AMateria::getType() const { return this->_type; }

// void AMateria::use(ICharacter &target)
// {
// 	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
// }
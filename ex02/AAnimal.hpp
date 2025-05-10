#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string _type;

public:
	AAnimal();
	AAnimal(const AAnimal &copy);
	virtual ~AAnimal();
	AAnimal &operator=(const AAnimal &copy);

	virtual void makeSound() const;
	std::string const &getType() const;
};

#endif
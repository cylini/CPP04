#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &copy);
	virtual ~Animal();
	Animal &operator=(const Animal &copy);
	virtual void makeSound() const;
	std::string const &getType() const;
	// 		void setType(std::string type);
	// 		void setType(const char *type);
	// 		void setType(const std::string &type);
	// 		void setType(const std::string_view &type);
	// 		void setType(const std::string_view type);
};

// class Dog : public Animal
// {
// public:
// 	Dog();
// 	Dog(const Dog &copy);
// 	virtual ~Dog();
// 	Dog &operator=(const Dog &copy);
// 	void makeSound() const;
// }

#endif
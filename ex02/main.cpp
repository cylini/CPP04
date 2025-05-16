#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	AAnimal animal;

	Dog *dog = new Dog();
	Cat *cat = new Cat(); 
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << "Dog sound: ";
	dog->makeSound();
	std::cout << "Cat sound: ";
	cat->makeSound();
	std::cout << "Dog idea[0]: " << dog->getBrain().getIdea(0) << std::endl;
	std::cout << "Cat idea[0]: " << cat->getBrain().getIdea(0) << std::endl;

	delete dog;
	delete cat;
	return 0;
}
//    Animal animal; // not allowed because there's at least one pure virtual method
// Dog dog;
// dog.makeSound();
// dog.getBrain().setIdea(0, "EAT");
// std::cout << "Dog idea[0]: " << dog.getBrain().getIdea(0) << std::endl;



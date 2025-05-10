#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{

	const int size = 6;
	AAnimal *animals[size];

	std::cout << "\n--- Creating animals ---\n"
			  << std::endl;
	for (int i = 0; i < size; ++i)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- Making sounds ---\n"
			  << std::endl;
	for (int i = 0; i < size; ++i)
	{
		animals[i]->makeSound();
	}

	std::cout << "\n--- Testing deep copy of Dog ---\n"
			  << std::endl;
	Dog original;
	original.getBrain().getIdea(0); // just to show access
	Dog copy = original;

	std::cout << "Original Brain Idea: " << original.getBrain().getIdea(0) << std::endl;
	std::cout << "Copied Brain Idea:   " << copy.getBrain().getIdea(0) << std::endl;

	std::cout << "\n--- Deleting animals ---\n"
			  << std::endl;
	for (int i = 0; i < size; ++i)
	{
		delete animals[i];
	}

	return 0;

	//    Animal animal; // not allowed because there's at least one pure virtual method
	// Dog dog;
	// dog.makeSound();
	// dog.getBrain().setIdea(0, "EAT");
	// std::cout << "Dog idea[0]: " << dog.getBrain().getIdea(0) << std::endl;
}

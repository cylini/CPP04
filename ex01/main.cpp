#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const int N = 4; // Taille du tableau d'animaux (moitié chiens, moitié chats)
	Animal *animals[N];

	// Remplir moitié Dog, moitié Cat
	for (int i = 0; i < N; ++i)
	{
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- Deleting Animals ---\n"
			  << std::endl;

	// Supprimer tous les animaux
	for (int i = 0; i < N; ++i)
	{
		delete animals[i];
	}

	std::cout << "\n--- Testing Deep Copy ---\n"
			  << std::endl;

	Dog basic;
	basic.getBrain()->setIdea(0, "Chase the cat!");

	Dog copy = basic; // Appelle le constructeur par copie
	std::cout << "Original Dog idea: " << basic.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea:   " << copy.getBrain()->getIdea(0) << std::endl;

	basic.getBrain()->setIdea(0, "Bark at the mailman!");

	std::cout << "\nAfter modifying original's brain:\n";
	std::cout << "Original Dog idea: " << basic.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea:   " << copy.getBrain()->getIdea(0) << std::endl;

	return 0;
}
// int main()
// {
// 	// Wrong Animal
// 	// Wrong Cat
// 	std::cout << "\n\n===== Wrong Animals =====" << std::endl;
// 	std::cout << "\n-------- constructors --------" << std::endl;
// 	const WrongAnimal *wronganimal = new WrongAnimal();
// 	const WrongAnimal *wrongcat = new WrongCat();
// 	std::cout << "\n-------- print type --------" << std::endl;
// 	std::cout << "Wrong Animal type: " << wronganimal->getType() << " " << std::endl;
// 	std::cout << "Wrong Cat type: " << wrongcat->getType() << " " << std::endl;
// 	std::cout << "\n-------- make sounds --------" << std::endl;
// 	wronganimal->makeSound();
// 	wrongcat->makeSound();
// 	std::cout << "\n-------- cleanup --------" << std::endl;
// 	delete wronganimal;
// 	delete wrongcat;

// 	std::cout << "\n\n===== Animals =====" << std::endl;
// 	std::cout << "\n-------- constructors --------" << std::endl;
// 	const Animal *meta = new Animal();
// 	const Animal *j = new Dog();
// 	const Animal *i = new Cat();
// 	std::cout << "\n-------- print type --------" << std::endl;
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	std::cout <<"\n-------- make sounds --------" << std::endl;
// 	i->makeSound(); // will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	std::cout << "\n-------- cleanup --------" << std::endl;
// 	delete meta;
// 	delete j;
// 	delete i;

// 	std::cout << "\n-------- other tests --------" << std::endl;

// 	Animal *animal = new Animal();
// 	animal->makeSound();
// 	std::cout << "Animal type: " << animal->getType() << std::endl;
// 	delete animal;
// 	std::cout << "------------------------" << std::endl;

// 	Animal *animal1 = new Cat();
// 	animal->makeSound();
// 	std::cout << "Animal type: " << animal->getType() << std::endl;
// 	delete animal1;
// 	std::cout << "------------------------" << std::endl;
// 	Animal *animal2 = new Dog();
// 	animal2->makeSound();
// 	std::cout << "Animal type: " << animal2->getType() << std::endl;
// 	delete animal2;
// 	std::cout << "------------------------" << std::endl;

// 	Dog *dog = new Dog();
// 	dog->makeSound();
// 	std::cout << "Dog type: " << dog->getType() << std::endl;
// 	delete dog;

// 	Cat *cat = new Cat();
// 	cat->makeSound();
// 	std::cout << "Cat type: " << cat->getType() << std::endl;
// 	delete cat;

// 	return 0;
// }
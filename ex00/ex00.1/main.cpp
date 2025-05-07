#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

	// Wrong animal
	// Wrong Cat
	std::cout << "\n\n===== Wrong Animals =====" << std::endl;
	std::cout << "\n-------- constructors --------" << std::endl;
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "\n-------- print type --------" << std::endl;
	std::cout << "Wrong Animal type: " << wrongAnimal->getType() << " " << std::endl;
	std::cout << "Wrong Cat type: " << wrongCat->getType() << " " << std::endl;

	// wrong class inheritance -> cannot compile
	//  const WrongAnimal* error = new Cat(); //not compilable
	//  std::cout << error->getType() << " " << std::endl; //not compilable

	// make sound
	std::cout << "\n-------- make sounds --------" << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound(); // willnot output the cat sound!
	// error->makeSound();

	// Cleanup
	std::cout << "\n-------- cleanup --------" << std::endl;
	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
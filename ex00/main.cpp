#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n===== Wrong Animals =====" << std::endl;
	std::cout << "\n-------- constructors --------" << std::endl;
	const WrongAnimal *wronganimal = new WrongAnimal();
	const WrongAnimal *wrongcat = new WrongCat();
	std::cout << "\n-------- print type --------" << std::endl;
	std::cout << "Wrong Animal type: " << wronganimal->getType() << std::endl;
	std::cout << "Wrong Cat type: " << wrongcat->getType() << std::endl;
	std::cout << "\n-------- make sounds --------" << std::endl;
	wronganimal->makeSound();
	wrongcat->makeSound();
	std::cout << "\n-------- cleanup --------" << std::endl;
	delete wronganimal;
	delete wrongcat;

	std::cout << "\n\n===== Animals =====" << std::endl;
	std::cout << "\n-------- constructors --------" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << "\n-------- print type --------" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout <<"\n-------- make sounds --------" << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\n-------- cleanup --------" << std::endl;
	delete j;
	delete i;
	delete meta;

	return 0;
}
// const Animal *meta = new Animal();
// const Animal *j = new Dog();
// const Animal *i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); // will output the cat sound!
// j->makeSound();
// meta->makeSound();

// delete meta;
// delete j;
// delete i;
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "\n🐾 === TESTS DES ANIMAUX ===\n";
	const int size = 6;
	Animal *animals[size];

	std::cout << "📦 Création de " << size / 2 << " Dogs et " << size / 2 << " Cats\n";
	for (int i = 0; i < size / 2; ++i)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; ++i)
		animals[i] = new Cat();

	std::cout << "\n🔊 Sons des animaux :\n";
	for (int i = 0; i < size; ++i)
		animals[i]->makeSound();

	std::cout << "\n🗑️ Suppression des animaux :\n";
	for (int i = 0; i < size; ++i)
		delete animals[i];

	std::cout << "\n🧠 === TEST DE COPIE PROFONDE (DOG) ===\n";
	Dog *dog = new Dog();

	std::cout << "\n📝 Ajout d'idées : \"EAT\" et \"SLEEP\"\n";
	dog->getBrain().setIdea(0, "EAT");
	dog->getBrain().setIdea(1, "SLEEP");

	std::cout << "Dog idea[0]: " << dog->getBrain().getIdea(0) << "\n";
	std::cout << "Dog idea[1]: " << dog->getBrain().getIdea(1) << "\n";

	std::cout << "\n📋 Création de dog2 par copie de dog\n";
	Dog *dog2 = new Dog(*dog);

	std::cout << "❌ Suppression de dog original\n";
	delete dog;

	std::cout << "\n🔊 dog2 fait un son : ";
	dog2->makeSound();

	std::cout << "💡 dog2 idea[0]: " << dog2->getBrain().getIdea(0) << "\n";
	std::cout << "💡 dog2 idea[1]: " << dog2->getBrain().getIdea(1) << "\n";

	std::cout << "\n🗑️ Suppression de dog2\n";
	delete dog2;

	std::cout << "\n✅ Fin du test sans fuite mémoire.\n";
	return 0;
}
// int main()
// {
// 	std::cout << "Animal tests:" << std::endl;
// 	int size = 6;
// 	Animal *animals[size];
// 	for (int i = 0; i < size / 2; ++i)
// 		animals[i] = new Dog();
// 	for (int i = size / 2; i < size; ++i)
// 		animals[i] = new Cat();
// 	for (int i = 0; i < size; ++i)
// 		animals[i]->makeSound();
// 	for (int i = 0; i < size; ++i)
// 		delete (animals[i]);

// 	Dog *dog = new Dog();
// 	std::cout << "Create ideas EAT and SLEEP for dog" << std::endl;
// 	dog->getBrain().setIdea(0, "EAT");
// 	dog->getBrain().setIdea(1, "SLEEP");
// 	std::cout << "Dog idea[0]: " << dog->getBrain().getIdea(0) << std::endl;
// 	std::cout << "Dog idea[1]: " << dog->getBrain().getIdea(1) << std::endl;
// 	std::cout << "Create dog2" << std::endl;
// 	std::cout << "Delete dog" << std::endl;
// 	Dog *dog2 = new Dog(*dog);
// 	delete (dog);
// 	dog2->makeSound();
// 	std::cout << "Dog2 idea[0]: " << dog2->getBrain().getIdea(0) << std::endl;
// 	std::cout << "Dog2 idea[1]: " << dog2->getBrain().getIdea(1) << std::endl;
// 	delete (dog2);

// 	return 0;
// }

// int main()
// {

// 	std::cout << std::endl;
// 	std::cout << "-----------------------------------------------------" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "Deep copy and assignments tests:" << std::endl;
// 	std::cout << std::endl;

// 	Dog basic;
// 	{
// 		Dog tmp = basic;
// 	}

// 	std::cout << std::endl;
// 	std::cout << "-----------------------------------------------------" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "Array tests:" << std::endl;
// 	std::cout << std::endl;

// 	Animal *animals[4];

// 	std::cout << std::endl;

// 	animals[0] = new Dog();
// 	animals[1] = new Cat();
// 	animals[2] = new Dog();
// 	animals[3] = new Cat();

// 	std::cout << std::endl;

// 	for (int i = 0; i < 4; i++)
// 	{
// 		std::cout << animals[i]->getType() << " makes a sound: ";
// 		animals[i]->makeSound();
// 	}

// 	std::cout << std::endl;

// 	for (int i = 0; i < 4; i++)
// 		delete animals[i];

// 	return 0;
// }

// int main()
// {
// 	Cat original;
// 	original.getBrain().setIdea(0, "Manger du poisson");
// 	Cat copy = original;

// 	std::cout << "Original idea[0]: " << original.getBrain().getIdea(0) << std::endl;
// 	std::cout << "Copy idea[0]: " << copy.getBrain().getIdea(0) << std::endl;

// 	// Modifier une idée dans l'original
// 	original.getBrain().setIdea(0, "Dormir");

// 	std::cout << "Original idea[0] (modifiée): " << original.getBrain().getIdea(0) << std::endl;
// 	std::cout << "Copy idea[0] (doit rester inchangée): " << copy.getBrain().getIdea(0) << std::endl;

// 	return 0;
// }
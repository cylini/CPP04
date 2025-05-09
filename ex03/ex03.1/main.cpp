#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "\n--- Création de la source de Materia ---\n";
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n--- Création du personnage 'me' ---\n";
	ICharacter *me = new Character("me");

	std::cout << "\n--- Création et équipement des Materias ---\n";
	AMateria *ice = src->createMateria("ice");
	AMateria *cure = src->createMateria("cure");

	me->equip(ice);
	me->equip(cure);

	std::cout << "\n--- Création du personnage 'bob' ---\n";
	ICharacter *bob = new Character("bob");

	std::cout << "\n--- Utilisation des Materias sur bob ---\n";
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n--- Test de copie profonde ---\n";
	ICharacter *copy = new Character(*dynamic_cast<Character *>(me));
	copy->use(0, *bob);
	copy->use(1, *bob);

	std::cout << "\n--- Déséquipement, test de limites ---\n";
	me->unequip(1);	  // déséquipe sans delete
	me->use(1, *bob); // rien ne doit se passer
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure")); // devrait remplir l'inventaire
	me->equip(src->createMateria("cure")); // devrait ne rien faire

	std::cout << "\n--- Nettoyage de la mémoire ---\n";
	delete bob;
	delete copy;
	delete me;
	delete src;

	std::cout << "\n✅ Fin du test sans fuites mémoire.\n";
	return 0;
}

// int main()
// {

// 	std::cout << "---- Learning Materias ----" << std::endl;
// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	std::cout << "\n---- Creating Character ----" << std::endl;
// 	ICharacter *me = new Character("me");

// 	std::cout << "\n---- Equipping Materias ----" << std::endl;

// 	AMateria *ice = src->createMateria("ice");
// 	AMateria *cure = src->createMateria("cure");

// 	me->equip(ice);
// 	me->equip(cure);

// 	std::cout << "\n---- Creating Target Character ----" << std::endl;
// 	ICharacter *bob = new Character("bob");

// 	std::cout << "\n---- Using Materias ----" << std::endl;
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	std::cout << "\n---- Copying Character ----" << std::endl;
// 	// Character *clone = new Character(*(Character *)me);
// 	Character *clone = new Character("clone");
// 	clone->use(0, *bob);
// 	clone->use(1, *bob);

// 	std::cout << "\n---- Unequipping Materia (index 0) ----" << std::endl;
// 	me->unequip(0);
// 	me->use(0, *bob); // Should do nothing

// 	std::cout << "\n---- Copying MateriaSource ----" << std::endl;
// 	MateriaSource *copySrc = new MateriaSource(*(MateriaSource *)src);
// 	AMateria *tmp2 = copySrc->createMateria("cure");
// 	if (tmp2)
// 	{
// 		std::cout << "Successfully cloned 'cure' from copied MateriaSource" << std::endl;
// 		delete tmp2;
// 	}
// 	else
// 		std::cout << "Failed to clone 'cure' from copied MateriaSource" << std::endl;

// 	std::cout << "\n---- Cleaning Up ----" << std::endl;

// 	delete src;
// 	delete me;
// 	delete bob;
// 	delete clone;
// 	delete copySrc;

// 	return 0;
// }

// int main()
// {
// 	std::cout << "========== [ Set Materia ] ==========" << std::endl;
// 	std::cout << "----------- [Create MateriaSource] --------------" << std::endl;
// 	IMateriaSource *src = new MateriaSource();

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	std::cout << "\n========== [ Set Character A ] ==========" << std::endl;
// 	std::cout << "----------- [Character : ME] --------------" << std::endl;
// 	ICharacter *me = new Character("ME");
// 	// Equip materias to the character (me)
// 	std::cout << "\n========== [ TEST equip() ] ==========" << std::endl;
// 	std::cout << "----------- [Equip on Character ME] --------------" << std::endl;
// 	AMateria *tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("ice"); // 5th should fail!
// 	me->equip(tmp);

// 	std::cout << "----------- [Unequip on Character ME] --------------" << std::endl;
// 	me->unequip(0);

// 	tmp = src->createMateria("cure"); // equip after unequip -> should work!
// 	me->equip(tmp);

// 	std::cout << "\n========== [ Set Character B ] ==========" << std::endl;
// 	std::cout << "----------- [Character : BOB] --------------" << std::endl;
// 	ICharacter *bob = new Character("BOB");

// 	std::cout << "\n========== [ TEST use() ] ==========" << std::endl;
// 	me->use(0, *bob); // cure
// 	me->use(4, *bob); // ice

// 	std::cout << "\n========== [ Cleanup ] ==========" << std::endl;

// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }
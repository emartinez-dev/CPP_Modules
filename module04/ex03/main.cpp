/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:52:10 by franmart          #+#    #+#             */
/*   Updated: 2023/05/31 12:44:29 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

void	ft_leaks(void)
{
	system("leaks -q interfaces");
}

int	main(void)
{
	atexit(ft_leaks);
	std::cout << "Testing main in subject:\n\n";
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "\n\nTesting not learning a materia an using it:\n\n";
	IMateriaSource *noIce = new MateriaSource();

	noIce->learnMateria(new Cure());
	tmp = noIce->createMateria("ice");

	ICharacter *me2 = new Character("Franmart");
	me2->equip(tmp);

	ICharacter *charlie = new Character("Charlie");

	me2->use(0, *charlie);

	std::cout << "\n\nTesting using a materia not equiped:\n\n";
	me2->use(123, *charlie);

	delete charlie;
	delete me2;
	delete noIce;

	std::cout << "\n\nTest for leaks:\n\n";

	return 0;
}
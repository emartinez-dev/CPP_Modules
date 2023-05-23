/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:19:31 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 15:50:01 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>

void	ft_leaks(void)
{
	std::cout << std::endl;;
	system("leaks -q brains");
}

int	main()
{
	atexit(ft_leaks);
	const Animal*	animals[10];

	std::cout << "Creation test ----------------------------\n\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Creating animal " << i + 1 << ":\n\n";
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << "\n\n";
	}

	std::cout << "Deletion test ----------------------------\n\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Deleting animal " << i + 1 << ":\n\n";
		delete animals[i];
		std::cout << "\n\n";
	}

	std::cout << "Deep copy test --------------------------\n\n";
	const Dog*	dogs[2];

	std::cout << "Creating new dog[0]\n\n";
	dogs[0] = new Dog();

	std::cout << "\nDog[0] barks\n";
	dogs[0]->makeSound();

	std::cout << "\nDog[0] gets cloned into Dog[1]\n";
	dogs[1] = new Dog(*dogs[0]);

	std::cout << "\nDog[0] gets removed\n";
	delete dogs[0];

	std::cout << "\nAwesome, Dog[1] keeps barking!!\n";
	dogs[1]->makeSound();

	std::cout << "\nDog[1] gets removed\n";
	delete dogs[1];
	return (0);
}

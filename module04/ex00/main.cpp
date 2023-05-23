/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:19:31 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 11:55:52 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "----------- Constructor tests -----------" << "\n\n";
	std::cout << "---- Animal constructor ----" << std::endl;
	const Animal *meta = new Animal();
	std::cout << "\n----- Dog constructor <j> ------" << std::endl;
	const Animal	*j = new Dog();
	std::cout << "\n----- Cat constructor <i> ------" << std::endl;
	const Animal	*i = new Cat();

	std::cout << "\n----------- Type tests -----------\n";
	std::cout << "j type: " << j->getType() << " \n";
	std::cout << "i type: " << i->getType() << " \n\n";

	std::cout << "\n----------- Sound tests -----------\n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n\n----------- WrongAnimal tests -----------" << "\n\n";
	std::cout << "---- WrongAnimal constructor ----" << std::endl;
	const WrongAnimal *metaWrong = new WrongAnimal();
	std::cout << "\n----- WrongCat constructor <k> ------" << std::endl;
	const WrongAnimal	*k = new WrongCat();

	std::cout << "\n----------- Type tests -----------\n";
	std::cout << "k type: " << k->getType() << " \n";

	std::cout << "\n----------- Sound tests -----------\n";
	k->makeSound();
	metaWrong->makeSound();

	std::cout << "\n\n----------- Destroy everything -----------" << "\n\n";
	delete meta;
	delete i;
	delete j;
	delete k;
	delete metaWrong;

	return (0);
}

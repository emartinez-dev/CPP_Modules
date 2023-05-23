#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat():WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}

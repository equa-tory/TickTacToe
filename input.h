#include<iostream>

int InputX()
{
	int inp;
	std::cout << "Enter horisontal position: ";
	std::cin >> inp;
	return inp-1;
}
int InputY()
{
	int inp;
	std::cout << "Enter vertical position: ";
	std::cin >> inp;
	return inp-1;
}
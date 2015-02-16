//  Ask name, generate a framed greeting
#include <iostream>
#include <string>

int main()
{
	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;
	
	//  Build message to write
	const std::string greeting = "Hello, " + name + "!";
	
	//  Build second and fourth lines of output
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "*" + spaces + "*";
	
	//  Build first and fifth lines of output
	const std::string first(second.size(), '*');
	
	//  Write it all out
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "*" << greeting << "*" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;
	
	return 0;
}
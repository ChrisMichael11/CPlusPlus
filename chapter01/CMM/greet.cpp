//  Ask for a name, then greet that name
#include <iostream>
#include <string>

int main()
{
	//  Ask name
	std::cout << "Please enter your first name: ";
	
	//  Read the name
	std::string name;			//  Defines 'name'
	std::cin >> name;			//  Reads 'name' into string
	
	//  Write greeting
	std::cout << "Hello, " << name << "!" << std::endl;
	return 0;
}
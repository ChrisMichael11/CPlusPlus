//  Chapter00 Practice

#include <iostream>
#include <string>

int main()
{
	
	//  1.1
	//const std::string hello = "Hello";
	//const std::string message = hello + " , world" + "!";
	//  1.2
	//const std::string exclam = "!";
	//const std::string message = "Hello, world" + exclam;  
	
	//  1.1 
	//std::cout << hello << std::endl;
	//std::cout << message << std::endl;
	//  1.2
	//std::cout << message << std::endl;
	
	//  1.3
	//{ const std::string s = "a string";
	//  std::cout << s << std::endl; }
	
	//{ const std::string s = "another string";
	//  std::cout << s << std::endl; }
	  
	//  1.4
	//{ const std::string s = "a string";
	//  std::cout << s << std::endl; 
	
	//{ const std::string s = "another string";
	//  std::cout << s << std::endl; }}  
	
	//  1.5
	//{ std::string s = "a string";
	//{ std::string x = s + ", really";
	//  std::cout << s << std::endl; 
	//  std::cout << x << std::endl; }
	//  }
	
	//  1.6
	std::cout <<  "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name
			  <<  std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name
			  <<  "; nice to meet you too!" << std::endl;	
	
	return 0;
}
//  Solution to 2.9

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
   int first;
   cout << "Enter the first number: ";
   cin >> first;
   cout << endl;
   
   int second;
   cout << "Enter the second number: ";
   cin >> second;
   cout << endl;

   if (first > second)
   {
      cout << "The number " << first << " is the larger number." << endl;
   }
   else if (second > first)
   {
      cout << "The number " << second << " is the larger number." << endl;
   }
   else
   {
      cout << "The numbers are equal." << endl;
   }
	return 0;
}
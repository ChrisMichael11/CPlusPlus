int main()
{
   int k = 0;
   while (k != n) {          // invariant: we have written k asterisks so far
      using std::cout;
      cout << "*";
      ++k;
   }
   std::cout << std::endl;   // std:: is required here
   return 0;
}

The first use of std:: is in the using-declaration. The name cout is declared to mean std::cout. 

The second time std:: appears is to make use of the std::cout stream to output a blank 
line. Because the using-declaration does not apply at this line, the std:: namespace must 
be used explicitly. The last use of std:: is to output a new line with the std::endl manipulator.
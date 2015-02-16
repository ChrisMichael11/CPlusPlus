/*This solution creates a string constant named padding that consists of the appropriate 
number of spaces to output between the border character and the greeting. It also adds a 
filler constant that consists of the number of spaces between the borders on lines above 
and below the greeting.

In the output loop, after determining that spaces should be output, the program tests 
to determine if the current row is a padding row or the greeting row, and outputs the 
appropriate string constant.*/


#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   // ask for the person's name
   cout << "Please enter your first name: ";

   // read the name
   string name;
   cin >> name;

   // build the message that we intend to write
   const string greeting = "Hello, " + name + "!";

   // the number of blanks surrounding the greeting
   const int pad = 5;

   // the number of rows and columns to write
   const int rows = pad * 2 + 3;
   const string::size_type cols = greeting.size() + pad * 2 + 2;

   // string of spaces equal in size to the padding between
   // the border and the greeting
   const string padding(pad, ' ');

   // string of spaces to fill the empty area between borders
   // above and below the greeting
   const string filler(greeting.size() + pad * 2, ' ');

   // write a blank line to separate the output from the input
   cout << endl;

   // write rows rows of output
   // invariant: we have written r rows so far
   for (int r = 0; r != rows; ++r) {

      string::size_type c = 0;

      // invariant: we have written c characters so far in the
      // current row
      while (c != cols) {

         // is it time to write the greeting?
         if (r == pad + 1 && c == pad + 1) {
            cout << greeting;
            c += greeting.size();
         } else {

            // are we on the border?
            if (r == 0 || r == rows - 1 ||
                c == 0 || c == cols - 1) {
               cout << "*";
               ++c;
            } else {

               // are we on the greeting line?
               if (r == pad + 1) {

                  // output the padding
                  cout << padding;
                  c += padding.size();
               } else {
                  
                  // output empty space between borders
                  cout << filler;
                  c += filler.size();
               }
            }
         }
      }

      cout << endl;
   }

   return 0;
}
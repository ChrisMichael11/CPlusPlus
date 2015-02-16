#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
   // this constant is the height of each figure
   const int height = 5;

   // these variables are used to track the row and
   // column count while drawing each figure
   int row;
   int col;

   
   // draw square_________________________
   row = 0;
   col = 0;

   // draw top line
   while (col < height) {
      cout << '*';
      ++col;
   }

   cout << endl;
   ++row;

   // draw middle lines
   while (row < height - 1) {

      col = 0;

      while (col < height) {

         ++col;
         
         if (col == 1)
            cout << '*';
         else {
            if (col == height)
               cout << '*';
            else
               cout << ' ';
         }

      }

      cout << endl;
      ++row;
   }

   // draw bottom line
   col = 0;

   while (col < height) {
      cout << '*';
      ++col;
   }

   // new line after figure
   cout << endl;

   // blank line between figures
   cout << endl;

   // draw rectangle___________________________
   row = 0;
   col = 0;

   // draw top line
   while (col < height * 2) {
      cout << '*';
      ++col;
   }

   cout << endl;
   ++row;

   // draw middle lines
   while (row < height - 1) {

      col = 0;

      while (col <= height * 2) {

         ++col;

         if (col == 1)
            cout << '*';
         else {
            if (col == height * 2)
               cout << '*';
            else
               cout << ' ';
         }
      }

      cout << endl;
      ++row;
   }

   // draw bottom line
   col = 0;

   while (col < height * 2) {
      cout << '*';
      ++col;
   }

   // new line after figure
   cout << endl;

   // blank line between figures
   cout << endl;

   // draw triangle___________________________
   row = 0;

   // draw rows above base
   while (row < height - 1)
   {
      col = 0;

      while (col < height + row) {

         ++col;

         if (col == height - row)
            cout << '*';
         else {

            if (col == height + row)
               cout << '*';
            else
               cout << ' ';
         }
      }

      cout << endl;
      ++row;
   }

   // draw the base
   col = 0;

   while (col < height * 2 - 1) {
      cout << '*';
      ++col;
   }

   // new line after figure
   cout << endl;

   return 0;
}
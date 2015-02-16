//  Calculate squares of int values up to 100.  Write in 2 columns
//  Col 1	Col 2
//  int		squared value
//  use 'setw' to manage values

#include <iomanip>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::setw;

int main()
{
   for (int i = 1; i < 101; ++i)
   {
      cout << setw(4) << i << setw(6) << (i * i) << endl;
      //  setw(4) wide enough for 100, setw(6) wide enough for 100^2
   }
}
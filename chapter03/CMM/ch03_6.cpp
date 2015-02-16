//  The average-grade computation in §3.1/36 might divide by zero if the student didn’t 
//  enter any grades. Division by zero is undefined in C++, which means that the 
//  implementation is permitted to do anything it likes. What does your C++ implementation
//  do in this case? Rewrite the program so that its behavior does not depend on how the 
//  implementation treats division by zero.

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main()
{
   // ask for and read the student's name
   cout << "Please enter your first name: ";
   string name;
   cin >> name;
   cout << "Hello, " << name << "!" << endl;

   // ask for and read the midterm and final grades
   cout << "Please enter your midterm and final exam grades: ";
   double midterm, final;
   cin >> midterm >> final;

   // ask for the homework grades
   cout << "Enter all your homework grades, "
      "followed by end-of-file: ";

   // the number and sum of grades read so far
   int count = 0;
   double sum = 0;

   // a variable into which to read
   double x;

   // invariant:
   //   we have read count grades so far, and
   //   sum is the sum of the first count grades
   while (cin >> x) {
      ++count;
      sum += x;
   }

   if (count == 0)
   {
      cout << endl << "No grades were entered. Your final grade cannot be calculated." << endl;
      return 1;
   }

   // write the result
   streamsize prec = cout.precision();
   cout << "Your final grade is " << setprecision(3) 
        << 0.2 * midterm + 0.4 * final + 0.4 * sum / count 
        << setprecision(prec) << endl;

   return 0;
}
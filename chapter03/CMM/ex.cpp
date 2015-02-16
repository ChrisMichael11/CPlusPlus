#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

int main()
{
   // ask for and read the integers
   cout << "Please enter the integers that are to be "
      "arranged into quartiles, followed by end-of-file: ";

   vector<double> values;
   int x;

   // invariant: values contains all of the integers read so far
   while (cin >> x)
      values.push_back(x);

   typedef vector<double>::size_type vec_sz;
   vec_sz size = values.size();

   // check that the user entered more than one value, since a 
   // single value would cause an error
   if (size < 2)
   {
      cout << endl << "You must enter at least two values. " 
         "Please try again." << endl;
      return 1;
   }

   // sort the values
   sort(values.begin(), values.end());

   // find the median of the entire set of values
   vec_sz mid = size/2;
   double median;
   median = size % 2 == 0 ? (values[mid] + values[mid-1]) / 2
      : values[mid];

   // find the size of the lower and upper sets
   vec_sz half_size = size % 2 == 0 ? mid : (mid % 2 == 0 ? mid - 1 : mid);

   // find the midpoint of the lower and upper sets
   vec_sz half_mid = half_size / 2;

   // find the median of the lower set, which is the lower quartile
   double lower_quartile;
   lower_quartile = half_size % 2 == 0 ? (values[half_mid] + values[half_mid-1]) / 2
      : values[half_mid];

   // find the median of the upper set, which is the upper quartile
   vec_sz upper_mid = size % 2 == 0 ? half_size + half_mid : half_size + half_mid + 1;
   double upper_quartile;
   upper_quartile = half_size % 2 == 0 ? (values[upper_mid] + values[upper_mid-1]) / 2
      : values[upper_mid];

   cout << "The quartiles are " << lower_quartile << ", " 
      << median << ", and " << upper_quartile << endl;

   return 0;
}
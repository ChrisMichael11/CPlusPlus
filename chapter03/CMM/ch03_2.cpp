//  Compute and print the quartiles (that is, the quarter of the numbers 
//  with the largest values, the next highest quarter, and so on) of a 
//  set of integers.

#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;				using std::cout;
using std::endl;			using std::sort;
using std::vector;

int main()
{
	//  Ask for integers
	cout <<  "Please enter the integers that are to be arranged into quartiles, followed"
			 " by end-of-file (CTRL+D).";
	
	vector<double> values;
	int x;
	
	//  INVARIANT:  values contains all integers read so far
	while (cin >> x)
		values.push_back(x);
	
	typedef vector<double>::size_type vec_sz;
	vec_sz size = values.size();
	
	//  Check that user entered more than one value (single value would cause error)
	if (size < 2)
	{	
		cout << endl << "You must enter at least two values, please try again." << endl;
		return 1;
	}
	
	//  Sort values
	sort(values.begin(), values.end());
	
	//  Find the median of the entire set of values
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (values[mid] + values[mid-1]) / 2 : values[mid];
	
	//  Find size of lower and upper sets
	vec_sz half_size = size % 2 == 0 ? mid : (mid % 2 == 0 ? mid -1 : mid);
	
	//  Find midpoint of lower and upper sets
	vec_sz half_mid = half_size / 2;
	
	//  Find median of lower set --> Lower Quartile
	double lower_quartile;
	lower_quartile = half_size % 2 == 0 ? (values[half_mid] + values[half_mid-1]) / 2
		: values[half_mid];
		
	//  Find the median of the upper set --> Upper Quartile
	vec_sz upper_mid = size % 2 == 0 ? half_size + half_mid : half_size + half_mid + 1;
	double upper_quartile;
	upper_quartile = half_size % 2 == 0 ? (values[upper_mid] + values[upper_mid-1]) / 2
		: values[upper_mid];
	
	cout <<  "The quartiles are " << lower_quartile <<", " << median << ", and " 
		 <<  upper_quartile << "!" << endl;
		 
	cout << "Lower Quartile\n" << lower_quartile << endl;
	cout << "Upper Quartile\n" << upper_quartile << endl;
	
	return 0;
}
 	
	
	
	
	
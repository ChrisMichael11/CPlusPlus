#include <algorithm>
#include <iomanip>
#ifndef __GNUC__
#include <ios>
#endif
#include <iostream>
#include <string>
#include <vector>

using std::cin;				using std::sort;
using std::cout;			using std::streamsize;
using std::endl;			using std::string;
using std::setprecision;	using std::vector;

int main()
{
	// Ask for and read students name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;
	
	//  Ask for and read midterm and final grades
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;
	
	//  Ask for and read homework grades
	cout << "Enter all your homework grades, "
			"followed by end-of-file (CTRL+D) ";
			
	vector<double> homework;
	double x;
	//  INVARIANT:  'homework' contains all homework grades read so far
	while (cin >> x)
		homework.push_back(x);
		
	//  Check that student entered some homework grades
	//  To find median, must know size of hw vector, create local variable
	//  vec_sz to deal with this.  typedef makes vec_sz a 'synonym' of 
	//  vector<double> type
#ifdef _MSC_VER
	typedef std::vector<double>::size_type vec_sz;
#else
	typedef vector<double>::size_type vec_sz;
#endif
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "You must enter your grades.  "
						"Please try again." << endl;
		return 1;
	}
	//  Sort grades
	sort(homework.begin(), homework.end());
	
	//  Compute median homework grade
	vec_sz mid = size/2;	//  'mid' of vec_sz vector defined
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
							: homework[mid];
	//  Median calculated first for even length vector.  If true, then mid 
	//  is really the mid and mid-1 positions of the vec_sz vector, take
	//  Average and get the 'median'.  If vector is of odd length, 'mid' is the median
	//  "? :" is if then else operator.
	//  if size % 2 == 0, then median = ((mid + mid -1)/2), if %2 /= 0
	//  median = mid
	
	//  Compute and write the final grade
	streamsize prec = cout.precision();
	cout <<  "Your final grade is " << setprecision(3)
		 <<  0.2 * midterm + 0.4 * final + 0.4 * median
		 <<  setprecision(prec) << endl;
	
	return 0;
}
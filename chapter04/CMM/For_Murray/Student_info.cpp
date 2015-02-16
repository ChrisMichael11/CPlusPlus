//  Source file for 'Student_info' - related functions
#include "Student_info.h"

using std::istream;		using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	//  Read and store student's name and midterm and final exam grades
	is >> s.name >> s.midterm >> s.final;
	
	read_hw(is, s.homework);	//  Read and store all HW grades
	return is;
}

//  Read HW grades from an input stream into a 'vector<double>'
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) { 
		//  Get rid of previous contents
		hw.clear();
		
		//  Read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);
			
		//  Clear the stream so next input will work
		in.clear();
	}
	return in;
}
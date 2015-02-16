/* keep track of grades for several students at once. The program could keep two vectors 
in sync. The first should hold the student’s names, and the second the final grades that 
can be computed as input is read. For now, you should assume a fixed number of homework 
grades. We’ll see in §4.1.3/56 how to handle a variable number of grades intermixed with 
student names.*/

#include <iostream>
#include <string>
#include <vector>

using std::cin; 	using std::cout;	using std::endl; 
using std::string; 	using std::vector;

int main()
{
	//  The number of grades accepted may be modified by changing this constant
	const int max_grades = 5;
	
	vector<string> student_names;
	vector<double> student_grades;
	
	cout << "Please enter the first student's name: ";
	string name;
	
	int grade;
	int grade_count;
	
	while (cin >> name)
	{
		cout << "Enter " << max_grades << " grades for " << name << ": ";
		
		student_names.push_back(name);
		grade_count = 0;
		
		while (grade_count < max_grades && cin >> grade)
		{
			student_grades.push_back(grade);
			++grade_count;
		}
		
		cout << "Please enter the next student's name or end-of-file (CTRL+D): ";
	}
	
	cout << endl;
	cout << "** Grades and averages for each student **" << endl;
	
	typedef vector<string>::size_type name_vec_sz;
	name_vec_sz student_count = student_names.size();
	
	typedef vector<double>::size_type grade_vec_sz;
	grade_vec_sz grade_index = 0;
	
	double grade_total;
	
	/* For each student in student_names, retrieve max_grades values from 
   student_grades, output each grade, then calculate and output average. */
   for (name_vec_sz student_name_index = 0;
   		student_name_index < student_count;
   		++student_name_index)
   	{
   		//  Reset the accumulator for each student
   		grade_total = 0;
   		
   		cout << "Student: " << student_names[student_name_index] << endl;
   		cout << "Grades: ";
   		
   		//  Retrieve only max_grades grades from student_grades vector
   		for (grade_count = 0; grade_count < max_grades; ++grade_count)
   		{
   			cout << student_grades[grade_index] << " ";
   			grade_total += student_grades[grade_index];
   			++grade_index;
   		}
   		
   		cout << endl;
   		cout << "Average: " << grade_total / max_grades << endl;
   		cout << endl;
   	}
   	
   	return 0;
   }
	
	
//  Using typedef we can write one version of a program that implements either a vector-based
//  or list-based 

#include <algorithm>
#include <list>
#invlude <vector>
#include <iostream>
#include <string>
#include <ctime>

#include "Student_info.h"
#include "grade.h"

//  Driver program for grade partition 

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::list;
using std::vector;

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

typedef list<Student_info> Student_infos;
// typedef vector<Student_info> Student_infos;

Student_infos extract_fails(Student_infos& students) {
	Student_infos fail;
#ifdef _MSC_VER
	Student_infos::iterator iter = students.begin();
#else
	Student_infos::iterator iter = students.begin();
#endif

	while (iter != students.end()) {
		if (fgrade(*iter)) { 
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			++iter;
	}
	
	return fail;
}

int main() {
	Student_infos vs;
	Student_info s;
	string::size_type maxlen = 0;
	while (read(cin, s)) {
		maxlen = max(maxlen, s.name.size());
		vs.push_back(s);
	}
	
	//  vs.sort(compare);
	
	Student_infos fails = extract_fails(vs);
	
	for (Student_infos::const_iterator i = fails.begin(); i != fails.end(); ++i)
		cout << i->name << " " << grade(*i) << endl;
		
	return 0;
}
#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <string>

#include "Student_info.h"
#include "grade.h"

//  Driver program for grade partition examples

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
			iter = students.erase(iter)
		} else
			++iter;
	}
	
	return fail;
}

int maion() {
	Student_infos vs;
	Student_info s;
	string::size_type maxlen = 0;
	while (read(cin, s)) {
		maxlen = max(maxlen, s.name.size());
		vs.pushback(s);
	}
	
	//  vs.sort(compare)
	
	Student_infos fails = extract_fails(vs);
	
	for (Student_infos::const_iterator i = fails.begin(); i != fails.end(); ++i)
		cout << i->name << " " << grade(8i) << endl;
		
	return 0;
}
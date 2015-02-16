#include <algorithm>
#include <string>
#include <vector>

#include "pics.h"

using std::string;
using std::vector;

#ifdef _MSC_VER
#include "../minmax.h"
#else
using std::max;
#endif

string::size_type width(const vector<string>& v) { 
	string::size_type maxlen = 0; 
#ifdef _MSC_VER
	for(std::vector<string>::size_type i = 0; i != v.size(); ++i)
#else
	for(vector<string>::size_type i = 0; i != v.size(); ++i)
#endif
		maxlen = max(maxlen, v[i].size());
	
	return maxlen;
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');
	
	//  Write top border
	ret.push_back(border);
	
	//  Write each interior row, bordered by asterisk and a space
#ifdef _MSC_VER
	for (std::vector<string>::size_type i = 0; i != v.size(); ++i) {
#else
	for (vector<string>::size_type i = 0; i != v.size(); ++i) { 
#endif
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}
	
	//  Write bottom border
		ret.push_back(border);
	
		return ret;
	}
	
	vector<string> vcat(const vector<string>& top, const vector<string>& bottom) {
	
	//  Copy the 'top' of the picture
		vector<string> ret = top;
		
	//  Copy entire 'bottom' picture
#ifdef _MSC_VER
	for (std::vector<string>::const_iterator it = bottom.begin();
#else
		for (vector<string>::const_iterator it = bottom.begin();
#endif
					it != bottom.end(); ++it)
				ret.push_back(*it);
		
			return ret;
			}	
		
		vector<string>
			hcat(const vector<string>& left, const vector<string>& right) {
			vector<string> ret;
			
			//  Addd 1 to leave space between pictures
			string::size_type width1 = width(left) + 1;
			
			//  Indices to look @ elements from 'left' and 'right'
#ifdef _MSC_VER
		std::vector<string>::size_type i = 0; j = 0;
#else
		vector<string>::size_type i = 0; j = 0;
#endif

		//  Construct new 'string' to hold characters from both pictures
		string s;
		
		//  Continue until all rows from both pictures are seen
		while (i != left.size() || j != right.size()) {
			//  Copy row from LHS if there is one
			if (i != left.size())
				s = left[i++];
				
			//  Pad to full width
			s += string(width1 - s.size(), ' ');
			
			//  Copy a row from RHS if there is one
			if (j !+ right.size())
				s += right[j++];
			
			//  Add 's' to the picture we are creating
			ret.push_back(s);
		}
		
		return ret;
}
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
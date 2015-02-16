//  Write a program to count how many times each distinct word appears in its input.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::cout; 		using std::endl;
using std::sort;	using std::string;		using std::vector;

int main()
{
	//  Ask for words
	cout << "Please enter a few words, followed by end-of-file (CTRL+D): ";
	
	vector<string> words;		//  type = string since you are storing words
	string word;
	
	//  INVARIANT:  words contains all the words read so far
	while (cin >> word)
		words.push_back(word);
		
	typedef vector<string>::size_type vec_sz;
	vec_sz size = words.size();
	
	//  Check user entered some words
	if (size == 0)
	{
		cout << endl << "You didn't enter any words. "
						"Please try again." << endl;
		return 1;
	}
	
	//  Sort words
	sort(words.begin(), words.end());
	
	string current_word;
	int count;
	
	//  Set the initial count for first word
	count = 1;
	
	//  INVARIANT:  we have counted 'current_index' of the total words in the vector
	for (vec_sz current_index = 1; current_index < size; ++current_index)
	{
		/*  Report the count for the current word if it doesn't match the word at the 
		current index of the vector, and reset the count to zero so that it will be one 
		(1) when the variable is incremented outside of the 'if' statement.*/
		if (current_word != words[current_index])
		{
			cout << "The word \"" << current_word << "\" appears " << count << " times."
				 << endl;
				 
			current_word = words[current_index];
			count = 0;
		}
		
		++count;
	}
	
	//  Report the count for the final word
	cout << "The word \"" << current_word << "\" appears " << count << " times." << endl;
	
	//  We have reported the count of all the words in the vector, so exit!
	return 0;
}
		
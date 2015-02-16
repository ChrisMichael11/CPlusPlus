//  Write a program to report the length of the longest and shortest string in its input.

/* Create two variables of type string::size_type: one to hold the shortest size, and one 
to hold the longest size. As the program proceeds through the input loop it first checks 
to see if shortest_size has been assigned a value other than zero. If not, it assigns it 
the first string’s size; otherwise it checks to see if the current string is shortest than
 shortest_size. It then checks to see if the current string is longer than longest_size.*/
 
 #include <iostream>
 #include <string>
 
 using std::cin;	using std::cout;	using std::endl; 	using std::string;
 
 int main()
 {
 	//  Ask for, and read in words
 	cout << "Please enter a few words, followed by end-of-file (CTRL+D): ";
 	
 	string::size_type shortest_size = 0;
 	string::size_type longest_size = 0;
 	
 	string word;
 	
 	while (cin >> word)
 	{
 		//  If shortest_size is zero, it hasn't been assigned yet
 		//  Otherwise, see if the current word is shorter.  If so, assign the current 
 		//  words size to 'shortest_size'.
 		if (shortest_size == 0 || word.size() < shortest_size)
 			shortest_size = word.size();
 			
 		//  See if the current word is longer than longest_size.  If so, assign current
 		//  word's size to longest_size.
 		if (word.size() > longest_size)
 			longest_size = word.size();
 	}
 	
 	//  Report the lengths of the shortest and longest words
 	cout << "The length of the shortest word is " << shortest_size
 		 << " and the length of the longest word is " << longest_size
 		 << endl;
 		 
 	return 0;
 }
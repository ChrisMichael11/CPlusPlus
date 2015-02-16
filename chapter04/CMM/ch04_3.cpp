//  Rewrite ch04_2 to allow more changes that allow i to grow without adjusting setw args

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int get_width(int n) {
  return log10(n) + 1;
}

int main() {
  int max = 100;
  
  for (int i = 1; i <= max; ++i) {
    cout << setw(get_width(max))
	 << i
	 << setw(get_width(max * max) + 1)
	 << i * i
	 << endl;
	 //  setw controlled by max width of output value
	 
  }
  
  return 0;
}
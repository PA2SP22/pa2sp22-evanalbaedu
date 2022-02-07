/*
 * Name        : scope.cpp
 * Author      : Luke Sathrum
 * Description : Example of overloading and default arguments
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Function Declaration for Dummy
void Dummy(int one);

// Program starts here
int main() {
  // Setup some local variables
  double one = 1;
  int two = 2;
  // Output one plus two
  cout << "local one + local two = " << (one + two) << endl;
  // Get output of Dummy()
  Dummy(two);

  // This ends our program
  return 0;
}

// Just a dummy function to show scope
void Dummy(int one) {
  // Note that one ^^^ is a local variable of the function Dummy
  int two = 5;
  cout << "Dummy() one + Dummy() two = " << (one + two) << endl;
}

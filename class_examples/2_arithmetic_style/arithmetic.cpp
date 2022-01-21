/*
 * Name        : arithmetic.cpp
 * Author      : Luke Sathrum
 * Description : Escape Sequences, Constants, Arithmetic, Increment/Decrement
 *               and Type Casting
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Program Execution Starts Here
int main() {
  // Some simple arithmetic
  cout << "int 6 + int 9 = " << (6 + 9) << endl;
  cout << "double 6.1 + double 9.2 = " << (6.1 + 9.2) << endl;
  cout << "int 6 + double 9.2 = " << (6 + 9.2) << endl;

  // Integer vs. Double division
  cout << "double 6.0 / double 9.0 = " << (6.0 / 9.0) << endl;
  cout << "int 6 / int 9 = " << (6 / 9) << endl;

  // This ends program execution
  return 0;
}

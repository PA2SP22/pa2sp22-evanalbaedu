/*
 * Name        : escape_constant.cpp
 * Author      : Luke Sathrum
 * Description : Samples of Escape Sequences and Constants
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Program Execution Starts Here
int main() {
  // Create some constants
  const char kTab = '\t';
  const double kPI = 3.1415927;

  // Calculate the area of a circle
  cout << "The area of circle with radius 5 is: " << kTab << 5 * 5 * kPI
       << endl;

  // Note we CANNOT change the value of a constant later
  // kPI = 3.1415;

  // This ends program execution
  return 0;
}

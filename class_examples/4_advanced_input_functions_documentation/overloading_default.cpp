/*
 * Name        : overloading_default.cpp
 * Author      : Luke Sathrum
 * Description : Example of overloading and default arguments
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * Adds the two values together and returns that number. The second parameter is
 * optional, i.e. it is a default argument.
 */
int Add(int one, int two = 0);

/*
 * An overloaded Add function for doubles. Once again the second parameter is
 * optional.
 */
double Add(double one, double two = 0.0);

// Program starts here
int main() {
  // Calling our functions in a cout statement
  cout << "Add(5) = " << Add(5) << endl;
  cout << "Add(5, 2) = " << Add(5, 2) << endl << endl;
  cout << "Add(5.5) = " << Add(5.5) << endl;
  cout << "Add(5.5, 2.2) = " << Add(5.5, 2.2) << endl;

  // This ends our program
  return 0;
}

// Notice how the default argument is NOT implemented here
int Add(int one, int two) {
  return one + two;
}

double Add(double one, double two) {
  return one + two;
}

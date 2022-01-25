/*
 * Name        : overloading_concepts.cpp
 * Author      : Luke Sathrum
 * Description : Looking at how we match overloaded functions and
 *               also at ambiguous overloading
 */

#include <iostream>
using std::cout;
using std::endl;

/*
 * This is a dummy class.
 */
class MyClass {
 public:
 /*
  * This is a dummy function that takes an int and a double
  */
  void F(int one, double two);
  /*
  * This is a dummy function that takes a double and an int
  */
  void F(double one, int two);
};

// Program starts here
int main() {
  // Create an object from the class
  MyClass object;
  // These will Match
  object.F(1, 5.0);
  object.F(1.0, 5);
  // This is ambiguous
//  object.F(1, 5);
  // As is this
//  object.F(1.0, 5.0);

  // This ends our program
  return 0;
}

void MyClass::F(int one, double two) {
  cout << "Matched F(int, double)\n";
  // To Prevent Warnings
  one++;
  two++;
}

void MyClass::F(double one, int two) {
  cout << "Matched F(double, int)\n";
  // To Prevent Warnings
  one++;
  two++;
}

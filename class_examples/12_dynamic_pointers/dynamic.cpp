/*
 * Name        : dynamic.cpp
 * Author      : Luke Sathrum
 * Description : Examples of creating pointers and dynamic variables.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program starts here
int main() {
  // Creating an integer pointer
  int *pointer;

  // Creating a dynamic variable
  // Note this variable is unnamed, you can only access it via pointers
  pointer = new int;

  // Assigning the value 42 to the dynamic variable
  *pointer = 42;

  // Output the values of *pointer and pointer
  cout << "*pointer == " << *pointer << endl;
  cout << "pointer  == " << pointer << endl << endl;

  // We'll point another pointer to our dynamic variable
  // Note the * here is NOT the dereferencing operator
  int *p2 = pointer;

  // Output the values of *p2 and p2
  cout << "*p2 == " << *p2 << endl;
  cout << "p2  == " << p2 << endl << endl;

  // We can also create a variable and assign it the value of the dynamic
  // variable
  int var = *p2;  // We could have used *pointer or *p2

  // Output the value of var
  cout << "var == " << var << endl;

  // This ends our program
  return 0;
}

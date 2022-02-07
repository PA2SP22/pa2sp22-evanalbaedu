/*
 * Name        : separate_compilation.cpp
 * Author      : Luke Sathrum
 * Description : Main file to help show separate compilation. We will
 *               create an instance of MyClass
 */

// Include our MyClass header file
#include "my_class.h"

// Program starts here
int main() {
  // Create a MyClass Object
  MyClass object;
  // Call the output member function
  object.Output();
  // This ends our program
  return 0;
}

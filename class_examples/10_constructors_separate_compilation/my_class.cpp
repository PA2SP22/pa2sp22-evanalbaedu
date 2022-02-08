/*
 * Name        : my_class.cpp
 * Author      : Luke Sathrum
 * Description : A dummy class to help show separate compilation
 *               This is the implementation file
 */

// We need to include the header file
#include "my_class.h"

MyClass::MyClass() : num_(0) {}

void MyClass::Output() {
  cout << "My number is: " << num_ << endl;
}

/*
 * Name        : my_class.h
 * Author      : Luke Sathrum
 * Description : A dummy class to help show separate compilation
 *               This is the interface file
 */

// Header guards to prevent multiple inclusion
#ifndef SATHRUM_MY_CLASS_H_
#define SATHRUM_MY_CLASS_H_

#include <iostream>
using std::cout;
using std::endl;

/*
 *  This class is a dummy class to help show how to
 *  break our class into an interface and implementation
 *  file. It will set a member variable to 1 on initialization
 *  and output it using the Output() function.
 */
class MyClass {
 public:
  /*
   * Constructor
   * Initialize our member variable num_ to 0
   */
  MyClass();
  /*
   * Output our member variable using cout
   */
  void Output();
 private:
  int num_;
};

#endif /* SATHRUM_MY_CLASS_H_ */

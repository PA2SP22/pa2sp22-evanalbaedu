/*
 * Name        : pointer_operators.cpp
 * Author      : Luke Sathrum
 * Description : Examples of creating pointers and using * and & operators.
 */

#include <iostream>
using std::cout;
using std::endl;

// Program starts here
int main() {
  // Creating some pointers
  int *p1, *p2;
  // Creating some integer variables
  int v1 = 1, v2 = 2;

  // Point p1 to variable v1
  p1 = &v1;
  // Point p2 to variable v2;
  p2 = &v2;

  // Output the values of v1 and *p1
  cout << "v1:  " << v1 << endl;
  cout << "*p1: " << *p1 << endl << endl;

  // Output the values of v2 and *p2
  cout << "v2:  " << v2 << endl;
  cout << "*p2: " << *p2 << endl << endl;

  // We can also output the memory addresses of p1 and p2
  // As well as v1 and v2
  cout << "p1:  " << p1 << endl;
  cout << "&v1: " << &v1 << endl << endl;

  cout << "p2:  " << p2 << endl;
  cout << "&v2: " << &v2 << endl << endl;

  // If you want to get real tricky you can output the memory address of
  // the pointers
  cout << "&p1: " << &p1 << endl;
  cout << "&p2: " << &p2 << endl;

  // This ends our program
  return 0;
}

/*
 * Name        : more_pointers.cpp
 * Author      : Luke Sathrum
 * Description : Example of typedef and arithmetic with pointers
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// A Type Definition for int*
// If for a class you can put this inside you class
typedef int* IntPtr;

// Program starts here
int main() {
  // Creating some pointers (how many?)
  int* p1, p2 = 5;

  // Create some pointers (how many?)
  IntPtr p3, p4;
  
  // Assign all three pointers the address of variable p2
  p1 = p3 = p4 = &p2;

  // Outputting the variables. They will all have garbage values
  // but pointers will have an 'x' in their garbage values
  cout << "p1: " << p1 << endl
       << "p2: " << p2 << endl
       << "p3: " << p3 << endl
       << "p4: " << p4 << endl;

  // Arithmetic on Pointers
  IntPtr a = new int[3];
  // Set our elements, this time using pointer arithmetic
  *(a) = 1;
  *(a + 1) = 2;
  *(a + 2) = 3;

  // Output the array
  for (int i = 0; i < 3; i++) {
    cout << "a[" << i << "] = " << a[i] << endl;
  }

  // Let's Perform some more arithmetic
  cout << "Memory address of a      : " << a << endl;
  // Increment a
  a++;
  cout << "Memory address of (a + 1): " << a << endl;
  // Increment a
  a++;
  cout << "Memory address of (a + 2): " << a << endl;

  // This ends our program
  return 0;
}

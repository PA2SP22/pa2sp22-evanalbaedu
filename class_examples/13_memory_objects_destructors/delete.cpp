/*
 * Name        : delete.cpp
 * Author      : Luke Sathrum
 * Description : Various examples of deleting memory
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program starts here
int main() {
  // Creating some pointers
  string garbage;
  int *p1, *p2, *array;
  int **multi_array;

  cout << "Creating Dynamic Stuff\n";

  // Creating a dynamic variable
  p1 = new int;
  *p1 = 5;
  cout << "*p1  = " << *p1 << endl;

  // Set p2 to point to the same place as p1
  p2 = p1;

  // Creating a dynamic array
  array = new int[5];

  // Set the first element to 0
  array[0] = 0;
  cout << "a[0] = " << array[0] << endl;

  // Creating a two-dimensional dynamic array of size 5 x 3
  multi_array = new int*[5];
  for (int i = 0; i < 5; i++) {
    multi_array[i] = new int[3];
  }

  cout << "Finished Creating Dynamic Stuff\n";
  cout << "Press enter to continue... ";
  getline(cin, garbage);

  cout << "Deleting Dynamic Stuff\n";
  // Cleanup
  // Delete the dynamic variable
  delete p1;
  // Note, p2 is now a dangling pointer
  // Output after memory is deleted
  cout << "*p1  = " << *p1 << endl;
  cout << "*p2  = " << *p1 << endl;

  // Best practice is to set dangling pointers to NULL
  p1 = NULL;
  p2 = NULL;

  // Delete the dynamic array
  delete[] array;
  // Output the first element after delete
  cout << "array[0] = " << array[0] << endl;

  // Best practice is to set dangling pointers to NULL
  array = NULL;

  // Delete the two-dimensional dynamic array
  for (int i = 0; i < 5; i++)
    delete[] multi_array[i];
  delete[] multi_array;

  // Best practice is to set dangling pointers to NULL
  multi_array = NULL;

  // What happens if we output a dangling pointer?
  if (p1 != NULL)
    cout << "*p1  = " << *p1 << endl;
  if (p2 != NULL)
    cout << "*p2  = " << *p1 << endl;

  cout << "Finished Deleting Dynamic Stuff\n";
  cout << "Press enter to continue... ";
  getline(cin, garbage);

  // This ends our program
  return 0;
}

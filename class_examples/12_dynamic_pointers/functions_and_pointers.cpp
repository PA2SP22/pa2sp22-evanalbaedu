/*
 * Name        : functions_and_pointers.cpp
 * Author      : Luke Sathrum
 * Description : Pointers as Parameters and Return Types.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*
 * This function uses a pointer to impersonate Call-By-Reference
 * @param int *temp - A pointer that points to a dynamic variable to be changed.
 */
void Sneaky(int *temp);

/*
 * This function will create and initialize a dynamic array and then return it
 * @param int size - The size of the array to be created
 * @return int* - A pointer to the created array
 */
int* CreateAndInitializeArray(int size);

// Program starts here
int main() {
  // Create a pointer that points to a dynamic variable
  int *pointer = new int;
  // Assigning the value 77 to the dynamic variable
  *pointer = 77;
  cout << "Before call to Sneaky() *p == " << *pointer << endl;

  // Call function sneaky
  Sneaky(pointer);

  cout << "After call to Sneaky() *p == " << *pointer << endl;
  cout << "Although we probably thought that it should still have been 77\n\n";

  // Let's point our pointer to a dynamically created array of size 5
  pointer = CreateAndInitializeArray(5);

  // Let's output the array
  cout << "The array contains the following values:\n";
  for (int i = 0; i < 5; i++) {
    cout << pointer[i] << endl;
  }

  // This ends our program
  return 0;
}

void Sneaky(int *temp) {
  // Assigning the value 99 to *temp
  *temp = 99;
  cout << "Inside function sneaky *temp == " << *temp << endl;
}

int* CreateAndInitializeArray(int size) {
  // Create the dynamically array
  int *a = new int[size];
  // Fill up the array
  for (int i = 0; i < size; i++)
    a[i] = i + 1;
  // Return a pointer the dynamic array
  return a;
}

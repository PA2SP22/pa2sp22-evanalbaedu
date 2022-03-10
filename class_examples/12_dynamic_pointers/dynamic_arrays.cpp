/*
 * Name        : dynamic_arrays.cpp
 * Author      : Luke Sathrum
 * Description : Examples of creating dynamic arrays. In this example we will
 *               dynamically create an array to hold student's names.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program starts here
int main() {
  // Creating a pointer to our array and an integer variable
  int size;
  string *students;

  // Get the size of the array
  cout << "How many students? ";
  cin >> size;
  cin.ignore(1000, '\n');
  // Create our dynamic array
  students = new string[size];

  // Get the names of the students
  for (int i = 0; i < size; i++) {
    cout << "Enter the first name of student " << (i + 1) << ": ";
    getline(cin, students[i]);
  }

  // Output the students as a comma separated list
  cout << "The students entered were: ";
  for (int i = 0; i < (size - 1); i++) {
    cout << students[i] << ", ";
  }
  cout << students[size - 1] << endl;

  // This ends our program
  return 0;
}

/*
 * Name        : dynamic_arrays.cpp
 * Author      : Luke Sathrum
 * Description : Example of dynamic arrays in C++
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * Outputs the names in the array
 * @param string[] students - The array of names to output
 * @param const int &size - The size of the array
 */
void Output(string students[], const int &size);
// Please note it could also have been written as:
//void Output(string *students, const int &size);

// Program starts here
int main() {
  // Setup our arrays and variables
  string *students;
  int size;

  // Get the size of the array
  cout << "How many students? ";
  cin >> size;
  cin.ignore(1000, '\n');

  // Create our dynamic array
  students = new string[size];

  // Get the names of the students
  for (int i = 0; i < size; i++) {
    cout << "Enter the full name of student " << (i + 1) << ": ";
    getline(cin, students[i]);
  }

  // Output the names
  cout << "The students entered were: ";
  Output(students, size);

  // This ends our program
  return 0;
}

void Output(string students[], const int &size) {
  int i;
  for (i = 0; i < size - 1; i++) {
    cout << students[i] << ", ";
  }
  cout << students[i] << endl;
}

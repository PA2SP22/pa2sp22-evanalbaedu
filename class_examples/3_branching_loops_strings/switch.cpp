/*
 * Name        : switch.cpp
 * Author      : Luke Sathrum
 * Description : Switch statements and enumerated types
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Program starts here
int main() {
  // Declare Variable
  int number;

  // Prompt for a number
  cout << "Please enter a number between 1 and 100: ";
  cin >> number;

  // Creating an enumerated type for grades.
  enum Grades {GRADE_A = 9, GRADE_B = 8, GRADE_C = 7, GRADE_D = 6};

  // switch
  switch (number / 10) {
    case GRADE_A:
    case 10:
      cout << "A";
      break;
    case GRADE_B:
      cout << "B";
      break;
    case GRADE_C:
      cout << "C";
      break;
    case GRADE_D:
      cout << "D";
      break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:
      cout << "F";
      break;
    default:
      cout << "Unknown Input";
  }
  cout << endl;

  // This ends our program
  return 0;
}

/*
 * Name        : loops.cpp
 * Author      : Luke Sathrum
 * Description : Examples of looping statements
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Program starts here
int main() {
  // Declare Variables
  int number, original_number;

  // Prompt for a number
  cout << "How many iterations? ";
  cin >> number;

  // Store the original
  original_number = number;

  // while statement
  cout << "while statement\n";
  while (number > 0) {
    cout << number << " ";
    number--;
  }
  cout << endl << endl << endl << endl;

  // Retrieve the original
  number = original_number;
  // do-while statement
  cout << "do-while statement\n";
  do {
    cout << number << " ";
    number--;
  } while (number > 0);
  cout << endl << endl << endl << endl;

  // for statement
  cout << "for statement\n";
  for (number = original_number; number > 0; number--) {
    cout << number << " ";
  }

  // This ends our program
  return 0;
}

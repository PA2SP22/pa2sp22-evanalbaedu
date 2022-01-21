/*
 * Name        : input_output.cpp
 * Author      : Luke Sathrum
 * Description : Outputting to the console and getting input from the user
 */

// Required Includes
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program Execution Starts Here
int main() {
  // Setup our variables
  int number_1, number_2;

  // Prompt the user
  cout << "Please enter an integer number: ";

  // Get a number from the user
  cin >> number_1;
  cout << "The number you entered was: " << number_1 << endl;

  // Get multiple numbers from the user
  cout << "Please enter 2 integer numbers separated by a space: ";
  cin >> number_1 >> number_2;
  cout << "You entered the numbers " << number_1 << " and " << number_2 << endl;

  // Get a string from a user
  string word;
  cout << "Please enter a single word:\n";
  cin >> word;
  cout << "The word you entered was:\n" << word << endl;

  // This ends program execution
  return 0;
}

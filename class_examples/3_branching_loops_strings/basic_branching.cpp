/*
 * Name        : basic_branching.cpp
 * Author      : Luke Sathrum
 * Description : Examples of branching statements. Note we use std::boolalpha to
 *               output booleans as true/false
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

// Program starts here
int main() {
  // Working on Boolean expressions
  cout << "-- && Operations --" << endl;
  cout << "true  &&  true: " << boolalpha << (true && true) << endl;
  cout << "true  && false: " << boolalpha << (true && false) << endl;
  cout << "false &&  true: " << boolalpha << (false && true) << endl;
  cout << "false && false: " << boolalpha << (false && false) << endl << endl;

  cout << "-- || Operations --" << endl;
  cout << "true  ||  true: " << boolalpha << (true || true) << endl;
  cout << "true  || false: " << boolalpha << (true || false) << endl;
  cout << "false ||  true: " << boolalpha << (false || true) << endl;
  cout << "false || false: " << boolalpha << (false || false) << endl << endl;

  cout << "-- ! Operations --" << endl;
  cout << "!true: " << boolalpha << !true << endl;
  cout << "!false: " << boolalpha << !false << endl << endl;

  // Declare Variables
  int number;

  // Prompt for a number
  cout << "Please enter a number between 1 and 100: ";
  cin >> number;

  // if-else statement
  if (number > 50)
    cout << "The number is high.";
  else
    cout << "The number is low.";
  cout << endl;

  // if-else-if-else
  if (number >= 90) {
    cout << "A\n";
    cout << "Great Job!";
  } else if (number >= 80) {
    cout << "B\n";
    cout << "Good Job!";
  } else if (number >= 70) {
    cout << "C\n";
    cout << "OK Job!";
  } else {
    cout << "D or F\n";
    cout << "Poor Job!";
  }
  cout << endl;

  // This ends our program
  return 0;
}

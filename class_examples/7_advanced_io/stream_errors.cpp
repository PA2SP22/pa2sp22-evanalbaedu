/*
 * Name        : stream_errors.cpp
 * Author      : Luke Sathrum
 * Description : Example of how to handle some stream errors.
 */

#include <iostream>
#include <limits>
#include <bitset>
using std::cout;
using std::cin;
using std::endl;

// Program starts here
int main() {
  // Create our variable to hold the integer from stdin
  int integer_to_get = 0;
  // Get the value
  cout << "Enter an integer (i.e. whole number): ";
  cin >> integer_to_get;
  // What state are our flags?
  cout << "\ngoodbit value: " << std::ios_base::goodbit << endl;
  cout << "badbit value:  " << std::ios_base::badbit << endl;
  cout << "eofbit value:  " << std::ios_base::eofbit << endl;
  cout << "failbit value: " << std::ios_base::failbit << endl;
  cout << "Current value: " << cin.rdstate() << endl;
  std::bitset<3> state(cin.rdstate());
  cout << "In binary: " << state << endl;

  // Reset flags and clear the buffer
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // Let's make sure we get an integer
  cout << "Please enter an integer: ";
  // Loop while input is bad. Could be any of the three error bits
  while (!(cin >> integer_to_get)) {
    cout << "Try Again!" << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  // Ouput the integer
  cout << "You entered: " << integer_to_get << endl;

  // This ends our program
  return 0;
}

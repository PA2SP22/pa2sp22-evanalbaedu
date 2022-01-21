/*
 * Name        : character_functions.cpp
 * Author      : Luke Sathrum
 * Description : Examples of character functions
 */

#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;

string print_pretty(bool value) {
  if (value)
    return "Yes";
  else
    return "No";
}

// Program starts here
int main() {
  // Setup some characters
  char char_a = 'A', char_b = 'b', char_c = '1', char_d = ',';

  // Testing characters, don't forget 0 is false and every other number is true
  cout << "Is char_a Alpha? " << print_pretty(isalpha(char_a)) << " ("
       << isalpha(char_a) << ")" << endl << endl;
  cout << "Is char_b Numeric? " << print_pretty(isdigit(char_b)) << " ("
       << isdigit(char_b) << ")" << endl << endl;
  cout << "Is char_c AlphaNumeric? " << print_pretty(isalnum(char_c)) << " ("
       << isalnum(char_c) << ")" << endl << endl;
  cout << "Is char_d Punctuation? " << print_pretty(ispunct(char_d)) << " ("
       << ispunct(char_d) << ")" << endl << endl;

  // Testing character case
  cout << "Is char_a lowercase? " << print_pretty(islower(char_a)) << " ("
       << islower(char_a) << ")" << endl << endl;

  // Convert to lowercase
  cout << "char_a to lower is: " << tolower(char_a) << endl << endl;
  // Since it returns an integer we need to cast it to an integer
  cout << "char_a to lower casted is: " << static_cast<char>(tolower(char_a))
       << endl;

  // This ends our program
  return 0;
}

/*
 * Name        : strings.cpp
 * Author      : Luke Sathrum
 * Description : Examples of strings and string functions
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program starts here
int main() {
  // Create our string
  string my_string;

  // Use = for assignment
  my_string = "Hello";
  // Use + for concatenation
  my_string = my_string + " World!";
  // Output the string
  cout << my_string << endl;

  // Let's create a second string that is all lowercase
  string lower_string = "hello world!";

  // Compare the string
  if (my_string > lower_string)
    cout << "\nmy_string > lower_string\n";
  else
    cout << "\nmy_string <= lower_string\n";

  // Strings are initialized to the empty string
  string empty_string;

  if (empty_string == "")
    cout << "\nempty_string is empty\n";

  // Getting Characters
  cout << "The character at location 0 is: " << my_string.at(0) << endl;
  cout << "The character at location 3 is: " << my_string.at(3) << endl;
  cout << "The character at location 4 is: " << my_string.at(4) << endl;
  // What if we go beyond our string
  //  cout << "The character at location 20 is: " << myString.at(20) << endl;

  // Setting Character
  my_string.at(0) = 'J';
  cout << "New Word: " << my_string << endl;
  my_string.at(4) = 'Y';
  cout << "New Word: " << my_string << endl;

  // Length
  cout << "The length of our string is: " << my_string.length() << endl << endl;

  // Length and Location in a for loop
  for (unsigned int i = 0; i < my_string.length(); i++) {
    cout << my_string.at(i) << endl;
  }

  // Set the string to something else to test string functions
  my_string = "HELLO";
  cout << "\nOur String is: " << my_string << endl;

  // Substring
  cout << "The substring is: " << my_string.substr(2, 2) << endl;

  // Empty
  if (my_string.empty() == true)
    cout << "The string is empty\n";
  else
    cout << "The string is not empty\n";

  // Find
  // Does the string ll exist?
  cout << "Does \"ll\" exist in our string?\n";
  if (my_string.find("ll") != string::npos)
    cout << "Found!\n";
  else
    cout << "Not Found\n";

  cout << "Does \"LL\" exist in our string?\n";
  if (my_string.find("LL") != string::npos)
    cout << "Found!\n";
  else
    cout << "Not Found\n";

  // This ends our program
  return 0;
}

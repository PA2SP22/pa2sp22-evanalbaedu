/*
 * Name        : stringstream.cpp
 * Author      : Luke Sathrum
 * Description : Examples of using a stringstream
 */

#include <iostream>
// New include
#include <sstream>
#include <string>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;
// New using statement
using std::stringstream;

// Program starts here
int main() {
  // Declare Variables
  int age, new_age;
  string name_age, name;
  // Declare our stringstream
  stringstream ss;
  // Get input from the user
  cout << "Please enter your age: ";
  cin >> age;
  cin.ignore(1000, '\n');
  cout << "Please enter your full name: ";
  getline(cin, name);

  // Show output via cout
  cout << "Hello " << name << " you are " << age << " years old." << endl;

  // Create a string that holds the same output
  ss << "Hello " << name << " you are " << age << " years old." << endl;
  name_age = ss.str();
  cout << name_age;

  // Attach a stringstream to our string variable
  stringstream ss_with_var(name_age);
  // Strip up until the number
  while (!isdigit(ss_with_var.peek())) {
    ss_with_var.ignore(1);
  }
  // Get the number
  ss_with_var >> new_age;
  cout << "The age extracted was: " << new_age << endl;

  // This ends our program
  return 0;
}

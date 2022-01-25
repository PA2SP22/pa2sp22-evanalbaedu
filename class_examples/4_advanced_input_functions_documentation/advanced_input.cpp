/*
 * Name        : advanced_input.cpp
 * Author      : Luke Sathrum
 * Description : Examples of advanced user input
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Program starts here
int main() {
  // Declare Variables
  int age, choice;
  string name;
  // Output a Menu
  cout << "Which simulation do you want to run?\n"
       << "(1) - Simple Input\n"
       << "(2) - getline() Input\n"
       << "(3) - Mixed Input w/ Errors\n"
       << "(4) - Mixed Input w/o Errors\n";
  // Get the choice
  cin >> choice;
  // Strip the newline
  cin.ignore(1000, '\n');
  // Run choices from the menu
  switch (choice) {
    case 1:
      // Simple Input
      cout << "Please enter your age: ";
      cin >> age;
      cout << "You are " << age << " years old." << endl;
      break;
    case 2:
      // getline() Input
      cout << "Please enter your full name: ";
      getline(cin, name);
      cout << "Hello " << name << endl;
      break;
    case 3:
      // Mixed input with errors
      cout << "Please enter your age: ";
      cin >> age;
      cout << "Please enter your full name: ";
      getline(cin, name);
      cout << "Hello " << name << " you are " << age << " years old." << endl;
      break;
    case 4:
      // Mixed input without errors
      cout << "Please enter your age: ";
      cin >> age;
      cin.ignore(1000, '\n');
      cout << "Please enter your full name: ";
      getline(cin, name);
      cout << "Hello " << name << " you are " << age << " years old." << endl;
      break;
    default:
      cout << "Invalid Selection!!!\n";
  }

  // This ends our program
  return 0;
}

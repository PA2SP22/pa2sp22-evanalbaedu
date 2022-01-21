/*
 * Name        : variables.cpp
 * Author      : Luke Sathrum
 * Description : Creating Variables and Assigning Values
 */

#include <string>
using std::string;

// Program Execution Starts Here
int main() {
  // Create some variables
  int one, two, three;
  double four, five;

  // Assign them values
  one = 1;
  two = 2;
  three = 3;
  four = 4.0;
  five = 5.0;

  // Create and initialize
  char w = 'w';
  bool decision = true;

  // Create and initialize alternate syntax
  string greeting("Hello World!");
  int ten(10);

  // To remove unused warnings...
  one = two = three = four = five = ten = w = decision = one, greeting = "";
  
  // This ends program execution
  return 0;
}

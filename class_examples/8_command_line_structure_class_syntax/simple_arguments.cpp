/*
 * Name        : simple_arguments.cpp
 * Author      : Luke Sathrum
 * Description : Example of how to use command line arguments.
 */

#include <iostream>
using std::cout;
using std::endl;

// Program starts here
int main(int argc, char *argv[]) {
  // Let the user know how many arguments there are
  if (argc == 1)
    cout << "There is one argument.\n\n";
  else
    cout << "There are " << argc << " arguments:" << endl;

  // Loop through each argument and print its number and value
  for (int i = 0; i < argc; i++)
    cout << i << " " << argv[i] << endl;

  // This ends our program
  return 0;
}

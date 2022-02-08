/*
 * Name        : error_example.cpp
 * Author      : Luke Sathrum
 * Description : Example of how to handle errors with command line arguments.
 */

#include <iostream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
using std::string;

/*
 * Useful when accepting input from stdin using the getline function.
 * Return the first character of a length 1 string. If the value is of
 * length 0 or of length > 1, return the null character ('\0').
 * @param value a string containing an expected single character
 * @return the first character of the string or null character ('\0')
 *         when value is length 0 or value is length > 1
 */
char StringToChar(string value);

// Program starts here
int main(int argc, char *argv[]) {
  string output;
  char single;
  // Make sure the user provided enough arguments
  if (argc > 1) {
    // Make sure all arguments are single characters
    for (int i = 1; i < argc; i++) {
      if ((single = StringToChar(argv[i])) == '\0') {
        cerr << "At lest one of your arguments is not a single character!"
             << endl;
        return 2;
      } else {
        output.append(1, single);
      }
    }
    cout << output << endl;
  } else {
    cerr << "Not enough arguments!\n";
    return 1;
  }
  // This ends our program
  return 0;
}

char StringToChar(string value) {
  if (value.length() == 1)
    return value.at(0);
  else
    return '\0';
}

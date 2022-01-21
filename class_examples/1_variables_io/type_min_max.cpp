/*
 * Name        : type_min_max.cpp
 * Author      : Luke Sathrum
 * Description : Example of how to get type minimums and maximums.
 */

#include <iostream>
#include <climits>
using std::cout;
using std::endl;

// Program starts here
int main() {
  // Bits in a Byte
  cout << "The number of bits in a byte " << CHAR_BIT << endl << endl;
  // short
  cout << "The minimum value of SHORT INT = " << SHRT_MIN << endl;
  cout << "The maximum value of SHORT INT = " << SHRT_MAX << endl;
  cout << "The maximum value of UNSIGNED SHORT INT = " << USHRT_MAX << endl
       << endl;
  // int
  cout << "The minimum value of INT = " << INT_MIN << endl;
  cout << "The maximum value of INT = " << INT_MAX << endl;
  cout << "The maximum value of UNSIGNED INT = " << UINT_MAX << endl << endl;
  // long
  cout << "The minimum value of LONG = " << LONG_MIN << endl;
  cout << "The maximum value of LONG = " << LONG_MAX << endl;
  cout << "The maximum value of UNSIGNED LONG = " << ULONG_MAX << endl << endl;
  // char
  cout << "The minimum value of CHAR = " << CHAR_MIN << endl;
  cout << "The maximum value of CHAR = " << CHAR_MAX << endl;
  // This ends our program
  return 0;
}

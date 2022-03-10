/*
 * Name        : assert.cpp
 * Author      : Luke Sathrum
 * Description : Testing code with built in assertions and try/catch
 */

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;

/* This function will do integer division on its two parameters and output the
 * quotient.
 * Pre-Condition: The divisor is an integer and CANNOT be 0
 * Post-Condition: Nothing was changed
 * @param num1 - The dividend
 * @param num2 - The divisor
 */
void Divide(int num1, int num2) {
  cout << "The quotient is: " << (num1 / num2);
}

// Program starts here
int main() {
  int val1, val2, test;
  cout << "Enter the dividend: ";
  cin >> val1;
  cout << "Enter the divisor: ";
  cin >> val2;
  cout << "Enter 1 to run assertion example, otherwise enter 2: ";
  cin >> test;
  if (test == 1) {
    assert(val2 != 0);
  } else {
    try {
      if (val2 == 0)
        throw string("Error: Divide by 0");
    } catch (const string &s) {
      cerr << s << endl;
      exit(1);
    }
  }
  Divide(val1, val2);
// This ends our program
  return 0;
}

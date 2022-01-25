/*
 * Name        : inc_dec_type_cast.cpp
 * Author      : Luke Sathrum
 * Description : Examples of Increment/Decrement Operators and Type Casting
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Program Execution Starts Here
int main() {
  // Increment and Decrement
  int a = 2, value_produced;

  // Postfix Example
  value_produced = 2 * (a++);
  cout << "a = " << a << "   value_produced = " << value_produced << endl;

  // Prefix Example
  a = 2;
  value_produced = 2 * (++a);
  cout << "a = " << a << "   value_produced = " << value_produced << endl;

  // Type Casting
  cout << "6 / 9 = " << (6 / 9) << endl;
  cout << "int 6 / typecasted int->double 9 = "
       << (6 / static_cast<double>(9)) << endl;

  // This ends program execution
  return 0;
}

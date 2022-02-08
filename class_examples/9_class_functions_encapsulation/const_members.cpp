/*
 * Name        : const_members.cpp
 * Author      : Luke Sathrum
 * Description : A class with const member functions
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// A simple class to show const member functions
class Simple {
 public:
  /*
   * Accessor for value_. Note this is a const function
   * @return int - The current value of the member variable value_
   */
  int value() const;
  /*
   * Mutator for value_. Sets the value of value_
   * @param int value - The new value to set value_ to
   */
  void set_value(int value);
 private:
  int value_;
};

// Program starts here
int main() {
  // Create our object
  Simple object;
  // Call our mutator
  object.set_value(10);
  // Call our accessor
  cout << "The value is: " << object.value() << endl;

  // This ends our program
  return 0;
}

int Simple::value() const {
  // Note this function should never change a member variable
  // The following will fail (compiler error)
  // value_ = 0;
  // We also CANNOT call a non-const function
//  if (value_ == 0)
//    set_value(10);
  return value_;
}

void Simple::set_value(int value) {
  value_ = value;
  // Note a non-const function CAN call a const function
  cout << "Inside set_value() the new value is: " << this->value() << endl;
}

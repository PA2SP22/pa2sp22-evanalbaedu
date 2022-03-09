/*
 * Name        : binary_unary_overload.cpp
 * Author      : Luke Sathrum
 * Description : Example of overloading binary operators.
 */

#include <iostream>
using std::cout;
using std::endl;

/*
 * A class to represent cents
 */
class Cents {
 public:
  /*
   * This constructor sets the internal cents_ member variable to the provided
   * argument.
   * @param int cents - The cents to set
   */
  Cents(int cents);
  /*
   * Accessor
   * Returns the value of the cents_ member variable
   * @return int - The value of cents_
   */
  int cents() const;
  /*
   * Mutator
   * Sets the value of the cents_ member variable
   * @param int cents - The cents to set
   */
  void set_cents(int cents);

 private:
  int cents_;
};

/*
 * Overload of + operator. Adds the cents_ member variable of two objects of
 * type Cents.
 * @param Cents c1 - The first object
 * @param Cents c2 - The second object
 * @return Cents - An object where the cents for the two parameters has been
 *                 added together
 */
const Cents operator +(const Cents &c1, const Cents &c2);

/*
 * Overload of - operator. Subtracts the cents_ member variable of two objects
 * of type Cents.
 * @param Cents c1 - The first object
 * @param Cents c2 - The second object
 * @return Cents - An object where the cents for the two parameters has been
 *                 subtracted from one another
 */
const Cents operator -(const Cents &c1, const Cents &c2);

/*
 * Overload of == operator. Compares the two objects.
 * @param Cents c1 - The first object
 * @param Cents c2 - The second object
 * @return bool - True if the cents are equal, otherwise false
 */
bool operator ==(const Cents &c1, const Cents &c2);

/*
 * Overload of unary - operator.
 * @param Cents c - The object to negate
 * @return Cents - An object where the cents have been negated
 */
const Cents operator -(const Cents &c);

// Program starts here
int main() {
  // Create some objects
  Cents cents1(6);
  Cents cents2(8);
  // Use overloaded Arithmetic Operators
  Cents cents_sum = cents1 + cents2;
  Cents cents_difference = cents1 - cents2;
  cout << "I have " << cents_sum.cents() << " cents after addition." << endl;
  cout << "I have " << cents_difference.cents() << " cents after subtraction."
       << endl;
  // Use overloaded unary -
    cents_difference = -cents_difference;
    cout << "I have " << cents_difference.cents() << " after unary minus."
         << endl;
  // Use overloaded equality operator
  if (cents_sum == cents_difference)
    cout << "The objects have the same values\n";
  else
    cout << "The objects do not have the same values\n";

  // This ends our program
  return 0;
}

Cents::Cents(int cents) {
  cents_ = cents;
}

int Cents::cents() const {
  return cents_;
}

void Cents::set_cents(int cents) {
  cents_ = cents;
}

// This function is NOT a member function!
const Cents operator +(const Cents &c1, const Cents &c2) {
  // Use the Cents constructor and operator+(int, int)
  return Cents(c1.cents() + c2.cents());
}

// This function is NOT a member function!
const Cents operator -(const Cents &c1, const Cents &c2) {
  // Use the Cents constructor and operator-(int, int)
  return Cents(c1.cents() - c2.cents());
}

bool operator ==(const Cents &c1, const Cents &c2) {
  return (c1.cents() == c2.cents());
}

const Cents operator -(const Cents &c) {
  return (-c.cents());
}

/*
 * Name        : friend_functions.cpp
 * Author      : Luke Sathrum
 * Description : Converting our overloaded operator functions to friend
 *               functions. Also adding an overload of <<
 */

#include <iostream>
using std::ostream;
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
  /*
   * Overload of + operator. Adds the cents_ member variable of two objects of
   * type Cents.
   * @param Cents c1 - The first object
   * @param Cents c2 - The second object
   * @return Cents - An object where the cents for the two parameters has been
   *                 added together
   */
  friend const Cents operator +(const Cents &c1, const Cents &c2);
  /*
   * Overload of - operator. Subtracts the cents_ member variable of two objects
   * of type Cents.
   * @param Cents c1 - The first object
   * @param Cents c2 - The second object
   * @return Cents - An object where the cents for the two parameters has been
   *                 subtracted from one another
   */
  friend const Cents operator -(const Cents &c1, const Cents &c2);
  /*
   * Overload of == operator. Compares the two objects.
   * @param Cents c1 - The first object
   * @param Cents c2 - The second object
   * @return bool - True if the cents are equal, otherwise false
   */
  friend bool operator ==(const Cents &c1, const Cents &c2);
  /*
   * Overload of unary - operator.
   * @param Cents c - The object to negate
   * @return Cents - An object where the cents have been negated
   */
  friend const Cents operator -(const Cents &c);
  /*
   * Overload of << operator.
   * @param ostream &out - The ostream object to output to
   * @param Cents c - The cents object to output from.
   * @return ostream& - The ostream object to allow for chaining of <<
   */
  friend ostream& operator <<(ostream &out, const Cents &c);

 private:
  int cents_;
};

// Program starts here
int main() {
  // Create some objects
  Cents cents1(0);
  Cents cents2(1);
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
  // Use overloaded assignment operator
  if (cents_sum == cents_difference)
    cout << "The objects have the same values\n";
  else
    cout << "The objects do not have the same values\n";
  // Using overloaded insertion operator
  cout << "The current value of cents_difference is: " << cents_difference
       << endl;

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

// These function are NOT a member function but they CAN access private members!
const Cents operator +(const Cents &c1, const Cents &c2) {
  // Use the Cents constructor and operator+(int, int)
  // Notice we can access private member variables
  return Cents(c1.cents_ + c2.cents_);
}

const Cents operator -(const Cents &c1, const Cents &c2) {
  return Cents(c1.cents_ - c2.cents_);
}

bool operator ==(const Cents &c1, const Cents &c2) {
  return (c1.cents_ == c2.cents_);
}

const Cents operator -(const Cents &c) {
  return (-c.cents_);
}

ostream& operator <<(ostream &out, const Cents &c) {
  out << c.cents_;
  // Return the ostream object to allow for chaining of <<
  return out;
}

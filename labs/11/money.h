/*
 * Name        : money.h
 * Author      : FILL IN
 * Description : Class Header File
 */

// ADD HEADER GUARD HERE

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using std::string;
using std::ostream;
using std::setfill;
using std::setw;

/*
 * Class Money.
 * A class that handles amounts of money in U.S. Currency.
 */
class Money {
 public:
  /*
   * Constructor #1.
   * Sets dollars and cents to the supplied values. Defaults to 0
   * @param int dollars - The value to set dollars_ to
   * @param int cents - The value to set cents_ to
   */
  Money(int dollars = 0, int cents = 0)
      : dollars_(dollars),
        cents_(cents) {
  }

  /*
   * Accessor for dollars_
   * @return int - The dollars_ value
   */
  int dollars() const {
    return dollars_;
  }

  /*
   * Accessor for cents_
   * @return int - The cents_ value
   */
  int cents() const {
    return cents_;
  }

  /*
   * Mutator for dollars_
   * @param int dollars - The value to set dollars_ to
   */
  void set_dollars(int dollars) {
    dollars_ = dollars;
  }

  /*
   * Mutator for cents_
   * @param int cents - The value to set cents_ to
   */
  void set_cents(int cents) {
    cents_ = cents;
  }

  /*
   * Overload of + operator. This is a friend function.
   * @param Money amount1 - The first object to add
   * @param Money amount2 - The second object to add
   * @return Money - The two objects added together
   */
  friend const Money operator +(const Money& amount1, const Money& amount2);

  /*
   * Overload of binary - operator. This is a friend function.
   * @param Money amount1 - The object to subtract from
   * @param Money amount2 - The object to be subtracted
   * @return Money - The result of the subtraction
   */
  friend const Money operator -(const Money& amount1, const Money& amount2);

  /*
   * Overload of == operator. This is a friend function.
   * @param Money amount1 - The first object to compare
   * @param Money amount2 - The second object to compare
   * @return bool - True if the objects have the same values, otherwise false
   */
  friend bool operator ==(const Money &amount1, const Money &amount2);

  /*
   * Overload of unary - operator. This is a friend function.
   * @param Money amount - The object to negate
   * @return Money - The result of the negation of the two member variables
   */
  friend const Money operator -(const Money &amount);

  /*
   * Overload of << operator.
   * Outputs the money values to the output stream.
   * Should be in the form $x.xx
   * @uses setw()
   * @uses setfill()
   * @param ostream &out - The ostream object to output to
   * @param Money amount - The Money object to output from.
   * @return ostream& - The ostream object to allow for chaining of <<
   */
  friend ostream& operator <<(ostream &out, const Money &amount);

 private:
  int dollars_;
  int cents_;
};

// REST OF HEADER GUARD GOES HERE

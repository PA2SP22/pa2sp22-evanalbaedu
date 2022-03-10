#include "money.h"

// This function definition provided as an example
const Money operator +(const Money& amount1, const Money& amount2) {
  // Get all the cents of object 1
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  // Get all the cents of object 2
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  // Add all the cents together
  int sum_all_cents = all_cents1 + all_cents2;
  // Handle the fact that money can be negative
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  // If the result of the operation was negative, negate final dollars and cents
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

// CLASS FUNCTION DEFINITIONS GO HERE
const Money operator -(const Money& amount1, const Money& amount2) {
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  int sum_all_cents = all_cents1 - all_cents2;
  int abs_all_cents = abs(sum_all_cents);
  int final_dollars = abs_all_cents / 100;
  int final_cents = abs_all_cents % 100;
  if (sum_all_cents < 0) {
    final_dollars = -final_dollars;
    final_cents = -final_cents;
  }
  return Money(final_dollars, final_cents);
}

bool operator ==(const Money &amount1, const Money &amount2) {
  int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
  int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
  return all_cents1 == all_cents2;
}

const Money operator -(const Money &amount) {
  return Money(-amount.dollars_, -amount.cents_);
}

ostream& operator <<(ostream &out, const Money &amount) {
  out << "$";

  if ((amount.dollars_ == 0) && (amount.cents_ < 0)) {
    out << "-";
  }
  out << amount.dollars_ << ".";
  out << setw(2) << setfill('0') << abs(amount.cents_);
  return out;
}


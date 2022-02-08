/*
 * Name        : accessor_mutator.cpp
 * Author      : Luke Sathrum
 * Description : Fleshing out our DayOfYear class with encapsulation and using
 *               accessor and mutator functions to deal with our private data.
 */

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

/*
 * This class represents a single day and can store information
 * about the day and month and then output that information
 */
class DayOfYear {
 public:
  // Member function declarations
  void Output();
  void Input(int month, int day);
  // Accessors
  int month();
  int day();
  // Mutators
  void set_month(int month);
  void set_day(int day);

 private:
  // Member Names
  int month_;
  int day_;
};

// Program starts here
int main() {
  // Create an object from the class
  DayOfYear today, bad;

  // Setup Today's Data using Mutators
  today.set_month(4);
  today.set_day(29);

  // Get Today's Data using Accessors
  cout << "Today's Month: " << today.month() << endl;
  cout << "Today's Day  : " << today.day() << endl;

  // Try to setup using bad data
  bad.set_month(0);
  bad.set_day(45);

  // Output's bad's data
  cout << "Bad's date is: ";
  bad.Output();

  // This ends our program
  return 0;
}

/*
 * This function will output the date, replacing the month number with its
 * string representation
 */
void DayOfYear::Output() {
  // Notice that we can access our member variable from our member function
  switch (month_) {
    case 1:
      cout << "January";
      break;
    case 2:
      cout << "February";
      break;
    case 3:
      cout << "March";
      break;
    case 4:
      cout << "April";
      break;
    case 5:
      cout << "May";
      break;
    case 6:
      cout << "June";
      break;
    case 7:
      cout << "July";
      break;
    case 8:
      cout << "August";
      break;
    case 9:
      cout << "September";
      break;
    case 10:
      cout << "October";
      break;
    case 11:
      cout << "November";
      break;
    case 12:
      cout << "December";
      break;
  }
  // Output the rest of the date
  cout << " " << day_ << endl;
}

/*
 * This function will set the variables month_ and day_ to the arguments
 * that are passed in.
 */
void DayOfYear::Input(int month, int day) {
  month_ = month;
  day_ = day;
}

/*
 * This accessor function will retrieve the month_.
 */
int DayOfYear::month() {
  return month_;
}

/*
 * This accessor function will retrieve the day_.
 */
int DayOfYear::day() {
  return day_;
}

/*
 * This mutator function will set the value of month_.
 * It does some simple checking to make sure 1 <= _month <= 12
 */
void DayOfYear::set_month(int month) {
  // Check to make sure month is correct
  if (month >= 1 && month <= 12) {
    month_ = month;
  } else {
    cerr << "Invalid month input, setting month to January\n";
    month_ = 1;
  }
}

/*
 * This mutator function will set the value of day_.
 * It does some simple checking to make sure 1 <= _day <= 31
 */
void DayOfYear::set_day(int day) {
  // Check to make sure month is correct
  if (day >= 1 && day <= 31) {
    day_ = day;
  } else {
    cerr << "Invalid day input, setting day to the first.\n";
    day_ = 1;
  }
}

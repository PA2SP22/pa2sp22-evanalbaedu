/*
 * Name        : encapsulation.cpp
 * Author      : Luke Sathrum
 * Description : Fleshing out our DayOfYear class with encapsulation using
 *               the public and private keywords.
 */

#include <iostream>
using std::cout;
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
 private:
  // Member Names
  int month_;
  int day_;
};

// Program starts here
int main() {
  // Create an object from the class
  DayOfYear today;
  // Now that our member variables are private
  // we cannot do the following
  today.month_ = 4;
  today.day_ = 29;

  // Instead we need to use our Input Function
  today.Input(4, 29);

  // Call our member function
  cout << "Today is ";
  today.Output();

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

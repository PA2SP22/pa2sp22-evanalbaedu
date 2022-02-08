/*
 * Name        : member_functions.cpp
 * Author      : Luke Sathrum
 * Description : Fleshing out our DayOfYear class with a member function to
 *               output our member variables
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
  // Member function prototype
  void Output();
  // Member Names
  int month_;
  int day_;
};

// Program starts here
int main() {
  // Create an object from the class
  DayOfYear today, yesterday;
  // Set our member variables for the today object
  today.month_ = 4;
  today.day_ = 29;
  // Set our member variable for the yesterday object
  yesterday.month_ = 4;
  yesterday.day_ = 28;

  // Call our member function
  cout << "Today is ";
  today.Output();
  cout << "Yesterday is ";
  yesterday.Output();

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

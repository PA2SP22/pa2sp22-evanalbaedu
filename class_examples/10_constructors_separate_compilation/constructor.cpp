/*
 * Name        : constructor.cpp
 * Author      : Luke Sathrum
 * Description : Fleshing out our DayOfYear class with a constructor.
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
  // Constructor
  DayOfYear(int month, int day);
  // Member function declarations
  void Output();
 private:
  // Member Names
  int month_;
  int day_;
};

// Program starts here
int main() {
  // Create an object from the class
  DayOfYear today(4, 29), first_of_month(4, 1);

  // Output our data
  cout << "Today is: ";
  today.Output();
  cout << "The first of the month was: ";
  first_of_month.Output();

  // This ends our program
  return 0;
}

/*
 * This constructor will set the variables month_ and day_ to the arguments
 * that are passed in.
 */
DayOfYear::DayOfYear(int month, int day) {
  month_ = month;
  day_ = day;
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

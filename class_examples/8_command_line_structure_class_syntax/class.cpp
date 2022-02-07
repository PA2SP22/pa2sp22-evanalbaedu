/*
 * Name        : class.cpp
 * Author      : Luke Sathrum
 * Description : Defining a class and then creating an object from it
 */

#include <iostream>
using std::cout;
using std::endl;

// Class Declaration
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
  // Currently we haven't defined our member functions so we can't use it
//  today.Output();

  // Output our member variables
  cout << "Today's date is " << today.month_ << "/" << today.day_ << endl;
  cout << "Yesterday's date was " << yesterday.month_
       << "/" << yesterday.day_ << endl;

  // This ends our program
  return 0;
}

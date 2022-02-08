/*
 * Name        : formatting.cpp
 * Author      : Luke Sathrum
 * Description : Formatting the output of our streams
 */

#include <iostream>
// For Manipulators we include <iomanip>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
// New Manipulators
using std::setw;
using std::setfill;

// Program starts here
int main() {
  // Let's output some text
  int ten = 10, nine = 9;
  cout << "T minus " << ten << " seconds and counting...\n";
  cout << "T minus " << nine << " seconds and counting...\n";

  // Before we change our settings lets save the default settings
  std::streamsize original_precision = cout.precision();
  std::ios::fmtflags original_flags = cout.flags();


  // We can format it better with width();
  cout << "\n\nT minus " << ten << " seconds and counting...\n";
  cout << "T minus " << setw(2) << nine << " seconds and counting...\n";

  // We can format numbers as well
  cout.setf(std::ios::showpoint | std::ios::fixed);
  double ten_d = 10, nine_d = 9;
  cout << "T minus " << ten_d << " seconds and counting...\n";
  cout << "T minus " << nine_d << " seconds and counting...\n";

  // Better formatting with precision
  cout.precision(2);
  cout << "\n\nT minus " << ten_d << " seconds and counting...\n";
  cout << "T minus " << nine_d << " seconds and counting...\n";

  // Or we can get rid of the precision all together
  cout.precision(0);
  cout << "\n\nT minus " << ten_d << " seconds and counting...\n";
  cout << "T minus " << nine_d << " seconds and counting...\n";

  // And we can get rid of the .
  cout.unsetf(std::ios::showpoint);
  cout << "\n\nT minus " << ten_d << " seconds and counting...\n";
  cout << "T minus " << nine_d << " seconds and counting...\n";

  // Fun with .fill()
  cout << "T minus " << setw(10) << setfill('.') << ten << endl;
  cout << "T minus " << setw(10) << setfill('.') << nine << endl;

  // Let's add a lot of flags
  cout.setf(std::ios::showpoint | std::ios::fixed |
            std::ios::scientific | std::ios::showpos);
  cout << "\n\nT minus " << ten_d << " seconds and counting...\n";
  cout << "T minus " << nine_d << " seconds and counting...\n";

  // Let's reset everything back to the default.
  cout.precision(original_precision);
  cout.flags(original_flags);
  cout << "\n\nT minus " << ten_d << " seconds and counting...\n";
  cout << "T minus " << nine_d << " seconds and counting...\n";

  // This ends our program
  return 0;
}

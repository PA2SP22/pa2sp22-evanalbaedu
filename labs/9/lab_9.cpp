/*
 * Name        : lab_9.cpp
 * Author      : FILL IN
 * Description : Working with Classes
 */
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/*
 * Class Spaceship.
 * A class to model a simple spaceship for a science fiction
 * game or story.
 */
class Spaceship {
 public:
  /*
   * Set the name of this Spaceship.
   * @param string name - The name for this Spaceship
   */
  void set_name(string name);

  /*
   * Set the top speed of this Spaceship.
   * @param double top_speed - The top speed for this Spaceship in warp
   */
  void set_top_speed(double top_speed);

  /*
   * Set the fuel source of this Spaceship.
   * @param string fuel_source - A fuel source for this Spaceship
   */
  void set_fuel_source(string fuel_source);

  /*
   * Set the crew capacity of this Spaceship.
   * @param int crew_capacity - A crew capacity for this Spaceship
   */
  void set_crew_capacity(int crew_capacity);

  /*
   * Get the name of this Spaceship.
   * @return string - The name of this Spaceship
   */
  string name() const;

  /*
   * Get the top speed of this Spaceship.
   * @return double - The top speed of this Spaceship
   */
  double top_speed() const;

  /*
   * Get the fuel source of this Spaceship.
   * @return string - The fuel source of this Spaceship
   */
  string fuel_source() const;

  /*
   * Get the crew capacity of this Spaceship.
   * @return int - The crew capacity of this Spaceship
   */
  int crew_capacity() const;

  /*
   * Get a string representation of this Spaceship's specifications.
   * The string will be formatted as
   * "NAME\n
   *  Top Speed:     Warp TOP_SPEED\n
   *  Fuel Source:   FUEL_SOURCE\n
   *  Crew Capacity: CREW_CAPACITY"
   * where NAME, TOP_SPEED (to two decimal places), FUEL_SOURCE, and
   * CREW_CAPACITY contain the values of the associated member variables.
   * @uses stringstream
   * @return string - A representation of this Spaceship's specifications
   */
  string ToString() const;

 private:
  string name_;
  float top_speed_;
  string fuel_source_;
  int crew_capacity_;
};

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// CODE HERE -- CLASS DEFINITION


// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";
  // Tests
  Spaceship enterprise;

  enterprise.set_name("USS Enterprise-D");
  yours = enterprise.name();
  actual = "USS Enterprise-D";
  Test(yours == actual, __LINE__, "set_name()/name()", yours, actual);

  enterprise.set_top_speed(9.6);
  Test(enterprise.top_speed() >= 9.59 && enterprise.top_speed() <= 9.61,
       __LINE__, "set_top_speed()/top_speed()");

  enterprise.set_fuel_source("Plasma");
  yours = enterprise.fuel_source();
  actual = "Plasma";
  Test(yours == actual, __LINE__, "set_fuel_source()/fuel_source()", yours,
       actual);

  enterprise.set_crew_capacity(5000);
  Test(enterprise.crew_capacity() == 5000, __LINE__,
       "set_crew_capacity()/crew_capacity()");

  yours = enterprise.ToString();
  actual = "USS Enterprise-D\n"
      "Top Speed:     Warp 9.60\n"
      "Fuel Source:   Plasma\n"
      "Crew Capacity: 5000";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);
  cout << "\n" << enterprise.ToString() << "\n\n";

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
  cout << "Be sure to run 'make style' to check for any style errors.\n"
       << "Please note that 'make style' does NOT check variable names or"
       << " indentation" << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, int line_number, string more_info, string yours,
          string actual) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
  if (!test) {
    if (yours != "!")
      cout << "Yours:  \"" << yours << '"' << endl;
    if (actual != "!")
      cout << "Actual: \"" << actual << '"' << endl;
    cout << "  Check Line " << line_number << " for more info" << endl;
  }
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}

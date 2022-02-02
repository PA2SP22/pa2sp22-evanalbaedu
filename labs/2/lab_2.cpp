/*
 * Name        : lab_2.cpp
 * Author      : Evan Alba
 * Description : Using Arithmetic to finish the functions MakeChange() and
 *               LaunchHumanCannonball()
 */

// Please note the header above. You need to include the name of the file, the
// author, a description of the program and any sources used
#include <iostream>
#include <cmath>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 7;
std::vector<int> failed_tests;

// Function Prototypes (DO NOT ALTER)
void MakeChange(int initial_value, int &quarters, int &dimes, int &nickels,
                int &pennies);
double LaunchHumanCannonball(double initial_velocity, double launch_angle);

// Create a Constant named kPI which is initialized to 3.1415927
// FILL IN
const double kPI = 3.1415927;
// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

/*
 * Given an initial integer value (representing change to be given, such as in a
 * financial transaction), break the value down into the number of quarters,
 * dimes, nickels, and pennies that would be given as change.
 * @param int initial_value - The amount of change to be broken down in pennies.
 * @param int quarters  - The number of quarters that come out of initial_value
 * @param int dimes - The number of dimes that come out of initial_value,
 *                    after quarters have been taken out
 * @param int nickels - The number of nickels that come out of initial_value,
 *                      after quarters and dimes have been taken out
 * @param int pennies - The number of pennies that come out of initial_value,
 *                      after quarters, dimes, and nickels have been taken out
 */
void MakeChange(int initial_value, int &quarters,
int &dimes, int &nickels, int &pennies) {
  quarters = 0;
  dimes = 0;
  nickels = 0;
  pennies = 0;
  while (initial_value > 0) {
    if ((initial_value / 25) >= 1) {
      quarters = (initial_value / 25);
      initial_value -= (quarters * 25);
    } else if ((initial_value / 10) >= 1) {
      dimes = (initial_value / 10);
      initial_value -= (dimes * 10);
    } else if ((initial_value / 5) >= 1) {
      nickels = (initial_value / 5);
      initial_value -= (nickels * 5);
    } else if ((initial_value / 1) >= 1) {
      pennies = (initial_value / 1);
      initial_value -= (pennies * 1);
    }
  }
}

/*
 * Computes the horizontal distance traveled by a human cannonball given an
 * initial velocity and launch angle. Simplified -- does not account for many
 * factors that affect projectile motion.
 * @param double initial_velocity - Represents the initial velocity of the
 *                                  human cannonball in meters/second
 * @param double launch_angle -  Represents the launch angle of the human
 *                               cannonball in degrees
 * @return double  - Represents the horizontal distance the human cannonball
 *                   will travel
 */
double LaunchHumanCannonball(double initial_velocity, double launch_angle) {
  // (1) Convert launch_angle from degrees to radians
  //     [radian_angle = degree_launch_angle * (kPI/180)]
  // CODE HERE
  double radian_angle = launch_angle * (kPI / 180);
  // (2) Compute final horizontal/x velocity
  //     [x_velocity = initial_velocity * cos(radian_angle)]
  // CODE HERE
  double x_velocity = initial_velocity * cos(radian_angle);
  // (3) Compute final vertical/y velocity
  //     [y_velocity = initial_velocity * sin(radian_angle) * -1]
  // CODE HERE
  double y_velocity = initial_velocity * sin(radian_angle) * -1;
  // (4) Compute time of flight
  //     [flight_time = (y_velocity) * 2 / -9.8]
  // CODE HERE
  double flight_time = (y_velocity) * 2 / -9.8;
  // (5) Compute horizontal/x distance travelled
  //     [x_distance = x_velocity * flight_time]
  // CODE HERE
  double x_distance = x_velocity * flight_time;
  return x_distance;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Test: " << num_of_tests << endl;
  string actual = "";

  int q = -1, n = -1, d = -1, p = -1;
  MakeChange(0, q, d, n, p);
  Test(((q == 0) && (d == 0) && (n == 0) && (p == 0)), __LINE__,
       "Change of $0.00");

  MakeChange(41, q, d, n, p);
  Test(((q == 1) && (d == 1) && (n == 1) && (p == 1)), __LINE__,
       "Change of $0.41");

  MakeChange(99, q, d, n, p);
  Test(((q == 3) && (d == 2) && (n == 0) && (p == 4)), __LINE__,
       "Change of $0.99");

  double value = LaunchHumanCannonball(25.0, 45.0);
  double scale = 0.01;  // round to nearest one-hundredth

  value = static_cast<int>(value / scale) * scale;
  Test((value <= 63.9) && (value >= 63.5), __LINE__, "Launch with (25, 45)");

  value = LaunchHumanCannonball(40.0, 60.0);
  value = static_cast<int>(value / scale) * scale;
  Test((value <= 141.5) && (value >= 141.1), __LINE__, "Launch with (40, 60)");

  value = LaunchHumanCannonball(10.0, 30.0);
  value = static_cast<int>(value / scale) * scale;
  Test((value <= 9.0) && (value >= 8.6), __LINE__, "Launch with (10, 30)");

  value = LaunchHumanCannonball(10.0, 90.0);
  value = static_cast<int>(value / scale) * scale;
  Test((value <= 0.2) && (value >= -0.2), __LINE__, "Launch with (10, 90)");

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
      cout << "Yours: \"" << yours << '"' << endl;
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

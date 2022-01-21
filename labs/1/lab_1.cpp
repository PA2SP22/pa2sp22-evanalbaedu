/*
 * Name        : lab_1.cpp
 * Author      : FILL IN
 * Description : FILL IN
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest(string user_name, char programmed_before, char my_character);
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // (1) Declare a string variable named user_name

  // (2) Declare a character variable named programmed_before and another named
  //     my_character. Initialize both of them to the value 'z'

  // (3) Display a welcome message to standard output

  // (4) Prompt the user for their first name

  // (5) Read the name from standard input and store in the variable user_name

  // (6) Display the message "Nice to meet you, NAME" where NAME is replaced
  //     with the value of user_name

  // (7) Ask the user if they have programmed before. Make sure you inform them
  //     that you want the answer as a single character (y/n)

  // (8): Read in the answer from standard input and store in the variable
  //      programmed_before

  
  // For testing (DO NOT ALTER)
  UnitTest(user_name, programmed_before, my_character);

  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest(string user_name, char programmed_before, char my_character) {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Test: " << num_of_tests << endl;
  string actual = "";

  Test(true, __LINE__, "Compiled");
  Test(my_character == 'z', __LINE__, "my_character initialized to 'z'");
  Test(user_name != "", __LINE__, "user_name != \"\"");
  Test(programmed_before == tolower('y') || programmed_before == tolower('n'),
       __LINE__, "programmed_before is 'y' or 'n'");

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
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

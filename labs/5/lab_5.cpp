/*
 * Name        : lab_5.cpp
 * Author      : FILL IN
 * Description : Working with Arrays
 */

#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/*
 * Create a string containing the contents of an array, each element separated
 * by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3".
 * @uses stringstream
 * @param int values[] - An array of integers
 * @param int size - The size of the integer array
 * @param char separator - The separator character to use in the returned
 *                         string. Defaults to ','
 * @return string - A string containing the contents of values separated by the
 *                  specified separator character
 */
string PrepareForDisplay(int values[], int size, char separator = ',');

/*
 * Test to see if an array contains a specified value.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int value - The value to search for within the array
 * @return bool - true if value is found in the array, otherwise false
 */
bool HasValue(int values[], int size, int value);

/*
 * Return the value from an array at a specified index.
 * @param int values -  An array of integers
 * @param int size - The size of the integer array
 * @param int index - The position in the array from which to return a value
 * @param bool error - A flag that will be set to true if index is invalid for
 *                     the array, else it will be set to false
 * @return int - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns 0 and sets error to true
 */
int ValueAt(int values[], int size, int index, bool& error);

/*
 * Return the sum of the values in an integer array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @return int - The sum of the values in the array
 */
int Sum(int values[], int size);

/*
 * Swap the positions of two values in an integer array. The two
 * index values must be valid for the array.
 * @param int values - An array of integers
 * @param int size - The size of the integer array
 * @param int index1 - The position of the first value to be swapped
 * @param int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
bool SwapValues(int values[], int size, int index1, int index2);

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 17;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// CODE HERE (FUNCTION DEFINITIONS)


// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";

  // Tests
  int values[] = { 3, 5, 7, 9, 11 };
  int size = 5;
  yours = PrepareForDisplay(values, size);
  actual = "3,5,7,9,11";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size)", yours,
       actual);
  yours = PrepareForDisplay(values, size, ' ');
  actual = "3 5 7 9 11";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size, ' ')", yours,
       actual);
  yours = PrepareForDisplay(values, size, ':');
  actual = "3:5:7:9:11";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size, ':')", yours,
       actual);
  Test(HasValue(values, size, 0) == false, __LINE__,
       "HasValue(values, size, 0)");
  Test(HasValue(values, size, 3) == true, __LINE__,
       "HasValue(values, size, 3)");
  Test(HasValue(values, size, 11) == true, __LINE__,
       "HasValue(values, size, 11)");
  bool error = true;
  Test(ValueAt(values, size, 0, error) == 3 && error == false, __LINE__,
       "ValueAt(values, size, 0, error)");
  Test(ValueAt(values, size, 5, error) == 0 && error == true, __LINE__,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(values, size, 4, error) == 11 && error == false, __LINE__,
       "ValueAt(values, size, 4, error)");
  Test(Sum(values, size) == 35, __LINE__, "Sum(values, size)");
  Test(Sum(values, 1) == 3, __LINE__, "Sum(values, 1)");
  Test(Sum(values, 0) == 0, __LINE__, "Sum(values, 0)");
  bool success;
  success = SwapValues(values, size, 0, 4);
  Test(values[0] == 11 && values[4] == 3 && success, __LINE__,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(values, size, 1, 3);
  Test(values[1] == 9 && values[3] == 5 && success, __LINE__,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(values, size, 2, 2);
  Test(values[2] == 7 && success, __LINE__, "SwapValues(values, size, 2, 2)");
  success = SwapValues(values, size, -2, 2);
  Test(values[2] == 7 && !success, __LINE__, "SwapValues(values, size, -2, 2)");
  success = SwapValues(values, size, 2, 10);
  Test(values[2] == 7 && !success, __LINE__, "SwapValues(values, size, 2, 10)");

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

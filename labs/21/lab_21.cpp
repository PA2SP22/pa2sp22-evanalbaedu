/*
 * Name        : lab_21.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for function templates.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <string>
#include <sstream>
#include "template.cpp"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 51;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";
  // Tests
  int int_values[] = { 3, 5, 7, 9, 11 };
  int size = 5;
  cout << "\n********Testing Integers********\n";
  yours = PrepareForDisplay(int_values, size);
  actual = "3,5,7,9,11";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size)", yours,
       actual);
  yours = PrepareForDisplay(int_values, size, ' ');
  actual = "3 5 7 9 11";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size, ' ')", yours,
       actual);
  yours = PrepareForDisplay(int_values, size, ':');
  actual = "3:5:7:9:11";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size, ':')", yours,
       actual);
  Test(HasValue(int_values, size, 0) == false, __LINE__,
       "HasValue(values, size, 0)");
  Test(HasValue(int_values, size, 3) == true, __LINE__,
       "HasValue(values, size, 3)");
  Test(HasValue(int_values, size, 11) == true, __LINE__,
       "HasValue(values, size, 11)");
  bool error = true;
  Test(ValueAt(int_values, size, 0, error) == 3 && error == false, __LINE__,
       "ValueAt(values, size, 0, error)");
  Test(ValueAt(int_values, size, 5, error) == 0 && error == true, __LINE__,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(int_values, size, 4, error) == 11 && error == false, __LINE__,
       "ValueAt(values, size, 4, error)");
  Test(Sum(int_values, size) == 35, __LINE__, "Sum(values, size)");
  Test(Sum(int_values, 1) == 3, __LINE__, "Sum(values, 1)");
  Test(Sum(int_values, 0) == 0, __LINE__, "Sum(values, 0)");
  bool success;
  success = SwapValues(int_values, size, 0, 4);
  Test(int_values[0] == 11 && int_values[4] == 3 && success, __LINE__,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(int_values, size, 1, 3);
  Test(int_values[1] == 9 && int_values[3] == 5 && success, __LINE__,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(int_values, size, 2, 2);
  Test(int_values[2] == 7 && success, __LINE__,
       "SwapValues(values, size, 2, 2)");
  success = SwapValues(int_values, size, -2, 2);
  Test(int_values[2] == 7 && !success, __LINE__,
       "SwapValues(values, size, -2, 2)");
  success = SwapValues(int_values, size, 2, 10);
  Test(int_values[2] == 7 && !success, __LINE__,
       "SwapValues(values, size, 2, 10)");

  double double_values[] = { 3.1, 5.2, 7.3, 9.4, 11.5 };
  cout << "\n********Testing Doubles********\n";
  yours = PrepareForDisplay(double_values, size);
  actual = "3.10,5.20,7.30,9.40,11.50";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size)", yours,
       actual);
  yours = PrepareForDisplay(double_values, size, ' ');
  actual = "3.10 5.20 7.30 9.40 11.50";
  Test(yours

  == actual,
       __LINE__, "PrepareForDisplay(values, size, ' ')", yours, actual);
  yours = PrepareForDisplay(double_values, size, ':');
  actual = "3.10:5.20:7.30:9.40:11.50";
  Test(yours

  == actual,
       __LINE__, "PrepareForDisplay(values, size, ':')", yours, actual);
  Test(HasValue(double_values, size, 0.0) == false, __LINE__,
       "HasValue(values, size, 0.0)");
  Test(HasValue(double_values, size, 3.10) == true, __LINE__,
       "HasValue(values, size, 3.10)");
  Test(HasValue(double_values, size, 11.50) == true, __LINE__,
       "HasValue(values, size, 11.50)");
  error = true;
  Test(ValueAt(double_values, size, 0, error) == 3.1 && error == false,
       __LINE__, "ValueAt(values, size, 0, error)");
  Test(ValueAt(double_values, size, 5, error) == 0 && error == true, __LINE__,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(double_values, size, 4, error) == 11.5 && error == false,
       __LINE__, "ValueAt(values, size, 4, error)");
  Test(Sum(double_values, size) == 36.5, __LINE__, "Sum(values, size)");
  Test(Sum(double_values, 1) == 3.10, __LINE__, "Sum(values, 1)");
  Test(Sum(double_values, 0) == 0.0, __LINE__, "Sum(values, 0)");
  success = SwapValues(double_values, size, 0, 4);
  Test(double_values[0] == 11.5 && double_values[4] == 3.1 && success, __LINE__,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(double_values, size, 1, 3);
  Test(double_values[1] == 9.4 && double_values[3] == 5.2 && success, __LINE__,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(double_values, size, 2, 2);
  Test(double_values[2] == 7.3 && success, __LINE__,
       "SwapValues(values, size, 2, 2)");
  success = SwapValues(double_values, size, -2, 2);
  Test(double_values[2] == 7.3 && !success, __LINE__,
       "SwapValues(values, size, -2, 2)");
  success = SwapValues(double_values, size, 2, 10);
  Test(double_values[2] == 7.3 && !success, __LINE__,
       "SwapValues(values, size, 2, 10)");

  string string_values[] = { "A", "B", "C", "D", "E" };
  cout << "\n********Testing Strings********\n";
  yours = PrepareForDisplay(string_values, size);
  actual = "A,B,C,D,E";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size)", yours,
       actual);
  yours = PrepareForDisplay(string_values, size, ' ');
  actual = "A B C D E";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size, ' ')", yours,
       actual);
  yours = PrepareForDisplay(string_values, size, ':');
  actual = "A:B:C:D:E";
  Test(yours == actual, __LINE__, "PrepareForDisplay(values, size, ':')", yours,
       actual);
  Test(HasValue(string_values, size, string(1, 'a')) == false, __LINE__,
       "HasValue(values, size, \"a\")");
  Test(HasValue(string_values, size, string(1, 'B')) == true, __LINE__,
       "HasValue(values, size, \"B\")");
  Test(HasValue(string_values, size, string(1, 'E')) == true, __LINE__,
       "HasValue(values, size, \"E\")");
  error = true;
  Test(ValueAt(string_values, size, 0, error) == "A" && error == false,
       __LINE__, "ValueAt(values, size, 0, error)");
  Test(ValueAt(string_values, size, 5, error) == "" && error == true, __LINE__,
       "ValueAt(values, size, 5, error)");
  Test(ValueAt(string_values, size, 4, error) == "E" && error == false,
       __LINE__, "ValueAt(values, size, 4, error)");
  Test(Sum(string_values, size) == "ABCDE", __LINE__, "Sum(values, size)");
  Test(Sum(string_values, 1) == "A", __LINE__, "Sum(values, 1)");
  Test(Sum(string_values, 0) == "", __LINE__, "Sum(values, 0)");
  success = SwapValues(string_values, size, 0, 4);
  Test(string_values[0] == "E" && string_values[4] == "A" && success, __LINE__,
       "SwapValues(values, size, 0, 4)");
  success = SwapValues(string_values, size, 1, 3);
  Test(string_values[1] == "D" && string_values[3] == "B" && success, __LINE__,
       "SwapValues(values, size, 1, 3)");
  success = SwapValues(string_values, size, 2, 2);
  Test(string_values[2] == "C" && success, __LINE__,
       "SwapValues(values, size, 2, 2)");
  success = SwapValues(string_values, size, -2, 2);
  Test(string_values[2] == "C" && !success, __LINE__,
       "SwapValues(values, size, -2, 2)");
  success = SwapValues(string_values, size, 2, 10);
  Test(string_values[2] == "C" && !success, __LINE__,
       "SwapValues(values, size, 2, 10)");

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

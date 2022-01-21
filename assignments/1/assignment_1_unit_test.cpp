/*
 * Name        : assignment_1_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Tests functions created for Assignment #1
 */

#include <iostream>
#include <string>
#include <climits>
#include "assignment_1.h"
using std::cout;
using std::endl;
using std::string;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
template<typename T>
void Test(bool test, int line_number, string more_info, T yours = T(),
          T actual = T());
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 42;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // Add code to manually test your functions below

  // To test your code (Comment Out to Manually Test)
  UnitTest();
  // This ends program execution
  return 0;
}

// Function Definitions
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  double dy, da;
  bool by, ba;
  string sy, sa, encrypted;

  // Setup double output
  cout.setf(std::ios::showpoint | std::ios::fixed);
  cout.precision(3);

  by = CheckAlphabetic("");
  ba = false;
  Test(by == ba, __LINE__, "CheckAlphabetic(\"\")", by, ba);

  by = CheckAlphabetic("ABC123");
  ba = false;
  Test(by == ba, __LINE__, "CheckAlphabetic(\"ABC123\")", by, ba);

  by = CheckAlphabetic("ABC");
  ba = true;
  Test(by == ba, __LINE__, "CheckAlphabetic(\"ABC\")", by, ba);

  by = CheckAlphabetic("ABCxyz");
  ba = true;
  Test(by == ba, __LINE__, "CheckAlphabetic(\"ABCxyz\")", by, ba);

  by = CheckAlphabetic("ABC\t");
  ba = false;
  Test(by == ba, __LINE__, "CheckAlphabetic(\"ABC\\t\")", by, ba);

  by = CheckAlphabetic(" ABC ");
  ba = false;
  Test(by == ba, __LINE__, "CheckAlphabetic(\" ABC \")", by, ba);

  by = CheckAlphabetic("!@#$%^&*()");
  ba = false;
  Test(by == ba, __LINE__, "CheckAlphabetic(\"!@#$%^&*()\")", by, ba);

  by = CheckAlphabetic("123ABC");
  ba = false;
  Test(by == ba, __LINE__, "CheckAlphabetic(\"123ABC\")", by, ba);

  by = CheckAlphabetic("AbCdEfGhIjKlMnOpQrStUvWxYz");
  ba = true;
  Test(by == ba, __LINE__, "CheckAlphabetic(\"AbCdEfGhIjKlMnOpQrStUvWxYz\")",
       by, ba);

  encrypted = "";
  by = EncryptString(encrypted, 5);
  ba = false;
  Test(by == ba, __LINE__, "EncryptString(\"\", 5)", by, ba);

  encrypted = "Hello World!";
  by = EncryptString(encrypted, 5);
  ba = false;
  Test(by == ba, __LINE__, "EncryptString(\"Hello World!\", 5)", by, ba);

  encrypted = "HelloWorld!";
  by = EncryptString(encrypted, 5);
  ba = false;
  Test(by == ba, __LINE__, "EncryptString(\"Hello World!\", 5)", by, ba);

  encrypted = "HelloWorld";
  by = EncryptString(encrypted, 5);
  sa = "MjqqtBtwqi";
  Test(encrypted == sa, __LINE__, "EncryptString(\"HelloWorld\", 5)", encrypted,
       sa);

  encrypted = "HelloWorld";
  by = EncryptString(encrypted, -5);
  sa = "CzggjRjmgy";
  Test(encrypted == sa, __LINE__, "EncryptString(\"HelloWorld\", -5)",
       encrypted, sa);

  encrypted = "HelloWorld";
  by = EncryptString(encrypted, 25);
  sa = "GdkknVnqkc";
  Test(encrypted == sa, __LINE__, "EncryptString(\"HelloWorld\", 25)",
       encrypted, sa);

  encrypted = "HelloWorld";
  by = EncryptString(encrypted, 26);
  sa = "HelloWorld";
  Test(encrypted == sa, __LINE__, "EncryptString(\"HelloWorld\", 26)",
       encrypted, sa);

  encrypted = "HelloWorld";
  by = EncryptString(encrypted, 1000000);
  sa = "VszzcKcfzr";
  Test(encrypted == sa, __LINE__, "EncryptString(\"HelloWorld\", 1000000)",
       encrypted, sa);

  encrypted = "HelloWorld";
  by = EncryptString(encrypted, -1000000);
  sa = "TqxxaIadxp";
  Test(encrypted == sa, __LINE__, "EncryptString(\"HelloWorld\", -1000000)",
       encrypted, sa);

  encrypted = "";
  by = DecryptString(encrypted, 5);
  ba = false;
  Test(by == ba, __LINE__, "DecryptString(\"\", 5)", by, ba);

  encrypted = "Hello World!";
  by = DecryptString(encrypted, 5);
  ba = false;
  Test(by == ba, __LINE__, "DecryptString(\"Hello World!\", 5)", by, ba);

  encrypted = "HelloWorld!";
  by = DecryptString(encrypted, 5);
  ba = false;
  Test(by == ba, __LINE__, "DecryptString(\"Hello World!\", 5)", by, ba);

  encrypted = "MjqqtBtwqi";
  by = DecryptString(encrypted, 5);
  sa = "HelloWorld";
  Test(encrypted == sa, __LINE__, "DecryptString(\"HelloWorld\", 5)", encrypted,
       sa);

  encrypted = "CzggjRjmgy";
  by = DecryptString(encrypted, -5);
  sa = "HelloWorld";
  Test(encrypted == sa, __LINE__, "DecryptString(\"HelloWorld\", -5)",
       encrypted, sa);

  encrypted = "GdkknVnqkc";
  by = DecryptString(encrypted, 25);
  sa = "HelloWorld";
  Test(encrypted == sa, __LINE__, "DecryptString(\"HelloWorld\", 25)",
       encrypted, sa);

  encrypted = "HelloWorld";
  by = DecryptString(encrypted, 26);
  sa = "HelloWorld";
  Test(encrypted == sa, __LINE__, "DecryptString(\"HelloWorld\", 26)",
       encrypted, sa);

  encrypted = "VszzcKcfzr";
  by = DecryptString(encrypted, 1000000);
  sa = "HelloWorld";
  Test(encrypted == sa, __LINE__, "DecryptString(\"HelloWorld\", 1000000)",
       encrypted, sa);

  encrypted = "TqxxaIadxp";
  by = DecryptString(encrypted, -1000000);
  sa = "HelloWorld";
  Test(encrypted == sa, __LINE__, "DecryptString(\"HelloWorld\", -1000000)",
       encrypted, sa);

  double values[] = { 10.5, 20.3, 30.2, 12.4 };

  dy = ComputeAverage(values, 4);
  da = 18.35;
  Test(dy > 18.349 && dy < 18.351, __LINE__,
       "ComputeAverage([10.5, 20.3, 30.2, 12.4])", dy, da);

  values[0] = 0, values[1] = 0, values[2] = 0, values[3] = 0;
  dy = ComputeAverage(values, 4);
  da = 0.0;
  Test(dy == da, __LINE__, "ComputeAverage([0, 0, 0, 0])", dy, da);

  values[0] = 5, values[1] = 7, values[2] = 11, values[3] = 7;
  dy = ComputeAverage(values, 4);
  da = 7.5;
  Test(dy > 7.499 && dy < 7.501, __LINE__, "ComputeAverage([5, 7, 11, 7])", dy,
       da);

  values[0] = -10.5, values[1] = -20.3, values[2] = -30.2, values[3] = -12.4;
  dy = ComputeAverage(values, 4);
  da = -18.35;
  Test(dy < -18.349 && dy > -18.351, __LINE__,
       "ComputeAverage([-10.5, -20.3, -30.2, -12.4])", dy, da);

  values[0] = -5, values[1] = 0, values[2] = 5, values[3] = 0;
  dy = ComputeAverage(values, 4);
  da = 0.0;
  Test(dy == da, __LINE__, "ComputeAverage([-5, 0, 5, 0])", dy, da);

  values[0] = -1.1, values[1] = 0, values[2] = 1.1;
  dy = FindMinValue(values, 3);
  da = -1.1;
  Test(dy < -1.099 && dy > -1.101, __LINE__, "FindMinValue([-1.1, 0, 1.1])", dy,
       da);

  values[0] = -3.1, values[1] = -3.2, values[2] = -3.3;
  dy = FindMinValue(values, 3);
  da = -3.3;
  Test(dy < -3.209 && dy > -3.301, __LINE__, "FindMinValue([-3.1, -3.2, -3.3])",
       dy, da);

  values[0] = 0, values[1] = 1.1, values[2] = 2.2;
  dy = FindMinValue(values, 3);
  da = 0;
  Test(dy == da, __LINE__, "FindMinValue([0, 1.1, 2.2])", dy, da);

  values[0] = 1, values[1] = 1, values[2] = 1;
  dy = FindMinValue(values, 3);
  da = 1.0;
  Test(dy > 0.999 && dy < 1.001, __LINE__, "FindMinValue([0, 0, 0])", dy, da);

  values[0] = INT_MAX, values[1] = INT_MAX, values[2] = INT_MAX;
  dy = FindMinValue(values, 3);
  da = INT_MAX;
  Test(dy == da, __LINE__, "FindMinValue([INT_MAX, INT_MAX, INT_MAX])", dy, da);

  values[0] = -1.1, values[1] = 0, values[2] = 1.1;
  dy = FindMaxValue(values, 3);
  da = 1.1;
  Test(dy > 1.099 && dy < 1.101, __LINE__, "FindMaxValue([-1.1, 0, 1.1])", dy,
       da);

  values[0] = -3.1, values[1] = -3.2, values[2] = -3.3;
  dy = FindMaxValue(values, 3);
  da = -3.1;
  Test(dy < -3.009 && dy > -3.101, __LINE__, "FindMaxValue([-3.1, -3.2, -3.3])",
       dy, da);

  values[0] = 0, values[1] = 1.1, values[2] = 2.2;
  dy = FindMaxValue(values, 3);
  da = 2.2;
  Test(dy > 2.199 && dy < 2.201, __LINE__, "FindMaxValue([0, 1.1, 2.2])", dy,
       da);

  values[0] = 1, values[1] = 1, values[2] = 1;
  dy = FindMaxValue(values, 3);
  da = 1.0;
  Test(dy > 0.999 && dy < 1.001, __LINE__, "FindMaxValue([0, 0, 0])", dy, da);

  values[0] = INT_MIN, values[1] = INT_MIN, values[2] = INT_MIN;
  dy = FindMaxValue(values, 3);
  da = INT_MIN;
  Test(dy == da, __LINE__, "FindMinValue([INT_MIN, INT_MIN, INT_MIN])", dy, da);

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
  cout << "Be sure to to check for any style errors.\n" << endl;
}

// For testing (DO NOT ALTER)
template<typename T>
void Test(bool test, int line_number, string more_info, T yours, T actual) {
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
    cout << "Yours:  " << std::boolalpha << yours << endl;
    cout << "Actual: " << std::boolalpha << actual << endl;
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


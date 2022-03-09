/*
 * Name        : lab_11.cpp
 * Author      : Luke Sathrum
 * Description : Unit_Test to test your class.
 */
#include <iostream>
#include <sstream>
#include <streambuf>
#include "money.h"
using std::cout;
using std::endl;

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
  // To help test your code (DO NOT ALTER)
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
  Money amount1(123, 45), amount2(10, 9);
  Money sum = amount1 + amount2;
  Money diff1 = amount1 - amount2;
  Money diff2 = amount2 - amount1;

  Test(sum.dollars() == 133 && sum.cents() == 54, __LINE__, "$123.45 + $10.09");
  Test(diff1.dollars() == 113 && diff1.cents() == 36, __LINE__,
       "$123.45 - $10.09");
  Test(diff2.dollars() == -113 && diff2.cents() == -36, __LINE__,
       "$10.09 - $123.45");
  amount1 = -amount1;
  Test(amount1.dollars() == -123 && amount1.cents() == -45, __LINE__,
       "-$123.45");
  Test((diff2 == diff1) == false, __LINE__, "$113.36 == $-113.36");

  amount1.set_dollars(-8);
  amount1.set_cents(-75);
  amount2.set_dollars(0);
  amount2.set_cents(50);
  sum = amount1 + amount2;
  diff1 = amount1 - amount2;
  diff2 = amount2 - amount1;

  Test(sum.dollars() == -8 && sum.cents() == -25, __LINE__, "$-8.75 + $0.50");
  Test(diff1.dollars() == -9 && diff1.cents() == -25, __LINE__,
       "$-8.75 - $0.50");
  Test(diff2.dollars() == 9 && diff2.cents() == 25, __LINE__, "$0.50 - $8.75");
  diff1 = -diff1;
  Test(diff1.dollars() == 9 && diff1.cents() == 25, __LINE__, "-$-9.25");
  Test((diff2 == diff1) == true, __LINE__, "$9.25 == $9.25");

  Money one(0, 10), two(0, -10), three(100, 2), four(-100, -2);
  std::streambuf* old_cout = cout.rdbuf();
  std::ostringstream capture_cout;
  cout.rdbuf(capture_cout.rdbuf());
  cout << Money(0, 10);
  cout.rdbuf(old_cout);
  yours = capture_cout.str();
  actual = "$0.10";
  Test(yours == actual, __LINE__, "<< Money(0, 10)", yours, actual);
  capture_cout.str("");
  cout.rdbuf(capture_cout.rdbuf());
  cout << Money(0, -10);
  cout.rdbuf(old_cout);
  yours = capture_cout.str();
  actual = "$-0.10";
  Test(yours == actual, __LINE__, "<< Money(0, -10)", yours, actual);
  capture_cout.str("");
  cout.rdbuf(capture_cout.rdbuf());
  cout << Money(100, 2);
  cout.rdbuf(old_cout);
  yours = capture_cout.str();
  actual = "$100.02";
  Test(yours == actual, __LINE__, "<< Money(100, 2)", yours, actual);
  capture_cout.str("");
  cout.rdbuf(capture_cout.rdbuf());
  cout << Money(-100, -2);
  cout.rdbuf(old_cout);
  yours = capture_cout.str();
  actual = "$-100.02";
  Test(yours == actual, __LINE__, "<< Money(-100, -2)", yours, actual);

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

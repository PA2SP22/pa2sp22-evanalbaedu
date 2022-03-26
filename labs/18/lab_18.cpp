/*
 * Name        : lab_18.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class SList.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include "sl_list.h"
#include "sl_node.h"

#include <iostream>
#include <sstream>
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
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 21;
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
  SLList list;
  stringstream full_list, half_list;
  for (int i = 999; i > 0; i--) {
    full_list << i << ", ";
    if (i < 500)
      half_list << i << ", ";
  }
  full_list << 0;
  half_list << 0;

  Test(list.size() == 0, __LINE__, "Default Constructor & size()");
  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.RemoveHead();
  Test(list.size() == 0, __LINE__, "RemoveHead() & size()");

  list.InsertHead(1);
  Test(list.size() == 1, __LINE__, "InsertHead(1) & size()");
  yours = list.ToString();
  actual = "1";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.RemoveHead();
  Test(list.size() == 0, __LINE__, "RemoveHead() & size()");
  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.InsertHead(10);
  list.InsertHead(20);
  Test(list.size() == 2, __LINE__, "InsertHead(10), InsertHead(20) & size()");
  yours = list.ToString();
  actual = "20, 10";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.RemoveHead();
  Test(list.size() == 1, __LINE__, "RemoveHead() & size()");
  yours = list.ToString();
  actual = "10";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.InsertHead(5);
  Test(list.size() == 2, __LINE__, "InsertHead(5) & size()");
  yours = list.ToString();
  actual = "5, 10";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Clear();
  Test(list.size() == 0, __LINE__, "Clear() & size()");
  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  for (unsigned int i = 0; i < 1000; i++)
    list.InsertHead(i);
  Test(list.size() == 1000, __LINE__, "InsertHead() \"HIGH LOAD\" & size()");
  yours = list.ToString();
  actual = full_list.str();
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  for (unsigned int i = 0; i < 500; i++)
    list.RemoveHead();
  Test(list.size() == 500, __LINE__, "RemoveHead() \"HIGH LOAD / 2\" & size()");
  yours = list.ToString();
  actual = half_list.str();
  Test(yours == actual, __LINE__, "ToString()", yours, actual);
  for (unsigned int i = 0; i < 600; i++)
    list.RemoveHead();
  Test(list.size() == 0, __LINE__, "RemoveHead() \"HIGH LOAD / 2\" & size()");

  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

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

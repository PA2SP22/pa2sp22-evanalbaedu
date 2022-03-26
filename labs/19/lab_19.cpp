/*
 * Name        : lab_19.cpp
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

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 44;
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
  std::stringstream full_head_list, half_head_list, full_tail_list,
      half_tail_list;
  for (int i = 999; i > 0; i--) {
    full_head_list << i << ", ";
    if (i < 500)
      half_head_list << i << ", ";
  }
  full_head_list << 0;
  half_head_list << 0;

  for (int i = 0; i < 999; i++) {
    full_tail_list << i << ", ";
    if (i < 499)
      half_tail_list << i << ", ";
  }
  full_tail_list << 999;
  half_tail_list << 499;

  Test(list.size() == 0, __LINE__, "Default Constructor & size()");
  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);
  Test(list.GetHead() == 0, __LINE__, "GetHead()");
  Test(list.GetTail() == 0, __LINE__, "GetTail()");

  list.RemoveHead();
  Test(list.size() == 0, __LINE__, "RemoveHead() & size()");

  list.RemoveTail();
  Test(list.size() == 0, __LINE__, "RemoveTail() & size()");

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

  list.InsertTail(5);
  Test(list.size() == 1, __LINE__, "InsertTail(5) & size()");
  yours = list.ToString();
  actual = "5";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.RemoveTail();
  Test(list.size() == 0, __LINE__, "RemoveTail() & size()");
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

  list.InsertHead(20);
  list.RemoveTail();
  Test(list.size() == 1, __LINE__, "InsertHead(20), RemoveTail() & size()");
  yours = list.ToString();
  actual = "20";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.InsertHead(5);
  Test(list.size() == 2, __LINE__, "InsertHead(5) & size()");
  yours = list.ToString();
  actual = "5, 20";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Clear();
  Test(list.size() == 0, __LINE__, "Clear() & size()");
  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.InsertHead(10);
  list.InsertHead(5);
  list.InsertTail(20);
  list.InsertTail(25);
  Test(
      list.size() == 4, __LINE__,
      "InsertHead(10), InsertHead(5), InsertTail(20), InsertTail(25) & size()");
  yours = list.ToString();
  actual = "5, 10, 20, 25";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  Test(list.GetHead() == 5, __LINE__, "GetHead()");
  Test(list.GetTail() == 25, __LINE__, "GetTail()");
  Test(list.size() == 4, __LINE__, "size()");
  yours = list.ToString();
  actual = "5, 10, 20, 25";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.RemoveHead();
  list.RemoveTail();
  list.RemoveHead();
  list.RemoveTail();
  Test(list.size() == 0, __LINE__,
       "RemoveHead(), RemoveTail(), RemoveHead(), RemoveTail() & size()");
  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  for (unsigned int i = 0; i < 1000; i++)
    list.InsertHead(i);
  Test(list.size() == 1000, __LINE__, "InsertHead() \"HIGH LOAD\" & size()");
  yours = list.ToString();
  actual = full_head_list.str();
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  for (unsigned int i = 0; i < 500; i++)
    list.RemoveHead();
  Test(list.size() == 500, __LINE__, "RemoveHead() \"HIGH LOAD / 2\" & size()");
  yours = list.ToString();
  actual = half_head_list.str();
  Test(yours == actual, __LINE__, "ToString()", yours, actual);
  for (unsigned int i = 0; i < 600; i++)
    list.RemoveHead();
  Test(list.size() == 0, __LINE__, "RemoveHead() \"HIGH LOAD / 2\" & size()");
  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  for (unsigned int i = 0; i < 1000; i++)
    list.InsertTail(i);
  Test(list.size() == 1000, __LINE__, "InsertTail() \"HIGH LOAD\" & size()");
  yours = list.ToString();
  actual = full_tail_list.str();
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  for (unsigned int i = 0; i < 500; i++)
    list.RemoveTail();
  Test(list.size() == 500, __LINE__, "RemoveTail() \"HIGH LOAD / 2\" & size()");
  yours = list.ToString();
  actual = half_tail_list.str();
  Test(yours == actual, __LINE__, "ToString()", yours, actual);
  for (unsigned int i = 0; i < 600; i++)
    list.RemoveTail();
  Test(list.size() == 0, __LINE__, "RemoveTail() \"HIGH LOAD / 2\" & size()");
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

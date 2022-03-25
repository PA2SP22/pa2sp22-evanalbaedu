/*
 * Name        : lab_20.cpp
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
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 46;
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

  Test(list.size() == 0, __LINE__, "Default Constructor & size()");
  yours = list.ToString();
  actual = "";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);
  Test(list.GetHead() == 0, __LINE__, "GetHead()");
  Test(list.GetTail() == 0, __LINE__, "GetTail()");

  list.Insert(10);
  Test(list.size() == 1, __LINE__, "Insert(10) & size()");
  yours = list.ToString();
  actual = "10";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Insert(50);
  Test(list.size() == 2, __LINE__, "Insert(50) & size()");
  yours = list.ToString();
  actual = "10, 50";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Insert(30);
  Test(list.size() == 3, __LINE__, "Insert(30) & size()");
  yours = list.ToString();
  actual = "10, 30, 50";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);
  Test(list.GetHead() == 10, __LINE__, "GetHead()");
  Test(list.GetTail() == 50, __LINE__, "GetTail()");

  list.Insert(5);
  Test(list.size() == 4, __LINE__, "Insert(5) & size()");
  yours = list.ToString();
  actual = "5, 10, 30, 50";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Insert(55);
  Test(list.size() == 5, __LINE__, "Insert(55) & size()");
  yours = list.ToString();
  actual = "5, 10, 30, 50, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Insert(20);
  Test(list.size() == 6, __LINE__, "Insert(20) & size()");
  yours = list.ToString();
  actual = "5, 10, 20, 30, 50, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Insert(40);
  Test(list.size() == 7, __LINE__, "Insert(40) & size()");
  yours = list.ToString();
  actual = "5, 10, 20, 30, 40, 50, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Insert(30);
  Test(list.size() == 8, __LINE__, "Insert(30) & size()");
  yours = list.ToString();
  actual = "5, 10, 20, 30, 30, 40, 50, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Insert(5);
  Test(list.size() == 9, __LINE__, "Insert(5) & size()");
  yours = list.ToString();
  actual = "5, 5, 10, 20, 30, 30, 40, 50, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  list.Insert(55);
  Test(list.size() == 10, __LINE__, "Insert(55) & size()");
  yours = list.ToString();
  actual = "5, 5, 10, 20, 30, 30, 40, 50, 55, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  cout << "\nYour List: " << list.ToString() << endl << endl;

  Test(list.RemoveFirstOccurence(1) == false, __LINE__,
       "RemoveFirstOccurence(1)");

  Test(list.RemoveFirstOccurence(5) == true, __LINE__,
       "RemoveFirstOccurence(5)");
  Test(list.size() == 9, __LINE__, "size()");
  yours = list.ToString();
  actual = "5, 10, 20, 30, 30, 40, 50, 55, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  Test(list.RemoveFirstOccurence(30) == true, __LINE__,
       "RemoveFirstOccurence(30)");
  Test(list.size() == 8, __LINE__, "size()");
  yours = list.ToString();
  actual = "5, 10, 20, 30, 40, 50, 55, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  Test(list.RemoveFirstOccurence(30) == true, __LINE__,
       "RemoveFirstOccurence(30)");
  Test(list.size() == 7, __LINE__, "size()");
  yours = list.ToString();
  actual = "5, 10, 20, 40, 50, 55, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  Test(list.RemoveFirstOccurence(55) == true, __LINE__,
       "RemoveFirstOccurence(55)");
  Test(list.size() == 6, __LINE__, "size()");
  yours = list.ToString();
  actual = "5, 10, 20, 40, 50, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  Test(list.RemoveFirstOccurence(10) == true, __LINE__,
       "RemoveFirstOccurence(10)");
  Test(list.size() == 5, __LINE__, "size()");
  yours = list.ToString();
  actual = "5, 20, 40, 50, 55";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  Test(list.GetHead() == 5, __LINE__, "GetHead()");
  Test(list.GetTail() == 55, __LINE__, "GetTail()");

  list.Clear();
  Test(list.size() == 0, __LINE__, "Clear() & size()");
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

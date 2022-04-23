/*
 * Name        : lab_24.cpp
 * Author      : Luke Sathrum
 * Description : Modifying your first Binary Search Tree
 */

#include <iostream>
#include <string>
#include <sstream>
#include "bs_tree.h"
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
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 67;
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
  BSTree tree;
  Test(tree.Remove(1) == false, __LINE__, "Default Constructor / Remove(1)");
  Test(
      tree.Insert(50) == true && tree.Insert(50) == false
          && tree.Insert(25) == true && tree.Insert(25) == false
          && tree.Insert(75) == true && tree.Insert(75) == false
          && tree.Insert(30) == true && tree.Insert(30) == false
          && tree.Insert(29) == true && tree.Insert(29) == false
          && tree.Insert(31) == true && tree.Insert(31) == false
          && tree.Insert(32) == true && tree.Insert(32) == false
          && tree.Insert(33) == true && tree.Insert(33) == false
          && tree.Insert(34) == true && tree.Insert(34) == false,
      __LINE__, "Insert Stress Test");
  Test(tree.GetSize() == 9, __LINE__, "GetSize()");
  actual = "25 29 30 31 32 33 34 50 75 ";
  Test(tree.FindMin() == 25, __LINE__, "FindMin()");
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  tree.Clear();
  Test(tree.GetSize() == 0, __LINE__, "Clear() / GetSize()");
  Test(tree.FindMin() == 0, __LINE__, "FindMin()");

  Test(tree.Insert(10) == true, __LINE__, "Insert(10)");
  Test(tree.GetSize() == 1, __LINE__, "GetSize()");
  actual = "10 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);
  Test(tree.Remove(10) == true, __LINE__, "Remove(10)");
  Test(tree.GetSize() == 0, __LINE__, "GetSize()");
  actual = "";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(
      tree.Insert(10) == true && tree.Insert(5) == true
          && tree.Insert(15) == true,
      __LINE__, "Insert(10), Insert(5), Insert(15)");
  Test(tree.GetSize() == 3, __LINE__, "GetSize()");
  Test(tree.FindMin() == 5, __LINE__, "FindMin()");
  actual = "5 10 15 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(1) == false, __LINE__, "Remove(1)");
  Test(tree.Remove(5) == true, __LINE__, "Remove(5)");
  Test(tree.GetSize() == 2, __LINE__, "GetSize()");
  Test(tree.FindMin() == 10, __LINE__, "FindMin()");
  actual = "10 15 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Insert(5) == true, __LINE__, "Insert(5)");
  Test(tree.GetSize() == 3, __LINE__, "GetSize()");
  Test(tree.FindMin() == 5, __LINE__, "FindMin()");
  actual = "5 10 15 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(15) == true, __LINE__, "Remove(15)");
  Test(tree.GetSize() == 2, __LINE__, "GetSize()");
  Test(tree.FindMin() == 5, __LINE__, "FindMin()");
  actual = "5 10 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Insert(15) == true, __LINE__, "Insert(15)");
  Test(tree.GetSize() == 3, __LINE__, "GetSize()");
  Test(tree.FindMin() == 5, __LINE__, "FindMin()");
  actual = "5 10 15 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(10) == true, __LINE__, "Remove(10)");
  Test(tree.GetSize() == 2, __LINE__, "GetSize()");
  Test(tree.FindMin() == 5, __LINE__, "FindMin()");
  actual = "5 15 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Insert(3) == true, __LINE__, "Insert(3)");
  Test(tree.GetSize() == 3, __LINE__, "GetSize()");
  Test(tree.FindMin() == 3, __LINE__, "FindMin()");
  actual = "3 5 15 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(15) == true, __LINE__, "Remove(15)");
  Test(tree.GetSize() == 2, __LINE__, "GetSize()");
  Test(tree.FindMin() == 3, __LINE__, "FindMin()");
  actual = "3 5 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Insert(10) == true, __LINE__, "Insert(10)");
  Test(tree.GetSize() == 3, __LINE__, "GetSize()");
  Test(tree.FindMin() == 3, __LINE__, "FindMin()");
  actual = "3 5 10 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(1) == false, __LINE__, "Remove(1)");
  Test(tree.Remove(100) == false, __LINE__, "Remove(100)");
  Test(tree.Remove(4) == false, __LINE__, "Remove(4)");
  Test(tree.Remove(7) == false, __LINE__, "Remove(7)");

  Test(tree.Remove(5) == true, __LINE__, "Remove(5)");
  Test(tree.GetSize() == 2, __LINE__, "GetSize()");
  Test(tree.FindMin() == 3, __LINE__, "FindMin()");
  actual = "3 10 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(10) == true, __LINE__, "Remove(10)");
  Test(tree.GetSize() == 1, __LINE__, "GetSize()");
  Test(tree.FindMin() == 3, __LINE__, "FindMin()");
  actual = "3 ";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(3) == true, __LINE__, "Remove(10)");
  Test(tree.GetSize() == 0, __LINE__, "GetSize()");
  Test(tree.FindMin() == 0, __LINE__, "FindMin()");
  actual = "";
  Test(tree.InOrder() == actual, __LINE__, "InOrder()", tree.InOrder(), actual);

  Test(tree.Remove(1) == false, __LINE__, "Remove(1)");

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

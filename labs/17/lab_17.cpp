/*
 * Name        : lab_17.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class SLNode.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include "sl_node.h"

#include <iostream>
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
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 8;
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
  SLNode node1;
  SLNode node2(1);

  Test(node1.contents() == 0, __LINE__, "Default Constructor & contents()");
  Test(node1.next_node() == NULL, __LINE__,
       "Default Constructor & next_node()");
  Test(node2.contents() == 1, __LINE__, "Overloaded Constructor & contents()");
  Test(node2.next_node() == NULL, __LINE__,
       "Overloaded Constructor & next_node()");

  SLNode* pNode = &node2;
  node1.set_next_node(&node2);
  Test(node1.next_node() == pNode, __LINE__, "set_next_node() & next_node()");

  pNode = &node1;
  // node1 and node2 now connect each to the other -- not something you should
  // ever do outside of a testing situation
  node2.set_next_node(pNode);
  Test(node2.next_node() == pNode, __LINE__, "set_next_node() & next_node()");

  node1.set_next_node(NULL);
  Test(node1.next_node() == NULL, __LINE__,
       "set_next_node(NULL) & next_node()");

  node2.set_next_node(NULL);
  Test(node2.next_node() == NULL, __LINE__,
       "set_next_node(NULL) & next_node()");

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

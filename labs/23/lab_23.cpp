/*
 * Name        : lab_23.cpp
 * Author      : Luke Sathrum
 * Description : Creating a Node for a Binary Search Tree
 */

#include <iostream>
#include <string>
#include <sstream>
#include "bst_node.h"
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
void UpdateContents(int& contents, int new_contents);
void UpdateLink(BSTNode*& link, BSTNode* new_link);
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 12;
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

  BSTNode node1;
  BSTNode node2(99);
  BSTNode node3(-1);

  Test(node1.GetContents() == 0, __LINE__,
       "Default Constructor / GetContents()");
  Test(node1.GetLeftChild() == NULL, __LINE__,
       "Default Constructor / GetLeftChild()");
  Test(node1.GetRightChild() == NULL, __LINE__,
       "Default Constructor / GetRightChild()");

  Test(node2.GetContents() == 99, __LINE__, "Constructor(99) / GetContents()");
  Test(node2.GetLeftChild() == NULL, __LINE__,
       "Constructor(99) / GetLeftChild()");
  Test(node2.GetRightChild() == NULL, __LINE__,
       "Constructor(99) / GetRightChild()");

  // node 2 is leftChild, node 3 is rightChild
  node1.SetLeftChild(&node2);
  Test(node1.GetLeftChild() == &node2, __LINE__,
       "SetLeftChild() / GetLeftChild()");
  node1.SetRightChild(&node3);
  Test(node1.GetRightChild() == &node3, __LINE__,
       "SetRightChild() / GetRightChild()");
  // swap children -- node3 leftChild, node2 rightChild
  UpdateLink(node1.GetLeftChild(), &node3);
  UpdateLink(node1.GetRightChild(), &node2);
  Test(node1.GetLeftChild() == &node3, __LINE__,
       "SetLeftChild() / GetLeftChild()");
  Test(node1.GetRightChild() == &node2, __LINE__,
       "SetRightChild() / GetRightChild()");

  node1.SetContents(42);
  Test(node1.GetContents() == 42, __LINE__, "SetContents(42) / GetContents()");
  UpdateContents(node1.GetContents(), 24);
  Test(node1.GetContents() == 24, __LINE__, "SetContents(24) / GetContents()");

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

void UpdateContents(int& contents, int new_contents) {
  contents = new_contents;
}

void UpdateLink(BSTNode*& link, BSTNode* new_link) {
  link = new_link;
}

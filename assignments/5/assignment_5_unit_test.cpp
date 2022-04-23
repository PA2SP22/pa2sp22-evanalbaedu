/*
 * Name        : assignment_5_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test for Templated Binary Search Tree
 */

#include <iostream>
#include <string>
#include <sstream>
#include "bs_treet.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "", string yours = "!", string actual =
              "!");
void UnitTest();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << "There are 59 tests.\n" << string(temp.length() - 1, '-')
       << endl;
  // Tests
  cout << "******BSTNodeT<int>******" << endl;
  BSTNodeT<int> inode1;
  BSTNodeT<int> inode2(99);
  BSTNodeT<int> inode3(-1);

  Test(inode1.GetContents() == 0, "Default Constructor / GetContents()");
  Test(inode1.GetLeft() == NULL, "Default Constructor / GetLeft()");
  Test(inode1.GetRight() == NULL, "Default Constructor / GetRight()");

  Test(inode2.GetContents() == 99, "Constructor(99) / GetContents()");
  Test(inode2.GetLeft() == NULL, "Constructor(99) / GetLeft()");
  Test(inode2.GetRight() == NULL, "Constructor(99) / GetRight()");

  // node 2 is leftChild, node 3 is rightChild
  inode1.SetLeft(&inode2);
  Test(inode1.GetLeft() == &inode2, "SetLeft() / GetLeft()");
  inode1.SetRight(&inode3);
  Test(inode1.GetRight() == &inode3, "SetRight() / GetRight()");

  cout << "******BSTNodeT<char>******" << endl;
  BSTNodeT<char> cnode1;
  BSTNodeT<char> cnode2('A');
  BSTNodeT<char> cnode3('a');

  Test(cnode1.GetContents() == '\0', "Default Constructor / GetContents()");
  Test(cnode1.GetLeft() == NULL, "Default Constructor / GetLeft()");
  Test(cnode1.GetRight() == NULL, "Default Constructor / GetRight()");

  Test(cnode2.GetContents() == 'A', "Constructor('A') / GetContents()");
  Test(cnode2.GetLeft() == NULL, "Constructor('A') / GetLeft()");
  Test(cnode2.GetRight() == NULL, "Constructor('A') / GetRight()");

  // node 2 is leftChild, node 3 is rightChild
  cnode1.SetLeft(&cnode2);
  Test(cnode1.GetLeft() == &cnode2, "SetLeft() / GetLeft()");
  cnode1.SetRight(&cnode3);
  Test(cnode1.GetRight() == &cnode3, "SetRight() / GetRight()");

  cout << "******BSTNodeT<string>******" << endl;
  BSTNodeT<string> snode1;
  BSTNodeT<string> snode2("Hello");
  BSTNodeT<string> snode3("Goodbye");

  Test(snode1.GetContents() == "", "Default Constructor / GetContents()");
  Test(snode1.GetLeft() == NULL, "Default Constructor / GetLeft()");
  Test(snode1.GetRight() == NULL, "Default Constructor / GetRight()");

  Test(snode2.GetContents() == "Hello",
       "Constructor(\"Hello\") / GetContents()");
  Test(snode2.GetLeft() == NULL, "Constructor(\"Hello\") / GetLeft()");
  Test(snode2.GetRight() == NULL, "Constructor(\"Hello\") / GetRight()");

  // node 2 is leftChild, node 3 is rightChild
  snode1.SetLeft(&snode2);
  Test(snode1.GetLeft() == &snode2, "SetLeft() / GetLeft()");
  snode1.SetRight(&snode3);
  Test(snode1.GetRight() == &snode3, "SetRight() / GetRight()");

  cout << "******BSTreeT<int>******" << endl;

  // Setup the BST
  BSTreeT<int> tree;
  BSTNodeT<int> *tree_pointer;
  string actual = "";
  Test(tree.GetSize() == 0, "Default Constructor / GetSize()");

  Test(tree.ToStringForwards() == actual, "ToStringForwards()",
       tree.ToStringForwards(), actual);
  Test(tree.ToStringBackwards() == actual, "ToStringBackwards()",
       tree.ToStringBackwards(), actual);
  Test(tree.Insert(50) == 1, "Insert(50)");
  Test(tree.GetSize() == 1, "GetSize()");
  actual = "50";
  Test(tree.ToStringForwards() == actual, "ToStringForwards()",
       tree.ToStringForwards(), actual);
  Test(tree.ToStringBackwards() == actual, "ToStringBackwards()",
       tree.ToStringBackwards(), actual);
  Test(tree.Insert(20) == 1, "Insert(20)");
  Test(tree.GetSize() == 2, "GetSize()");
  actual = "20, 50";
  Test(tree.ToStringForwards() == actual, "ToStringForwards()",
       tree.ToStringForwards(), actual);
  actual = "50, 20";
  Test(tree.ToStringBackwards() == actual, "ToStringBackwards()",
       tree.ToStringBackwards(), actual);

  Test(tree.Insert(80) == 1, "Insert(80)");
  Test(tree.GetSize() == 3, "GetSize()");
  actual = "20, 50, 80";
  Test(tree.ToStringForwards() == actual, "ToStringForwards()",
       tree.ToStringForwards(), actual);
  actual = "80, 50, 20";
  Test(tree.ToStringBackwards() == actual, "ToStringBackwards()",
       tree.ToStringBackwards(), actual);

  Test(tree.Insert(80) == 2, "Insert(80)");
  Test(tree.GetSize() == 3, "GetSize()");
  actual = "20, 50, 80";
  Test(tree.ToStringForwards() == actual, "ToStringForwards()",
       tree.ToStringForwards(), actual);
  actual = "80, 50, 20";
  Test(tree.ToStringBackwards() == actual, "ToStringBackwards()",
       tree.ToStringBackwards(), actual);

  Test(tree.Exists(50) == true, "Exists(50)");
  Test(tree.Exists(0) == false, "Exists(0)");

  tree_pointer = tree.Get(50);
  Test(tree_pointer->GetContents() == 50, "Get(50)");

  tree_pointer = tree.Get(0);
  Test(tree_pointer == NULL, "Get(0)");

  Test(tree.Remove(80) == 1, "Remove(80)");
  Test(tree.GetSize() == 3, "GetSize()");
  actual = "20, 50, 80";
  Test(tree.ToStringForwards() == actual, "ToStringForwards()",
       tree.ToStringForwards(), actual);
  actual = "80, 50, 20";
  Test(tree.ToStringBackwards() == actual, "ToStringBackwards()",
       tree.ToStringBackwards(), actual);

  Test(tree.Remove(80) == 0, "Remove(80)");
  Test(tree.GetSize() == 2, "GetSize()");
  actual = "20, 50";
  Test(tree.ToStringForwards() == actual, "ToStringForwards()",
       tree.ToStringForwards(), actual);
  actual = "50, 20";
  Test(tree.ToStringBackwards() == actual, "ToStringBackwards()",
       tree.ToStringBackwards(), actual);

  Test(tree.Remove(80) == -1, "Remove(80)");

  tree.Clear();
  Test(tree.GetSize() == 0, "Clear() / GetSize()");
  actual = "";
  Test(tree.ToStringForwards() == actual, "ToStringForwards()",
       tree.ToStringForwards(), actual);
  Test(tree.ToStringBackwards() == actual, "ToStringBackwards()",
       tree.ToStringBackwards(), actual);

  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n" << "Passed: " << ut_passed << " / "
       << ut_total << endl << "Failed: " << ut_failed << " / " << ut_total
       << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info, string yours, string actual) {
  static int test_number = 1;
  if (test) {
    cout << "PASSSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED  TEST ";
    ut_failed++;
  }
  cout << test_number << " " << more_info << "!" << endl;
  if (!test) {
    if (yours != "!")
      cout << "Yours: \"" << yours << '"' << endl;
    if (actual != "!")
      cout << "Actual: \"" << actual << '"' << endl;
  }
  ut_total++;
  test_number++;
}


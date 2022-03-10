/*
 * Name        : assignment_3a_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class TodoItem.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <sstream>
#include <streambuf>
#include "todo_item.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
template <typename T>
void Test(bool test, string more_info = "", T yours = T(),
          T expected = T());
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 18;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // START DEBUGGING CODE

  // END DEBUGINH CODE
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

  // Tests
  string desc1 = "Go to Store";
  string desc2 = "Brush Teeth @ 8PM";
  string expected, yours;
  string to_file;

  cout << "*****TodoItem(\"Go to Store\")*****\n";
  TodoItem item(desc1);
  Test(item.description() == desc1, "description()", item.description(), desc1);
  Test(item.priority() == 1, "priority()", item.priority(), 1);
  Test(item.completed() == false, "completed()", item.completed(), false);
  to_file = "Go to Store@1@0";
  Test(item.ToFile() == to_file, "ToFile()", item.ToFile(), to_file);

  cout << "\n*****TodoItem(\"Go to Store\", 3)*****\n";
  TodoItem item2(desc1, 3);
  Test(item2.description() == desc1, "description()", item2.description(),
       desc1);
  Test(item2.priority() == 3, "priority()", item2.priority(), 3);
  Test(item2.completed() == false, "completed()", item2.completed(), false);
  to_file = "Go to Store@3@0";
  Test(item2.ToFile() == to_file, "ToFile()", item2.ToFile(), to_file);

  cout << "\n*****TodoItem(\"Go to Store\", 2, true)*****\n";
  TodoItem item3(desc1, 2, true);
  Test(item3.description() == desc1, "description()", item3.description(),
       desc1);
  Test(item3.priority() == 2, "priority()", item3.priority(), 2);
  Test(item3.completed() == true, "completed()", item3.completed(), true);
  to_file = "Go to Store@2@1";
  Test(item3.ToFile() == to_file, "ToFile()", item3.ToFile(), to_file);

  cout << "\n*****TodoItem Mutators*****\n";
  item.set_description(desc2);
  Test(item.description() == desc2,
       "set_description(\"Brush Teeth @ 8PM\") / description()",
       item.description(), desc2);
  item.set_priority(4);
  Test(item.priority() == 4, "set_priority(4) / priority()", item.priority(),
       4);
  item.set_priority(0);
  Test(item.priority() == 5, "set_priority(0) / priority()", item.priority(),
       5);
  item.set_priority(6);
  Test(item.priority() == 5, "set_priority(6) / priority()", item.priority(),
       5);
  item.set_completed(true);
  Test(item.completed() == true, "set_completed(true) / completed()",
       item.completed(), true);
  to_file = "Brush Teeth ` 8PM@5@1";
  Test(item.ToFile() == to_file, "ToFile()", item.ToFile(), to_file);

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
template <typename T>
void Test(bool test, string more_info, T yours, T expected) {
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
  if (!test && yours != T()) {
      cout << "Expected: " << std::boolalpha << expected << endl;
      cout << "Yours   : " << std::boolalpha << yours  << endl << endl;
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


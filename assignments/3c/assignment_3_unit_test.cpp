/*
 * Name        : assignment_3_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class TodoItem and TodoList.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include <iostream>
#include <sstream>
#include <streambuf>
#include "todo_list.h"
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
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 53;
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

  cout << "\n*****TodoList Constructor*****\n";
  TodoList list;
  Test(list.GetSize() == 0, "GetSize()", list.GetSize(),
       static_cast<unsigned int>(0));
  Test(list.GetCapacity() == 25, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(25));
  Test(list.ToFile() == "", "ToFile()", list.ToFile(), string(""));

  cout << "\n*****TodoList Member Functions with 1 Item*****\n";
  list.AddItem(new TodoItem(desc1));
  Test(list.GetSize() == 1, "AddItem(TodoItem(\"Go to Store\")) / GetSize()",
       list.GetSize(), static_cast<unsigned int>(1));
  Test(list.GetCapacity() == 25, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(25));
  Test(list.GetItem(1)->ToFile() == string("Go to Store@1@0"),
       "GetItem(1)->ToFile()", list.GetItem(1)->ToFile(),
       string("Go to Store@1@0"));
  Test(list.ToFile() == "Go to Store@1@0\n", "ToFile()", list.ToFile(),
       string("Go to Store@1@0\n"));
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****TodoList Member Functions with 2 Items*****\n";
  list.AddItem(new TodoItem(desc1, 2, true));
  Test(list.GetSize() == 2,
       "AddItem(TodoItem(\"Go to Store\", 2, true)) / GetSize()",
       list.GetSize(), static_cast<unsigned int>(2));
  Test(list.GetCapacity() == 25, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(25));
  yours = list.GetItem(1)->ToFile();
  expected = "Go to Store@1@0";
  Test(yours == expected, "GetItem(1)->ToFile()", yours, expected);
  yours = list.GetItem(2)->ToFile();
  expected = "Go to Store@2@1";
  Test(yours == expected, "GetItem(2)->ToFile()", yours, expected);
  yours = list.ToFile();
  expected = "Go to Store@1@0\nGo to Store@2@1\n";
  Test(yours == expected, "ToFile()", yours, expected);
  list.DeleteItem(1);
  Test(list.GetSize() == 1, "DeleteItem(1) / GetSize()", list.GetSize(),
       static_cast<unsigned int>(1));
  Test(list.GetCapacity() == 25, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(25));
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****TodoList Member Functions with 25 Items*****\n";
  list.AddItem(new TodoItem(desc2, 4, true));
  stringstream ss;
  for (int i = 0; i < 23; i++) {
    ss << "Description #" << i + 3;
    list.AddItem(new TodoItem(ss.str(), i % 5 + 1));
    ss.str("");
  }
  Test(list.GetSize() == 25, "AddItem(Adding 24 More Items) / GetSize()",
       list.GetSize(), static_cast<unsigned int>(25));
  Test(list.GetCapacity() == 25, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(25));
  yours = list.GetItem(17)->ToFile();
  expected = "Description #17@5@0";
  Test(yours == expected, "GetItem(17)->ToFile()", yours, expected);
  yours = list.GetItem(25)->ToFile();
  expected = "Description #25@3@0";
  Test(yours == expected, "GetItem(25)->ToFile()", yours, expected);
  yours = list.ToFile();
  expected =
      "Go to Store@2@1\nBrush Teeth ` 8PM@4@1\nDescription #3@1@0\n"
          "Description #4@2@0\nDescription #5@3@0\nDescription #6@4@0\n"
          "Description #7@5@0\nDescription #8@1@0\nDescription #9@2@0\n"
          "Description #10@3@0\nDescription #11@4@0\nDescription #12@5@0\n"
          "Description #13@1@0\nDescription #14@2@0\nDescription #15@3@0\n"
          "Description #16@4@0\nDescription #17@5@0\nDescription #18@1@0\n"
          "Description #19@2@0\nDescription #20@3@0\nDescription #21@4@0\n"
          "Description #22@5@0\nDescription #23@1@0\nDescription #24@2@0\n"
          "Description #25@3@0\n";
  Test(yours == expected, "ToFile()", yours, expected);
  cout << "Testing Overloaded <<:\n" << list << endl;

  list.DeleteItem(15);
  Test(list.GetSize() == 24, "DeleteItem(15) / GetSize()", list.GetSize(),
       static_cast<unsigned int>(24));
  Test(list.GetCapacity() == 25, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(25));
  yours = list.GetItem(10)->ToFile();
  expected = "Description #10@3@0";
  Test(yours == expected, "GetItem(10)->ToFile()", yours, expected);
  yours = list.GetItem(20)->ToFile();
  expected = "Description #21@4@0";
  Test(yours == expected, "GetItem(20)->ToFile()", yours, expected);
  yours = list.ToFile();
  expected = "Go to Store@2@1\nBrush Teeth ` 8PM@4@1\nDescription #3@1@0\n"
      "Description #4@2@0\nDescription #5@3@0\nDescription #6@4@0\n"
      "Description #7@5@0\nDescription #8@1@0\nDescription #9@2@0\n"
      "Description #10@3@0\nDescription #11@4@0\nDescription #12@5@0\n"
      "Description #13@1@0\nDescription #14@2@0\n"
      "Description #16@4@0\nDescription #17@5@0\nDescription #18@1@0\n"
      "Description #19@2@0\nDescription #20@3@0\nDescription #21@4@0\n"
      "Description #22@5@0\nDescription #23@1@0\nDescription #24@2@0\n"
      "Description #25@3@0\n";
  Test(yours == expected, "ToFile()", yours, expected);
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****TodoList Member Functions with 30 Items*****\n";
  for (int i = 25; i <= 30; i++) {
    ss << "New Description #" << i;
    list.AddItem(new TodoItem(ss.str(), i % 5 + 1, true));
    ss.str("");
  }
  Test(list.GetSize() == 30, "AddItem(Adding 6 More Items) / GetSize()",
       list.GetSize(), static_cast<unsigned int>(30));
  Test(list.GetCapacity() == 35, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(35));
  yours = list.GetItem(11)->ToFile();
  expected = "Description #11@4@0";
  Test(yours == expected, "GetItem(11)->ToFile()", yours, expected);
  yours = list.GetItem(30)->ToFile();
  expected = "New Description #30@1@1";
  Test(yours == expected, "GetItem(30)->ToFile()", yours, expected);
  yours = list.ToFile();
  expected = "Go to Store@2@1\nBrush Teeth ` 8PM@4@1\nDescription #3@1@0\n"
      "Description #4@2@0\nDescription #5@3@0\nDescription #6@4@0\n"
      "Description #7@5@0\nDescription #8@1@0\nDescription #9@2@0\n"
      "Description #10@3@0\nDescription #11@4@0\nDescription #12@5@0\n"
      "Description #13@1@0\nDescription #14@2@0\n"
      "Description #16@4@0\nDescription #17@5@0\nDescription #18@1@0\n"
      "Description #19@2@0\nDescription #20@3@0\nDescription #21@4@0\n"
      "Description #22@5@0\nDescription #23@1@0\nDescription #24@2@0\n"
      "Description #25@3@0\nNew Description #25@1@1\nNew Description #26@2@1\n"
      "New Description #27@3@1\nNew Description #28@4@1\n"
      "New Description #29@5@1\nNew Description #30@1@1\n";
  Test(yours == expected, "ToFile()", yours, expected);
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****Sorting TodoList with 30 Items*****\n";
  list.Sort();
  bool sorted = true;
  for (int i = 1; i <= 30; i++) {
    if ((i <= 7) && (list.GetItem(i)->priority()) != 1)
      sorted = false;
    else if ((i > 7 && i <= 14) && (list.GetItem(i)->priority()) != 2)
      sorted = false;
    else if ((i > 14 && i <= 19) && (list.GetItem(i)->priority()) != 3)
      sorted = false;
    else if ((i > 19 && i <= 25) && (list.GetItem(i)->priority()) != 4)
      sorted = false;
    else if ((i > 25 && i <= 30) && (list.GetItem(i)->priority()) != 5)
      sorted = false;
  }
  yours = list.ToFile();
  expected = "Description #3@1@0\nDescription #8@1@0\n"
              "Description #13@1@0\nDescription #18@1@0\n"
              "Description #23@1@0\nNew Description #25@1@1\n"
              "New Description #30@1@1\nGo to Store@2@1\n"
              "Description #4@2@0\nDescription #9@2@0\n"
              "Description #14@2@0\nDescription #19@2@0\n"
              "Description #24@2@0\nNew Description #26@2@1\n"
              "Description #5@3@0\nDescription #10@3@0\n"
              "Description #20@3@0\nDescription #25@3@0\n"
              "New Description #27@3@1\nBrush Teeth ` 8PM@4@1\n"
              "Description #6@4@0\nDescription #11@4@0\n"
              "Description #16@4@0\nDescription #21@4@0\n"
              "New Description #28@4@1\nDescription #7@5@0\n"
              "Description #12@5@0\nDescription #17@5@0\n"
              "Description #22@5@0\nNew Description #29@5@1\n";

  Test(sorted && yours == expected, "Sort()", yours, expected);
  cout << "Testing Overloaded <<:\n" << list << endl;

  cout << "\n*****TodoList Member Functions with 1000 Items*****\n";
  for (int i = 0; i < 970; i++)
    list.AddItem(new TodoItem("A", 1, true));
  Test(list.GetSize() == 1000, "AddItem(Adding 970 More Items) / GetSize()",
       list.GetSize(), static_cast<unsigned int>(1000));
  Test(list.GetCapacity() == 1005, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(1005));
  cout << "**Deleting All Items**\n";
  for (int i = 1000; i >= 1; i--)
    list.DeleteItem(i);
  Test(list.GetSize() == 0, "DeleteItem() / GetSize()", list.GetSize(),
       static_cast<unsigned int>(0));
  Test(list.GetCapacity() == 1005, "GetCapacity()", list.GetCapacity(),
       static_cast<unsigned int>(1005));

  // Testing Destructors
  cout << "\n*****Testing Destructors*****" << endl
       << "If the next line is the \"END Testing Destructors\" then you passed!"
       << endl;
  TodoItem *dynamic_item = new TodoItem("testing");
  delete dynamic_item;
  dynamic_item = new TodoItem("testing2", 5);
  delete dynamic_item;
  dynamic_item = new TodoItem("Testing3", 3, true);
  TodoList *dynamic_list = new TodoList();
  delete dynamic_list;
  dynamic_list = new TodoList();
  for (int i = 0; i < 50; i++)
    dynamic_list->AddItem(new TodoItem("testing"));
  delete dynamic_list;
  cout << "*****END Testing Destructors*****" << endl;
  Test(true, "Destructors", 0, 0);

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


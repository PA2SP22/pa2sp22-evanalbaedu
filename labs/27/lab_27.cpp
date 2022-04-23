/*
 * Name        : lab_27.cpp
 * Author      : Luke Sathrum
 * Description : Using the STL
 */

#include <iostream>
#include <string>
#include <sstream>
#include "treasure_chest.h"
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
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 33;
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

  stringstream ss;

  const Item* ptrItem = NULL;
  Item item;
  Item testItems[5] = { Item("ruby", 100, 1), Item("gold", 5, 100), Item(
      "emerald", 50, 2), Item("silver", 2, 200), Item() };
  TreasureChest chest;

  Test(chest.GetSize() == 0 && chest.Empty(), __LINE__,
       "TreasureChest Default Constructor / GetSize() / Empty()");
  Test(chest.GetItem(0) == NULL, __LINE__, "GetItem(0)");
  try {
    chest.RemoveItem(0);
    Test(false, __LINE__, "RemoveItem(0)");
  } catch (string &s) {
    Test(s == "ERROR: Remove at invalid position", __LINE__, "RemoveItem(0)");
  }
  actual = "Chest Empty!";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  chest.AddItem(testItems[0]);
  Test(chest.GetSize() == 1 && !chest.Empty(), __LINE__,
       "AddItem(ruby) / GetSize() / Empty()");
  actual = "ruby";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  chest.AddItem(testItems[1]);
  Test(chest.GetSize() == 2 && !chest.Empty(), __LINE__,
       "AddItem(gold) / GetSize() / Empty()");
  actual = "ruby, gold";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  chest.InsertItem(testItems[2], 1);
  Test(chest.GetSize() == 3 && !chest.Empty(), __LINE__,
       "InsertItem(emerald, 1) / GetSize() / Empty()");
  actual = "ruby, emerald, gold";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  chest.InsertItem(testItems[3], 2);
  Test(chest.GetSize() == 4 && !chest.Empty(), __LINE__,
       "InsertItem(silver, 2) / GetSize() / Empty()");
  actual = "ruby, emerald, silver, gold";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  chest.InsertItem(testItems[4], 10);
  Test(chest.GetSize() == 5 && !chest.Empty(), __LINE__,
       "InsertItem(noname, 10) / GetSize() / Empty()");
  actual = "ruby, emerald, silver, gold, noname";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  item = chest.RemoveItem(0);
  Test(item.name_ == "ruby" && item.value_ == 100 && item.quantity_ == 1,
       __LINE__, "RemoveItem(0)");
  Test(chest.GetSize() == 4 && !chest.Empty(), __LINE__, "GetSize() / Empty()");
  actual = "emerald, silver, gold, noname";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  item = chest.RemoveItem(3);
  Test(item.name_ == "noname" && item.value_ == 0 && item.quantity_ == 0,
       __LINE__, "RemoveItem(0)");
  Test(chest.GetSize() == 3 && !chest.Empty(), __LINE__, "GetSize() / Empty()");
  actual = "emerald, silver, gold";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  try {
    chest.RemoveItem(3);
    Test(false, __LINE__, "RemoveItem(3)");
  } catch (string &s) {
    Test(s == "ERROR: Remove at invalid position", __LINE__, "RemoveItem(3)");
  }

  chest.Clear();
  Test(chest.GetSize() == 0 && chest.Empty(), __LINE__,
       "Clear() / GetSize() / Empty()");
  Test(chest.GetItem(0) == NULL, __LINE__, "GetItem(0)");

  actual = "Chest Empty!";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  for (unsigned int i = 0; i < 5; i++)
    chest.AddItem(testItems[i]);

  Test(chest.GetSize() == 5 && !chest.Empty(), __LINE__,
       "Adding 5 Items / GetSize() / Empty()");
  actual = "ruby, gold, emerald, silver, noname";
  Test(chest.ToString() == actual, __LINE__, "ToString()", chest.ToString(),
       actual);
  cout << "Chest Contents: " << chest << endl << endl;

  chest.SortByName();
  actual = "emerald, gold, noname, ruby, silver";
  Test(chest.ToString() == actual, __LINE__, "SortByName() / ToString()",
       chest.ToString(), actual);
  cout << "Chest Contents: " << chest << endl << endl;

  ptrItem = chest.GetItem(0);
  Test(
      ptrItem->name_ == "emerald" && ptrItem->value_ == 50
          && ptrItem->quantity_ == 2,
      __LINE__, "GetItem(0)");

  chest.SortByValue();
  actual = "noname, silver, gold, emerald, ruby";
  Test(chest.ToString() == actual, __LINE__, "SortByValue() / ToString()",
       chest.ToString(), actual);
  cout << "Chest Contents: " << chest << endl << endl;

  ptrItem = chest.GetItem(0);
  Test(
      ptrItem->name_ == "noname" && ptrItem->value_ == 0
          && ptrItem->quantity_ == 0,
      __LINE__, "GetItem(0)");

  chest.SortByQuantity();
  actual = "noname, ruby, emerald, gold, silver";
  Test(chest.ToString() == actual, __LINE__, "SortByQuantity() / ToString()",
       chest.ToString(), actual);
  cout << "Chest Contents: " << chest << endl << endl;

  ptrItem = chest.GetItem(4);
  Test(
      ptrItem->name_ == "silver" && ptrItem->value_ == 2
          && ptrItem->quantity_ == 200,
      __LINE__, "GetItem(4)");

  ptrItem = chest.GetItem(5);
  Test(ptrItem == NULL, __LINE__, "GetItem(5)");

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

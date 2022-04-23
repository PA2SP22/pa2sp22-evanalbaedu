/*
 * Name        : lab_26.cpp
 * Author      : Luke Sathrum
 * Description : Working on Inheritance
 */

#include <iostream>
#include <string>
#include <sstream>
#include "item.h"
#include "food_item.h"
#include "magic_item.h"
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
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 18;
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
  Item item;
  Item mItem("game", 25);
  FoodItem foodItem;
  FoodItem mFoodItem("coffee", 1, 10, "ounces", 10.25);
  MagicItem magicItem;
  MagicItem mMagicItem("staff", 999, "carved wood", 125);

  Test(item.name() == "item" && item.value() == 0, __LINE__,
       "Item(): Default Constructor / name() / value()");
  actual = "item, $0";
  Test(item.ToString() == actual, __LINE__, "Item(): ToString()",
       item.ToString(), actual);

  item.set_name("car");
  item.set_value(35000);

  Test(item.name() == "car" && item.value() == 35000, __LINE__,
       "Item(): set_name(\"car\") / set_value(35000) / name() / value()");
  actual = "car, $35000";
  Test(item.ToString() == actual, __LINE__, "Item(): ToString()",
       item.ToString(), actual);

  Test(mItem.name() == "game" && mItem.value() == 25, __LINE__,
       "Item(): Constructor(\"game\", 25) / name() / value()");
  actual = "game, $25";
  Test(mItem.ToString() == actual, __LINE__, "Item(): ToString()",
       mItem.ToString(), actual);

  Test(
      foodItem.name() == "fooditem" && foodItem.value() == 0
          && foodItem.calories() == 0 && foodItem.unit_of_measure() == "nounits"
          && foodItem.units() == 0,
      __LINE__,
      "FoodItem(): Default Constructor / name() / value() / calories() /"
      "unit_of_measure() / units()");
  actual = "fooditem, $0, 0.00 nounits, 0 calories";
  Test(foodItem.ToString() == actual, __LINE__, "FoodItem(): ToString()",
       foodItem.ToString(), actual);

  foodItem.set_name("cupcake");
  foodItem.set_value(5);
  foodItem.set_unit_of_measure("cake(s)");
  foodItem.set_units(1.5);
  foodItem.set_calories(200);
  Test(
      foodItem.name() == "cupcake" && foodItem.value() == 5
          && foodItem.calories() == 200
          && foodItem.unit_of_measure() == "cake(s)" && foodItem.units() == 1.5,
      __LINE__,
      "FoodItem(): set_name(cupcake) / set_value(5) / set_unit_of_measure(\""
      "cake(s)\" / set_units(1.5) / set_calories(200) / name() / value() / "
      "calories() / unit_of_measure() / units()");
  actual = "cupcake, $5, 1.50 cake(s), 200 calories";
  Test(foodItem.ToString() == actual, __LINE__, "FoodItem(): ToString()",
       foodItem.ToString(), actual);

  Test(
      mFoodItem.name() == "coffee" && mFoodItem.value() == 1
          && mFoodItem.calories() == 10
          && mFoodItem.unit_of_measure() == "ounces"
          && mFoodItem.units() == 10.25,
      __LINE__,
      "FoodItem(): Constructor(\"coffee\", 1, 10, \"ounces\", 10.25) / name()"
      "/ value() / calories() / unit_of_measure() / units()");
  actual = "coffee, $1, 10.25 ounces, 10 calories";
  Test(mFoodItem.ToString() == actual, __LINE__, "FoodItem(): ToString()",
       mFoodItem.ToString(), actual);

  Test(
      magicItem.name() == "magicitem" && magicItem.value() == 0
          && magicItem.description() == "no description"
          && magicItem.mana_required() == 0,
      __LINE__,
      "MagicItem(): Default Constructor / name() / value() / description()"
      "/ mana_required()");
  actual = "magicitem, $0, no description, requires 0 mana";
  Test(magicItem.ToString() == actual, __LINE__, "MagicItem(): ToString()",
       magicItem.ToString(), actual);

  magicItem.set_name("wand");
  magicItem.set_value(1000);
  magicItem.set_description("jewel-encrusted");
  magicItem.set_mana_required(50);

  Test(
      magicItem.name() == "wand" && magicItem.value() == 1000
          && magicItem.description() == "jewel-encrusted"
          && magicItem.mana_required() == 50,
      __LINE__, "MagicItem(): set_name(\"wand\") / set_value(1000) / "
      "set_description(\"jewel-encrusted\") / set_mana_required(50) / name() "
      "/ value() / description() / mana_required()");
  actual = "wand, $1000, jewel-encrusted, requires 50 mana";
  Test(magicItem.ToString() == actual, __LINE__, "MagicItem(): ToString()",
       magicItem.ToString(), actual);

  Test(
      mMagicItem.name() == "staff" && mMagicItem.value() == 999
          && mMagicItem.description() == "carved wood"
          && mMagicItem.mana_required() == 125,
      __LINE__,
      "MagicItem(): Constructor(\"staff\", 999, \"carved wood\", 125) / name()"
      "/ value() / description() / mana_required()");
  actual = "staff, $999, carved wood, requires 125 mana";
  Test(mMagicItem.ToString() == actual, __LINE__, "MagicItem(): ToString()",
       mMagicItem.ToString(), actual);

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


/*
 * Name        : lab_10.cpp
 * Author      : Luke Sathrum
 * Description : Unit_Test to test your class.
 */
#include <iostream>
#include "temperature.h"
using std::cout;
using std::endl;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // To help test your code (DO NOT ALTER)
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
  Temperature temp1;
  Test(temp1.GetTempAsKelvin() == 0, __LINE__,
       "Default Constructor / GetTempAsKelvin()");
  temp1.SetTempFromKelvin(50);
  Test(temp1.GetTempAsKelvin() == 50, __LINE__,
       "SetTempFromKelvin(50) / GetTempAsCelsius()");
  temp1.SetTempFromCelsius(5);
  Test(
      temp1.GetTempAsFahrenheit() >= 40.99
          && temp1.GetTempAsFahrenheit() <= 41.01,
      __LINE__, "SetTempFromCelsius(5) / GetTempAsFarenheit()");
  temp1.SetTempFromFahrenheit(5);
  Test(temp1.GetTempAsKelvin() >= 258.149 && temp1.GetTempAsKelvin() <= 258.151,
       __LINE__, "SetTempFromFahrenheit(5) / GetTempAsKelvin()");

  yours = temp1.ToString();
  actual = "258.15 Kelvin";
  Test(yours == actual, __LINE__, "ToString()", yours, actual);

  Temperature temp2(50);
  Test(
      temp2.GetTempAsFahrenheit() >= -369.68
          && temp2.GetTempAsFahrenheit() <= -369.66,
      __LINE__, "Constructor(50) / GetTempAsFahrenheit()");

  yours = temp2.ToString('C');
  actual = "-223.15 Celsius";
  Test(yours == actual, __LINE__, "ToString('C')", yours, actual);
  Temperature temp3(5, 'F');
  Test(
      temp3.GetTempAsKelvin() >= 258.14
          && temp3.GetTempAsFahrenheit() <= 258.16,
      __LINE__, "Constructor(5, 'F') / GetTempAsKelvin()");
  Temperature temp4(5, 'f');
  Test(
      temp4.GetTempAsKelvin() >= 258.14
          && temp4.GetTempAsKelvin() <= 258.16,
      __LINE__, "Constructor(5, 'f') / GetTempAsKelvin()");
  Temperature temp5(5, 'C');
  Test(
      temp5.GetTempAsKelvin() >= 278.14
          && temp5.GetTempAsKelvin() <= 278.16,
      __LINE__, "Constructor(5, 'C') / GetTempAsKelvin()");
  Temperature temp6(5, 'c');
  Test(
      temp6.GetTempAsKelvin() >= 278.14
          && temp6.GetTempAsKelvin() <= 278.16,
      __LINE__, "Constructor(5, 'c') / GetTempAsKelvin()");
  Temperature temp7(5, 'K');
  Test(temp7.GetTempAsKelvin() == 5, __LINE__,
       "Constructor(5, 'K') / GetTempAsKelvin()");
  Temperature temp8(5, '5');
  Test(temp8.GetTempAsKelvin() == 5, __LINE__,
       "Constructor(5, '5') / GetTempAsKelvin()");

  yours = temp8.ToString('c');
  actual = "-268.15 Celsius";
  Test(yours == actual, __LINE__, "ToString('c')", yours, actual);

  yours = temp8.ToString('K');
  actual = "5.00 Kelvin";
  Test(yours == actual, __LINE__, "ToString('K')", yours, actual);

  yours = temp8.ToString('k');
  actual = "5.00 Kelvin";
  Test(yours == actual, __LINE__, "ToString('k')", yours, actual);

  yours = temp8.ToString('F');
  actual = "-450.67 Fahrenheit";
  Test(yours == actual, __LINE__, "ToString('F')", yours, actual);

  yours = temp8.ToString('f');
  actual = "-450.67 Fahrenheit";
  Test(yours == actual, __LINE__, "ToString('f')", yours, actual);

  yours = temp8.ToString('1');
  actual = "Invalid Unit";
  Test(yours == actual, __LINE__, "ToString('1')", yours, actual);

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

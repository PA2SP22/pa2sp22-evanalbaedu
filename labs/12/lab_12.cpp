/*
 * Name        : lab_12.cpp
 * Author      : FILL IN
 * Description : Working with Pointers and Dynamic Variables / Arrays
 */
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

/*
 * Allocate memory for a dynamic array of integers.
 * @param unsigned int size - The desired size of the dynamic array
 * @return int* - A pointer to the newly allocated integer array
 */
int* MakeDynoIntArray(unsigned int size);

/*
 * Compute the sum of an array.
 * @param int* the_array - The array for which the sum will be computed
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the sum of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Sum(int* the_array, unsigned int array_size);

/*
 * Identify the max value in an array.
 * @param int* the_array - The array for which the max value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the max value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Max(int* the_array, unsigned int array_size);

/*
 * Identify the min value in an array.
 * @param int* the_array - The array for which the min value will be identified
 * @param unsigned int array_size - The size of the_array
 * @return int - An integer containing the min value of the array
 * @throw The message "NULL ARRAY REFERENCE" if the_array is NULL
 *        Syntax: throw "The Message to throw";
 */
int Min(int* the_array, unsigned int array_size);

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
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS


// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";
  // Tests
  int* my_array = NULL;  // = makeDynoIntArray(10);
  unsigned int my_array_size = 0;

  try {
    Sum(my_array, my_array_size);
  } catch (const char* e) {
    Test(!strcmp(e, "NULL ARRAY REFERENCE"), __LINE__,
         "Sum() EXCEPTION HANDLING");
  }

  try {
    Min(my_array, my_array_size);
  } catch (const char* e) {
    Test(!strcmp(e, "NULL ARRAY REFERENCE"), __LINE__,
         "Min() EXCEPTION HANDLING");
  }

  try {
    Max(my_array, my_array_size);
  } catch (const char* e) {
    Test(!strcmp(e, "NULL ARRAY REFERENCE"), __LINE__,
         "Max() EXCEPTION HANDLING");
  }

  my_array_size = 3;
  my_array = MakeDynoIntArray(my_array_size);
  Test(my_array != NULL, __LINE__, "MakeDynoIntArray(3)");

  my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;

  Test(Sum(my_array, my_array_size) == 60, __LINE__, "Sum(Array)");
  Test(Max(my_array, my_array_size) == 30, __LINE__, "Max(Array)");
  Test(Min(my_array, my_array_size) == 10, __LINE__, "Min(Array)");

  my_array[0] = 30, my_array[1] = 10, my_array[2] = 20;
  Test(Sum(my_array, my_array_size) == 60, __LINE__, "Sum(Array)");
  Test(Max(my_array, my_array_size) == 30, __LINE__, "Max(Array)");
  Test(Min(my_array, my_array_size) == 10, __LINE__, "Min(Array)");

  my_array[0] = 30, my_array[1] = 20, my_array[2] = 10;
  Test(Sum(my_array, my_array_size) == 60, __LINE__, "Sum(Array)");
  Test(Max(my_array, my_array_size) == 30, __LINE__, "Max(Array)");
  Test(Min(my_array, my_array_size) == 10, __LINE__, "Min(Array)");

  my_array[0] = 20, my_array[1] = 10, my_array[2] = 30;

  Test(Sum(my_array, my_array_size) == 60, __LINE__, "Sum(Array)");
  Test(Max(my_array, my_array_size) == 30, __LINE__, "Max(Array)");
  Test(Min(my_array, my_array_size) == 10, __LINE__, "Min(Array)");

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

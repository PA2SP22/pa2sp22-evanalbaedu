/*
 * Name        : lab_15.cpp
 * Author      : FILL IN
 * Description : Working with Insertion and Shell Sort
 */
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/*
 * Apply the insertion sort algorithm to sort an array of integers.
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int InsertionSort(int the_array[], unsigned int size);

/*
 * Apply the shell sort algorithm to sort an array of integers.
 * NOTE: At the end of each iteration of the for loop you will need to call
 *       DisplayArray(the_array);
 * @param int[] the_array - The integer array to be sorted
 * @param unsigned int size - The size of the_array
 * @return int - The number of passes the algorithm does. In this case "pass" is
 *               defined as the number of times the outside loop runs. You
 *               should increment your variable once you enter the outside loop.
 */
int ShellSort(int the_array[], unsigned int size);

/*
 * Swap the values of two integer variables.
 * @param int &value_1 - The first value to be swapped.
 * @param int &value_2 - The second value to be swapped.
 */
void SwapValues(int &value_1, int &value_2);

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;
bool CompareArrays(int array_one[], int array_two[], unsigned int size);
void DisplayArray(int values[]);
bool GRADER = false;
const unsigned int kSize = 5;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// CODE HERE -- FUNCTION DEFINITION


void SwapValues(int &value_1, int &value_2) {
  // DO NOT ALTER THE NEXT 3 LINES!!!
  if (GRADER) {
    cout << value_1 << " " << value_2 << endl;
  }
  // Code SWAP Algorithm Here
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";
  // Tests
  int main[kSize] = { 10, 20, 30, 40, 50 };
  int test[kSize] = { 50, 40, 30, 20, 10 };
  int passes;

  // Insertion Sort
  InsertionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "InsertionSort([50, 40, 30, 20, 10])");

  InsertionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "InsertionSort([10, 20, 30, 40, 50])");

  test[0] = 10, test[1] = 30, test[2] = 20, test[3] = 50, test[4] = 40;

  InsertionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "InsertionSort([10, 30, 20, 50, 40])");

  main[0] = 10, main[1] = 30, main[2] = 30, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 30, test[2] = 10, test[3] = 30, test[4] = 50;

  InsertionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "InsertionSort([50, 30, 10, 30, 50])");

  main[0] = 50, main[1] = 50, main[2] = 50, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 50, test[2] = 50, test[3] = 50, test[4] = 50;

  passes = InsertionSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "InsertionSort([50, 50, 50, 50, 50])");
  Test(passes == 5, __LINE__, "InsertionSort Number of Passes");

  // Shell Sort
  main[0] = 10, main[1] = 20, main[2] = 30, main[3] = 40, main[4] = 50;
  test[0] = 50, test[1] = 40, test[2] = 30, test[3] = 20, test[4] = 10;

  ShellSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "ShellSort([50, 40, 30, 20, 10])");

  ShellSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "ShellSort([10, 20, 30, 40, 50])");

  test[0] = 10, test[1] = 30, test[2] = 20, test[3] = 50, test[4] = 40;

  ShellSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "ShellSort([10, 30, 20, 50, 40])");

  main[0] = 10, main[1] = 30, main[2] = 30, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 30, test[2] = 10, test[3] = 30, test[4] = 50;

  ShellSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "ShellSort([50, 30, 10, 30, 50])");

  main[0] = 50, main[1] = 50, main[2] = 50, main[3] = 50, main[4] = 50;
  test[0] = 50, test[1] = 50, test[2] = 50, test[3] = 50, test[4] = 50;

  passes = ShellSort(test, kSize);
  Test(CompareArrays(main, test, kSize), __LINE__,
       "ShellSort([50, 50, 50, 50, 50])");
  Test(passes == 2, __LINE__, "ShellSort Number of Passes");

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n\n";
  cout << string(40, '-') << endl;

  GRADER = true;
  cout << "ALGORITHM TEST\n";
  cout << string(40, '-') << endl;

  main[0] = 9, main[1] = 1, main[2] = 5, main[3] = 2, main[4] = 7;
  cout << "Insertion Sort Expected\n" << "--------------------\n"
       << "1 9\n5 9\n2 9\n2 5\n7 9\n\n";
  cout << "Insertion Sort Actual\n" << "--------------------\n";
  InsertionSort(main, kSize);

  cout << endl << endl;
  main[0] = 9, main[1] = 1, main[2] = 5, main[3] = 2, main[4] = 7;
  cout << "Shell Sort Expected\n" << "--------------------\n"
       << "5 1 9 2 7\n5 1 9 2 7\n5 1 7 2 9\n1 5 7 2 9\n1 5 7 2 9\n"
       << "1 2 5 7 9\n1 2 5 7 9\n\n";
  cout << "Shell Sort Actual\n" << "--------------------\n";
  ShellSort(main, kSize);

  cout << string(40, '-') << endl;
  cout << "END OF ALGORITHM TEST!\n";
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

bool CompareArrays(int array_one[], int array_two[], unsigned int size) {
  for (unsigned int i = 0; i < size; i++)
    if (array_one[i] != array_two[i])
      return false;
  return true;
}

void DisplayArray(int values[]) {
  if (GRADER) {
    for (unsigned int i = 0; i < kSize; i++)
      cout << values[i] << ' ';
    cout << endl;
  }
}

/*
 * Name        : lab_22.cpp
 * Author      : YOUR NAME
 * Description : Recursive Functions
 */

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/*
 * Compute and return the factorial of a value, using a recursive algorithm. Zero factorial
 * will return 1.
 * @param value an unsigned integer containing the value for which the factorial will be computed
 * @return an unsigned integer containing the computed factorial of the value
 */
unsigned int Factorial(unsigned int value);

/*
 * Return a specified value in a Fibonacci sequence. The lowest value requested in the sequence
 * must never be less than one.
 * @param fibValue an unsigned integer specifying which value in the Fibonacci sequence to return
 * @return an unsigned integer containing the requested value in the Fibonacci sequence
 */
unsigned int Fibonacci(unsigned int fib_value);

/*
 * Test a single word to see if it is a palindrome. The word must be all in the same case
 * (upper or lower) and cannot contain spaces, digits, or punctuation.
 * @param word a string containing the word to be tested
 * @return true of word is a palindrome, else false; empty string and single character strings
 *         are considered palindromes
 */
bool WordIsPalindrome(string word);

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going forward to the end of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param start an unsigned integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces; returns empty string
 *         if the startIndex is >= the size of the array
 */
string ArrayForwardsAsString(int array[], unsigned int start,
                             unsigned int size);

/*
 * Produce a string containing the contents of an array, separated by single spaces,
 * starting at a specified index and going backward to the beginning of the array. The returned
 * string will contain an extra space character after the last value added.
 * @param array an integer array containing the values to be added to the string
 * @param start an unsigned integer containing the index of the first value in the array to be added
 *        to the output string
 * @param size an unsigned integer containing the number of elements in the array
 * @return a string containing the contents of the array, separated by spaces, in reverse order; returns empty string
 *         if the startIndex is < zero
 */
string ArrayBackwardsAsString(int array[], unsigned int start, unsigned int size);

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

// CODE FUNCTION DEFINITIONS HERE


// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";
  // Tests

  Test(Factorial(0) == 1, __LINE__, "Factorial(0)");
  Test(Factorial(1) == 1, __LINE__, "Factorial(1)");
  Test(Factorial(2) == 2, __LINE__, "Factorial(2)");
  Test(Factorial(5) == 120, __LINE__, "Factorial(5)");
  Test(Fibonacci(1) == 1, __LINE__, "Fibonacci(1)");
  Test(Fibonacci(2) == 1, __LINE__, "Fibonacci(2)");
  Test(Fibonacci(3) == 2, __LINE__, "Fibonacci(3)");
  Test(Fibonacci(15) == 610, __LINE__, "Fibonacci(610)");
  Test(WordIsPalindrome("") == true, __LINE__, "WordIsPalindrome(\"\")");
  Test(WordIsPalindrome("a") == true, __LINE__, "WordIsPalindrome(\"a\")");
  Test(WordIsPalindrome("sitonapotatopanotis") == true, __LINE__,
       "WordIsPalindrome(\"sitonapotatopanotis\")");
  Test(WordIsPalindrome("baseball") == false, __LINE__,
       "WordIsPalindrome(\"baseball\")");

  int numbers[5] = { 5, 10, 15, 20, 25 };
  yours = ArrayForwardsAsString(numbers, 0, 5);
  actual = "5 10 15 20 25 ";
  Test(yours == actual, __LINE__, "ArrayForwardsAsString(numbers, 0, 5)", yours,
       actual);
  yours = ArrayForwardsAsString(numbers, 3, 5);
  actual = "20 25 ";
  Test(yours == actual, __LINE__, "ArrayForwardsAsString(numbers, 3, 5)", yours,
       actual);
  yours = ArrayForwardsAsString(numbers, 5, 5);
  actual = "";
  Test(yours == actual, __LINE__, "ArrayForwardsAsString(numbers, 5, 5)", yours,
       actual);
  yours = ArrayBackwardsAsString(numbers, 4, 5);
  actual = "25 20 15 10 5 ";
  Test(yours == actual, __LINE__, "ArrayBackwardsAsString(numbers, 4, 5)",
       yours, actual);
  yours = ArrayBackwardsAsString(numbers, 1, 5);
  actual = "10 5 ";
  Test(yours == actual, __LINE__, "ArrayBackwardsAsString(numbers, 1, 5)",
       yours, actual);
  yours = ArrayBackwardsAsString(numbers, -1, 5);
  actual = "";
  Test(yours == actual, __LINE__, "ArrayBackwardsAsString(numbers, -1, 5)",
       yours, actual);

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

/*
 * Name        : lab_4.cpp
 * Author      : FILL IN
 * Description : Use branching statements, looping statements and string and
 *               character functions to complete the functions
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ios_base;
using std::boolalpha;

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void InteractiveTest();
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
void ClearScreen();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;

// Function Prototypes (DO NOT ALTER)
string MakeString(string label, double value, char separator);
char StringToChar(string value);
int StringToInt(string value);
double StringToDouble(string value);
bool StringToBool(string value);

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  string input;
  cout << "[1] Do interactive test, [2] Skip to unit test: ";
  getline(cin, input);
  if (StringToInt(input) == 1)
    InteractiveTest();

  UnitTest();
  // This ends program execution
  return 0;
}

/*
 * Return a string comprised of a label, followed by a space, followed by a
 * separator character, followed by a space, followed by a floating-point value.
 * For example, label="Temperature", value=41.7, separator=':' will return
 * "Temperature : 41.7".
 * @uses stringstream.
 * @param string label - The label for the value
 * @param double value - The value associated with the label
 * @param char separator - The character that separates the label and the value
 * @return string - Comprised of a label, followed by a space, followed by a
 *                  separator character, followed by a space, followed by a
 *                  floating-point value
 */
string MakeString(string label, double value, char separator) {
  // CODE HERE
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Return the first character of a length 1 string. If the value is of
 * length 0 or of length > 1, return the null character ('\0').
 * @param string value - The expected single character
 * @return char - The first character of the string or null character ('\0')
 *                when value is length 0 or value is length > 1
 */
char StringToChar(string value) {
  // CODE HERE
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected integer value (such as a string
 * captured from stdin) into an integer. If value is not valid as an integer,
 * return 0.
 * @uses stringstream
 * @param string value - The expected integer value
 * @return int - An integer representing the value, or 0 on failure
 */
int StringToInt(string value) {
  // THIS FUNCTION PROVIDED AS AN EXAMPLE
  int ivalue = 0;
  stringstream converter(value);
  converter.exceptions(ios_base::failbit);

  try {
    converter >> ivalue;
  } catch (ios_base::failure f) {
  }

  return ivalue;
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an expected floating-point value (such as a
 * string captured from stdin) into a double. If value is not valid as a double
 * return 0.
 * @uses stringstream
 * @param string value - The expected floating-point value
 * @return double - A double representing the value, or 0 on failure
 */
double StringToDouble(string value) {
  // CODE HERE
}

/*
 * Useful when accepting input from stdin using the getline function.
 * Convert a string containing an boolean value (such as a string captured from
 * stdin) into a bool. Return true if the first character is 'T'
 * (case-insensitive), false if the first character is 'F' (case-insensitive),
 * and false on anything else.
 * @param string value - The expected string to start with either 'T' or 'F'
 * @return bool - If the first character is 'T' (case-insensitive) return true.
 *                If the first character is 'F' (case-insensitive) return false.
 *                Return false on anything else.
 */
bool StringToBool(string value) {
  // CODE HERE
}

// For testing (DO NOT ALTER)
void InteractiveTest() {
  cout << "\nSTARTING INTERACTIVE TEST\n\n";

  bool quit = false;
  char c = 'z';
  string input;

  while (!quit) {
    cout << "! TRY EVERYTHING YOU CAN TO BREAK THESE ON BAD INPUT !\n\n";

    cout << "Enter a char ('z' to stop interactive test): ";
    getline(cin, input);
    c = StringToChar(input);
    if (c == '\0')
      cout << input << " not a valid char\n";
    else if (c == 'z')
      break;
    else
      cout << "Char input: " << c << endl;

    cout << "\nEnter an integer: ";
    getline(cin, input);
    cout << "Integer input: " << StringToInt(input) << endl;

    cout << "\nEnter a double: ";
    getline(cin, input);
    cout << "Double input: " << StringToDouble(input) << endl;

    cout << "\nEnter TRUE or FALSE: ";
    getline(cin, input);
    cout << "Boolean input: " << boolalpha << StringToBool(input) << endl;

    cout << "\nHIT ENTER TO CONTINUE";
    getline(cin, input);
    ClearScreen();
  }

  cout << "\nINTERACTIVE TEST COMPLETE\n\n";
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Test: " << num_of_tests << endl;
  string yours = "", actual = "";

  // Tests
  Test(MakeString("Temperature", 42.6, ':') == "Temperature : 42.6", __LINE__,
       "MakeString(\"Temperature\", 42.6, ':')");
  Test(MakeString("", 75, ',') == " , 75", __LINE__,
       "MakeString(\"\", 75, ',')");
  Test(MakeString("Total", 100.05, '=') == "Total = 100.05", __LINE__,
       "MakeString(\"Total\", 100.05, '=')");
  Test(StringToChar("") == '\0', __LINE__, "StringToChar(\"\")");
  Test(StringToChar("yn") == '\0', __LINE__, "StringToChar(\"yn\")");
  Test(StringToChar("X") == 'X', __LINE__, "StringToChar(\"X\")");
  Test(StringToInt("42") == 42, __LINE__, "StringToInt(\"42\")");
  Test(StringToInt("hello") == 0, __LINE__, "StringToInt(\"hello\")");
  Test(StringToInt("") == 0, __LINE__, "StringToInt(\"\")");
  Test(StringToDouble("") == 0, __LINE__, "StringToDouble(\"\")");
  Test(StringToDouble("3.14") == 3.14, __LINE__, "StringToDouble(\"3.14\")");
  Test(StringToDouble("hello") == 0, __LINE__, "StringToDouble(\"hello\")");
  Test(StringToBool("") == false, __LINE__, "StringToBool(\"\")");
  Test(StringToBool("TrUe") == true, __LINE__, "StringToBool(\"TrUe\")");
  Test(StringToBool("FALSE") == false, __LINE__, "StringToBool(\"FALSE\")");

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

// For testing (DO NOT ALTER)
void ClearScreen() {
#ifdef WIN32
  system("cls");
#else
  system("clear");
#endif
}

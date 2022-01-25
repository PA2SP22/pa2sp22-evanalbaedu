/*
 * Name        : lab_3.cpp
 * Author      : FILL IN
 * Description : Using branching statements, looping statements and string and
 *               character functions complete the functions
 */

#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <sstream>
using std::cin;
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
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;

// Function Prototypes (DO NOT ALTER)
string Goldilocks(string item, int number);
int RockScissorPaper(char player_one, char player_two);
string CharWithAsciiValueAsString(char c);
string ToLower(string input);
string ToUpper(string input);
char GetCharacter(string input, int char_index);

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too small"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid argument)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid argument)
 * @return string - The output string specified in the documentation above
 */
string Goldilocks(string item, int number) {
  // CODE HERE
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw
 */
int RockScissorPaper(char player_one, char player_two) {
  // YOU MUST USE A SWITCH IN THIS FUNCTION
  // CODE HERE
}

/*
 * Return a string that contains a character (taken from the parameter
 * c) and its ASCII integer value. For example, If the char passed in is 'A',
 * the function will return '"A 65"
 * @param char character - The char from which an ASCII value will be taken
 * @return string - A string containing the original character argument,
 *                  followed by a space, followed by the ASCII integer value of
 *                  the char
 */
string CharWithAsciiValueAsString(char character) {
  // CODE HERE

  // HINT: try a stringstream here
}

/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) {
  // CODE HERE
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 */
string ToUpper(string input) {
  // CODE HERE
}

/*
 * Return the character from the input string at index char_index.
 * @param string input - The string from which the character will be taken
 * @param int char_index - The zero-indexed position of the character to return.
 *                         char_index must be >= 0 and < length of input string.
 * @return char - A char containing the character from the input string at
 *                char_index position, or the null character if char_index is
 *                outside the range of the string. The null character is '\0'
 */
char GetCharacter(string input, int char_index) {
  // CODE HERE
}

// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Test: " << num_of_tests << endl;
  string yours = "", actual = "";

  yours = Goldilocks("porridge", 2);
  actual = "This porridge is too cold";
  Test(yours == actual, __LINE__, "Goldilocks(\"porridge\", 2)", yours, actual);

  yours = Goldilocks("chair", 3);
  actual = "This chair is just right";
  Test(yours == actual, __LINE__, "Goldilocks(\"chair\", 3)", yours, actual);

  yours = Goldilocks("bed", 1);
  actual = "This bed is too hard";
  Test(yours == actual, __LINE__, "Goldilocks(\"bed\", 1)", yours, actual);

  Test(RockScissorPaper('r', 'S') == 1, __LINE__,
       "RockScissorPaper ('r', 'S')");

  Test(RockScissorPaper('R', 'p') == 2, __LINE__,
       "RockScissorPaper ('R', 'p')");

  Test(RockScissorPaper('S', 'P') == 1, __LINE__,
       "RockScissorPaper ('S', 'P')");

  Test(RockScissorPaper('r', 'r') == 3, __LINE__,
       "RockScissorPaper ('r', 'r')");

  yours = CharWithAsciiValueAsString('Z');
  actual = "Z 90";
  Test(yours == actual, __LINE__, "CharWithAsciiValueAsString('Z')", yours,
       actual);

  yours = CharWithAsciiValueAsString('a');
  actual = "a 97";
  Test(yours == actual, __LINE__, "CharWithAsciiValueAsString('a')", yours,
       actual);

  yours = ToLower("HELLO");
  actual = "hello";
  Test(yours == actual, __LINE__, "ToLower(\"HELLO\")", yours, actual);

  yours = ToLower("gOOdbYe");
  actual = "goodbye";
  Test(yours == actual, __LINE__, "ToLower(\"gOOdbYe\")", yours, actual);

  yours = ToUpper("hello");
  actual = "HELLO";
  Test(yours == actual, __LINE__, "ToUpper(\"hello\")", yours, actual);

  yours = ToUpper("gOOdbYe");
  actual = "GOODBYE";
  Test(yours == actual, __LINE__, "ToUpper(\"gOOdbYe\")", yours, actual);

  Test(GetCharacter("amazing", 3) == 'z', __LINE__,
       "GetCharacter(\"amazing\", 3)");

  Test(GetCharacter("hooray!", 6) == '!', __LINE__,
       "GetCharacter(\"hooray!\", 6)");

  Test(GetCharacter("toobig", 10) == '\0', __LINE__,
       "GetCharacter(\"toobig\", 10)");

  Test(GetCharacter("toosmall", -10) == '\0', __LINE__,
       "GetCharacter(\"toosmall\", -10)");

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

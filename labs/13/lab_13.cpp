/*
 * Name        : lab_13.cpp
 * Author      : FILL IN
 * Description : Working with Pointers and Dynamic Objects
 */
#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

/*
 * Allocate memory for a dynamic string with specified contents.
 * @param string contents - The desired contents of the dynamic string
 * @return string* - A pointer to the newly allocated string
 */
string* MakeDynoString(string contents);

/*
 * Free the memory associated with a dynamic string and NULL out its pointer.
 * @param string *& the_string - A pointer (passed by reference) to a dynamic
 *                               string
 */
void ClearDynoString(string *&the_string);

/*
 * Count the number of alphabetic and numeric characters in a string and return
 * its length.
 * @uses isdigit() and isalpha()
 * @param string* the_string - A pointer to the string in which characters will
 *                             be counted
 * @param unsigned int &alpha - Contains the count of alphabetic characters in
 *                              the string on return
 * @param unsinged int &num - Contains the count of numeric characters in the
 *                            string on return
 * @return unsigned int - Contains the length of the_string
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
unsigned int CountChars(string* theString, unsigned int &alpha,
                        unsigned int &num);

/*
 * Find a word inside of a string.
 * @uses String Member function find()
 * @uses String Member Variable npos
 * @param string *the_string - The string in which the search for a word will
 *                             take place
 * @param string the_word - The word to look for inside of the_string
 * @return bool - True if the_word is found in the_string, else false
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
bool FindWord(string *the_string, string the_word);

/*
 * Replace one word in a string with another word.
 * @uses String Member Function find()
 * @uses String Member Function replace()
 * @param string *the_string -  The string that will have a word replaced
 * @param string old_word  - The word inside of the_string being replaced
 * @param string new_word - The word that will be used to replace old_word in
 *                          the_string
 * @return bool - True if old_word was found and replaced, else return false
 * @throw The message "NULL STRING REFERENCE" if the_string is NULL
 */
bool ReplaceWord(string* the_string, string old_word, string new_word);

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

// CODE HERE -- FUNCTION DEFINITION


// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Tests: " << num_of_tests << endl;
  string yours = "", actual = "";
  // Tests
  string* my_string = 0;
  unsigned int alpha, num;

  try {
    CountChars(my_string, alpha, num);
  } catch (const char* e) {
    Test(!strcmp(e, "NULL STRING REFERENCE"), __LINE__,
         "CountChars() EXCEPTION HANDLING");
  }

  try {
    FindWord(my_string, "hello");
  } catch (const char* e) {
    Test(!strcmp(e, "NULL STRING REFERENCE"), __LINE__,
         "FindWord() EXCEPTION HANDLING");
  }

  try {
    ReplaceWord(my_string, "hello", "goodbye");
  } catch (const char* e) {
    Test(!strcmp(e, "NULL STRING REFERENCE"), __LINE__,
         "ReplaceWord() EXCEPTION HANDLING");
  }

  my_string = MakeDynoString("123, abc; 456: hello. 0!");
  Test(my_string != NULL, __LINE__,
       "MakeDynoString(\"123, abc; 456: hello. 0!\")");
  Test(CountChars(my_string, alpha, num) == 24, __LINE__,
       "CountChars() for Length");
  Test(alpha == 8, __LINE__, "CountChars() for Alpha");
  Test(num == 7, __LINE__, "CountChars() for Numeric");

  Test(FindWord(my_string, "HELLO") == false, __LINE__, "FindWord(\"HELLO\")");
  Test(FindWord(my_string, "abc") == true, __LINE__, "FindWord(\"abc\")");

  ReplaceWord(my_string, "hello", "goodbye");

  Test(*my_string == "123, abc; 456: goodbye. 0!", __LINE__,
       "ReplaceWord(my_string, \"hello\", \"goodbye\")");
  Test(ReplaceWord(my_string, "HELLO", "GOODBYE") == false, __LINE__,
       "ReplaceWord(my_string, \"HELLO\", \"GOODBYE\")");

  ClearDynoString(my_string);
  Test(my_string == NULL, __LINE__, "ClearDynoString(my_string");

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

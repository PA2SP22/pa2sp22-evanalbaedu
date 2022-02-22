/*
 * Name        : lab_8.cpp
 * Author      : FILL IN
 * Description : Working with Command Line Arguments
 */
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::map;
using std::stringstream;

/*
 * Process the argv array (command-line arguments to the program). Ignore
 * argv[0] as that is the program name. Perform the following operations on
 * the input values:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * @param int argc - Contains the number of arguments passed to the program
 *                   on the command-line
 * @param char *argv[] - An array containing the command-line arguments
 */
void ProcessArguments(int argc, char *argv[]);

// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
map<int, int> counters;
void OnTen();
void OnTwenty();
void OnThirty();
void OnForty();
void OnFifty();
void OnError();
void UnitTest(int argc, char *argv[]);
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
bool CheckArgs(int argc, char* argv[]);
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 6;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main(int argc, char* argv[]) {
  // To test your code (DO NOT ALTER)
  UnitTest(argc, argv);
  // This ends program execution
  return 0;
}

// CODE HERE -- FUNCTION DEFINITION

// For testing (DO NOT ALTER)
void UnitTest(int argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "teacher") == 0 && CheckArgs(argc, argv)) {
    cout << string(40, '-') << endl;
    cout << "UNIT TEST:\n" << string(40, '-') << endl;
    if (num_of_tests != 0)
      cout << "Total Number of Tests: " << num_of_tests << endl;
    string yours = "", actual = "";
    // Tests
    counters[10] = 0, counters[20] = 0, counters[20] = 0, counters[40] = 0,
    counters[50] = 0;
    counters[99] = 0;

    ProcessArguments(argc, argv);

    Test(counters[10] == 1, __LINE__, "Counting 10s");
    Test(counters[20] == 1, __LINE__, "Counting 20s");
    Test(counters[30] == 1, __LINE__, "Counting 30s");
    Test(counters[40] == 1, __LINE__, "Counting 40s");
    Test(counters[50] == 1, __LINE__, "Counting 50s");
    Test(counters[99] == 2, __LINE__, "Counting Errors");

    cout << string(40, '-') << endl;
    cout << "Passed: " << ut_passed << " / " << ut_total << endl;
    OutputFailedTests();
    cout << string(40, '-') << endl;
    cout << "END OF UNIT TEST!\n";
    cout << string(40, '-') << endl;
    cout << "Be sure to run 'make style' to check for any style errors.\n"
         << "Please note that 'make style' does NOT check variable names or"
         << " indentation" << endl << endl;
  } else {
    cout << "\nRun program with the following argument list:\n";
    cout << "\n\t\"teacher 10 20 30 40 50 60\"\n";
    cout << "\nto run the UNIT TEST.\n\n";
  }
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

bool CheckArgs(int argc, char* argv[]) {
  if (argc == 8) {
    // convert the argv[2] to argv[7] contents to integers
    int *temps = new int[6];
    stringstream ss;
    for (int i = 0, j = 2; i < 6; i++, j++) {
      ss.str(argv[j]);
      ss >> temps[i];
      ss.clear();
    }

    // check to see that argv[2] to argv[7] match the expected launch
    // UNIT TEST values
    for (int i = 0, j = 10; i < 6; i++, j += 10) {
      if (temps[i] != j)
        return false;
    }

    delete[] temps;

    return true;
  }
  return false;
}

void OnTen() {
  counters[10]++;
}

void OnTwenty() {
  counters[20]++;
}

void OnThirty() {
  counters[30]++;
}

void OnForty() {
  counters[40]++;
}

void OnFifty() {
  counters[50]++;
}

void OnError() {
  counters[99]++;
}

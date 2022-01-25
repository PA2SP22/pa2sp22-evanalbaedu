/*
 * Name        : call_by.cpp
 * Author      : Luke Sathrum
 * Description : Examples of Call-by-Value, Call-by-Reference and
 *               const-by-reference.
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * Changes the value of the parameter and outputs it
 */
void CallByValue(string call_by_value);
/*
 * Changes the value of the parameter and outputs it
 */
void CallByReference(string &call_by_reference);
/*
 * Tries to change the value of the parameter and outputs it
 */
void ConstByReference(const string &const_by_reference);

// Program starts here
int main() {
  // Setup our original number
  string word = "Hello";
  cout << "The value before a call to CallByValue(): " << word << endl;
  CallByValue(word);
  cout << "The value after a call to CallByValue(): " << word << endl << endl;

  cout << "The value before a call to CallByReference(): " << word << endl;
  CallByReference(word);
  cout << "The value after a call to CallByReference(): " << word << endl
       << endl;

  cout << "The value before a call to ConstByReference(): " << word << endl;
  ConstByReference(word);
  cout << "The value after a call to ConstByReference(): " << word << endl
       << endl;

  // This ends our program
  return 0;
}

void CallByValue(string call_by_value) {
  call_by_value = "One";
  cout << "Inside CallByValue(): " << call_by_value << endl;
}

void CallByReference(string &call_by_reference) {
  call_by_reference = "Two";
  cout << "Inside CallByReference(): " << call_by_reference << endl;
}

void ConstByReference(const string& const_by_reference) {
  // This will result in a compiler error
//  const_by_reference = "Three";
  cout << "Inside ConstByReference(): " << const_by_reference << endl;
}

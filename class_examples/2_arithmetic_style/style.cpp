/*
 * Name        : style.cpp
 * Author      : Luke Sathrum
 * Description : Examples of Class Programming Style
 * Sources     :
 */

// Please note the header above. You need to include the name of the file, the
// author, a description of the program and any sources used

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Program Execution Starts Here
int main() {
  // Note comments have a space between the // and the first word
  // We are also in a block so we are indented over 2 spaces

  // Variables should be named well and have underscores between words
  int total_rounds;

  // Constants start with a k and do not have underscores
  int kTotalRounds = 3;

  // 80 Lines ends at the @ and should never be longer than this               @

  // To get rid of warning...
  total_rounds = kTotalRounds;
  total_rounds++;
  
  // This ends program execution
  // Notice that 0 is not in () such as return(0);
  return 0;
}

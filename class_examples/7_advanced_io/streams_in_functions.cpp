/*
 * Name        : streams_in_functions.cpp
 * Author      : Luke Sathrum
 * Description : Example of using streams in functions. It depends on the file
 *               functions.txt.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::stringstream;

/**
 * This function will output a message to the given output stream
 * @param ostream &output - The output stream
 * @param string message - The message to output to the output stream
 */
void Output(ostream &output, string message) {
  output << message;
}

/**
 * This function will read a line from the input stream and output it to
 * standard out
 * @param istream &input - The input stream
 */
void ReadLine(istream &input) {
  string line;
  getline(input, line);
  cout << "The line was: " << line << endl;
}

// Program starts here
int main() {
  string line;
  // Use the functions with cin / cout
  Output(cout, "Please type anything followed by <enter>\n");
  ReadLine(cin);

  // Use the functions with a stringstream
  stringstream ss;
  Output(ss, "Writing to the stringstream!\n");
  ReadLine(ss);

  // Use the functions with a file
  ifstream fin("functions.txt");
  if (fin.fail()) {
    Output(cerr, "Failed to open the file functions.txt!\n");
    exit(1);
  }
  ofstream fout("functions_output.txt");
  if (fout.fail()) {
    Output(cerr, "Failed to open the file functions_output.txt!\n");
    exit(1);
  }
  Output(fout, "Writing to the file\n");
  ReadLine(fin);
  fout.close();
  fin.close();

  // This ends our program
  return 0;
}

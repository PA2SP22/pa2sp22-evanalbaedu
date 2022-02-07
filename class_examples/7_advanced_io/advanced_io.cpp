/*
 * Name        : advanced_io.cpp
 * Author      : Luke Sathrum
 * Description : Reading a file and appends to another file. Uses the files
 *               read.txt and append.txt
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

// Program starts here
int main() {
  // Set up a string variable to hold the line
  string line;
  // Declare our Input Stream
  ifstream fin("read.txt");
  // Declare our Output Stream
  ofstream fout("append.txt", std::ios::app);
  // Make sure both streams connected successfully
  if (fin.fail() || fout.fail()) {
    cerr << "Error opening/creating one of the files.\n";
    exit(1);
  }

  // Get and output lines until we hit the end of the file
  while (!fin.eof()) {
    // Get the current line in the file
    getline(fin, line);
    // Output the line to the output file (we are appending)
    fout << line << endl;
  }

  cout << "The file i/o has completed successfully\n";

  // Close our Streams
  fin.close();
  fout.close();

  // This ends our program
  return 0;
}

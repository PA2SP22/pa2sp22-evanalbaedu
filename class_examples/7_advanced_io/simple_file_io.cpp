/*
 * Name        : simple_file_io.cpp
 * Author      : Luke Sathrum
 * Description : Examples of how to read and write files. There is 1 file
 *               associated with this program, infile.txt, which holds
 *               multiple numbers, each on 1 line.
 */

#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

// Program starts here
int main() {
  // Declare our Streams
  ifstream fin;
  ofstream fout;
  // Open our files
  fin.open("infile.txt");
  fout.open("outfile.txt");

  // Get the numbers from infile and output to outfile
  int first, second, third;
  fin >> first >> second >> third;
  fout << "The sum of the first 3\n" << "numbers in infile.txt\n"
       << "are " << (first + second + third) << endl;

  cout << "The file i/o has completed successfully\n";

  // Close our Streams
  fin.close();
  fout.close();
  // This ends our program
  return 0;
}

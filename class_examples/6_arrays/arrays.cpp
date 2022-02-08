/*
 * Name        : arrays.cpp
 * Author      : Luke Sathrum
 * Description : Example of arrays in C++
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*
 * Fills up an array of any size that holds student scores
 * @param int[] scores - The array to fill up
 * @param const int &size - The size of the array
 */
void FillUp(int scores[], const int &size);

/*
 * Outputs the scores in the array
 * @param int[] scores - The array to fill up
 * @param const int &size - The size of the array
 */
void Output(int scores[], const int &size);

/*
 * Returns the highest test score in the array
 * @param int[] scores - The array to fill up
 * @param const int &size - The size of the array
 * @return int - The highest test score
 */
int Highest(int scores[], const int &size);

// Program starts here
int main() {
  // Setup our arrays and variables
  const int kSizeScoreArray = 5;
  int scores[] = { 1, 2, 3, 4, 5 };

  // Output the array and highest value
  cout << "The array contains the following values:\n";
  Output(scores, kSizeScoreArray);
  cout << "The highest value in the array is: "
       << Highest(scores, kSizeScoreArray) << endl;

  // Get new values for the array
  FillUp(scores, kSizeScoreArray);

  // Output the array and highest value
  cout << "The array contains the following values:\n";
  Output(scores, kSizeScoreArray);
  cout << "The highest value in the array is: "
       << Highest(scores, kSizeScoreArray) << endl;

  // This ends our program
  return 0;
}

void FillUp(int scores[], const int &size) {
  for (int i = 0; i < size; i++) {
    // Get the score
    cout << "Enter score " << i + 1 << ": ";
    cin >> scores[i];
  }
}

void Output(int scores[], const int &size) {
  int i;
  for (i = 0; i < size - 1; i++) {
    cout << scores[i] << ", ";
  }
  cout << scores[i] << endl;
}

int Highest(int scores[], const int &size) {
  int highest = scores[0];
  for (int i = 1; i < size; i++) {
    // Check to see if this score is larger than highest
    if (scores[i] > highest)
      highest = scores[i];
  }
  return highest;
}

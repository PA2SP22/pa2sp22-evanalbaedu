/*
 * Name        : multidimensional_arrays.cpp
 * Author      : Luke Sathrum
 * Description : Example of multidimensional arrays in C++
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Global Constants
const int kNumberStudents = 4, kNumberQuizzes = 3;

/*
 * Outputs a multidimensional array of students quiz grades
 * @param int[][kNumberQuizzes] scores - The array of students and quiz scores
 */
void OutputScores(int scores[][kNumberQuizzes]);

// Program starts here
int main() {
  // Setup our arrays and variables
  const int kNumberStudents = 4, kNumberQuizzes = 3;
  int scores[kNumberStudents][kNumberQuizzes] = {
  // Quiz 1, Quiz 2, Quiz 3
      { 10, 5, 7 },  // Student 1
      { 1, 2, 3 },  // Student 2
      { 9, 9, 8 },  // Student 3
      { 8, 7, 5 }   // Student 4
  };

  // Output the scores
  OutputScores(scores);

  // This ends our program
  return 0;
}

void OutputScores(int scores[][kNumberQuizzes]) {
  // To output a multidimensional array, we need a for loop for each dimension
  // This outside loop handles each student one-by-one
  for (int i_row = 0; i_row < kNumberStudents; i_row++) {
    cout << "Student " << (i_row + 1) << "'s quiz scores\n"
         << "-----------------------------------------\n";
    // This inside loop handles each individual's quiz one-by-one
    for (int i_col = 0; i_col < kNumberQuizzes; i_col++) {
      cout << "Quiz " << (i_col + 1) << ": " << scores[i_row][i_col] << endl;
    }
    cout << "-----------------------------------------\n";
  }
}

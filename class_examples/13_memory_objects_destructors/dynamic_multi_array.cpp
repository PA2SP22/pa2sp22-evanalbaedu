/*
 * Name        : dynamic_multi_array.cpp
 * Author      : Luke Sathrum
 * Description : Examples of using dynamic multidimensional arrays.
 *               Here's what we're doing
 *               1) Create our dynamic multidimensional array
 *                 - This is an array to hold student's quiz scores
 *               2) Fill up our dynamic multidimensional array
 *                 - Have the user input the test scores
 *               3) Output our multidimensional array
 *                 - We will output the quiz scores and calculate the total for
 *                   each user
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Program starts here
int main() {
  // Create our variables
  int size_row, size_col, i_row, i_col, sum;

  // Creating a pointer to be used for the outside array
  // This creates pointer that can hold integer pointers
  int **quizzes;

  // Get the size of the outside array (i.e. the number of students)
  cout << "How many students? ";
  cin >> size_row;

  // Get the size of each of our inside arrays (i.e. the number of quizzes)
  cout << "How many quizzes? ";
  cin >> size_col;

  // Create our dynamic outside array (an array of integer pointers)
  quizzes = new int*[size_row];

  // Create our dynamic inside arrays (arrays of integers)
  for (i_row = 0; i_row < size_row; i_row++) {
    quizzes[i_row] = new int[size_col];
  }

  // Get the quiz grades for each student
  for (i_row = 0; i_row < size_row; i_row++) {
    cout << endl;
    // Loop through each quiz for the given student
    for (i_col = 0; i_col < size_col; i_col++) {
      // Get the quiz grade
      cout << "Grades for Student " << (i_row + 1) << ", Quiz " << (i_col + 1)
           << ": ";
      cin >> quizzes[i_row][i_col];
    }
  }

  // Add some spacing
  cout << endl << endl;

  // Output the quiz grades for each student, including the total
  for (i_row = 0; i_row < size_row; i_row++) {
    // Output the student header
    cout << "Grades for Student " << (i_row + 1) << endl;
    cout << "---------------------------------------\n";
    // Set the sum to 0
    sum = 0;
    // Loop and get each quiz grade for the above student
    for (i_col = 0; i_col < size_col; i_col++) {
      // Output the quiz grade
      cout << "Quiz " << (i_col + 1) << ": " << quizzes[i_row][i_col] << endl;
      // Add the quiz grade to the sum
      sum += quizzes[i_row][i_col];
    }
    // Output the student footer
    cout << "Total : " << sum << endl << endl;
  }

  // This ends our program
  return 0;
}

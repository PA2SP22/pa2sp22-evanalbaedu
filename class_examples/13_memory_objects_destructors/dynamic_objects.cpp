/*
 * Name        : dynamic_objects.cpp
 * Author      : Luke Sathrum
 * Description : Examples of creating dynamic objects
 */

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*
 * This class will hold the quiz name and score of a student
 */
class Scores {
 public:
  /*
   * This constructor will set the name and score of a quiz.
   * NOTE: This is an inline function
   * @param string quiz_name - The name of the quiz
   * @param int score - The score for the quiz
   */
  Scores(string quiz_name, int score)
      : quiz_name_(quiz_name),
        score_(score) {
  }
  /*
   * This function prompts the user to change the quiz name and score
   */
  void SetQuizNameScore();
  /*
   * This function outputs the quiz name and score
   */
  void Output();
 private:
  string quiz_name_;
  int score_;
};

// Program starts here
int main() {
  // Create the dynamic object. To call the constructor we need ()
  Scores *object = new Scores("Midterm #1", 89);
  object->Output();
  object->SetQuizNameScore();
  object->Output();

  // This ends our program
  return 0;
}

void Scores::SetQuizNameScore() {
  cout << "Enter the new name for the quiz: ";
  cin >> quiz_name_;
  cout << "Enter the new score for the quiz: ";
  cin >> score_;
}

void Scores::Output() {
  cout << quiz_name_ << ": " << score_ << endl;
}

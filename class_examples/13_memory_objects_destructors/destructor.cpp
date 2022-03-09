/*
 * Name        : destructor.cpp
 * Author      : Luke Sathrum
 * Description : Example of creating a destructor on our Scores Class
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// This class will create a dynamic array to hold scores
class Scores {
 public:
  // Constructor to create the dynamic array of size
  Scores(int size);
  // Destructor to clean-up our dynamic array
  ~Scores();
  // Will prompt the user to enter the scores
  void FillUp();
  // Will Output all the scores in the array
  void Output();
 private:
  int size_;
  int *scores_;
};

// Program starts here
int main() {
  // This block is to help show when a destructor gets called
  {
    // Create the object. To call the constructor we need ()
    Scores object(3);
    object.FillUp();
    object.Output();
    // Leaving scope... The destructor should be called
    cout << "\nBefore leaving scope..\n";
  }
  cout << "After leaving scope..\n\n";

  // On dynamic objects the destructor gets called when we use delete
  {
    Scores *object = new Scores(2);
    object->FillUp();
    object->Output();
    cout << "\nBefore Delete...\n";
    // Call to delete, which will call the destructor
    delete object;
    cout << "After Delete... still in scope\n\n";
  }

  // This ends our program
  return 0;
}

Scores::Scores(int size) {
  cout << "The constructor has been called\n";
  // Set the internal size to the parameter
  size_ = size;
  // Create the dynamic array
  scores_ = new int[size];
}

Scores::~Scores() {
  cout << "The destructor has been called\n";
  delete[] scores_;
}

void Scores::FillUp() {
  for (int i = 0; i < size_; i++) {
    cout << "Enter score #" << (i + 1) << ": ";
    cin >> scores_[i];
  }
}

void Scores::Output() {
  for (int i = 0; i < size_; i++) {
    cout << "Score #" << (i + 1) << ": " << scores_[i] << endl;
  }
}

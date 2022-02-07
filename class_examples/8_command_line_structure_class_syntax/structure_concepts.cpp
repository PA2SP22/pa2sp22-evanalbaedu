/*
 * Name        : structure_concepts.cpp
 * Author      : Luke Sathrum
 * Description : Creating sub-structures and initializing structures
 */

#include <iostream>
using std::cout;
using std::endl;

// Create a Date structure
struct Date {
  int month;
  int day;
  int year;
};
// Create a Structure to hold person information
struct PersonInfo {
  double height;
  int weight;
  Date birthday;
};

// Program starts here
int main() {
  // Create and initialize a Date structure
  Date today = { 1, 1, 1900 };
  cout << "Today's date is " << today.month << "/"
       << today.day << "/" << today.year << endl;

  // Create a Person
  PersonInfo person;
  // Setup their data
  person.height = 6;
  person.weight = 175;
  // We are allowed to assign a structure's data to another structure
  person.birthday = today;
  // Output all of the person's info
  cout << "The person is " << person.height << " feet tall"
       << " and weighs " << person.weight << " pounds and was born "
       << person.birthday.month << "/"
       << person.birthday.day << "/" << person.birthday.year << endl;

  // This ends our program
  return 0;
}

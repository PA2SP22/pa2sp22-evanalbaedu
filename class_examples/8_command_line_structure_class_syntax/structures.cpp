/*
 * Name        : structures.cpp
 * Author      : Luke Sathrum
 * Description : Defining and Using Structures
 *             : Note: This program uses some output formatting that we have
 *                     not introduced.
 */

#include <iostream>
#include <string>
// For Formatting
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::string;
// For Formatting
using std::setw;

// Create a car structure
struct Car {
  int year;
  int doors;
  double horse_power;
  string make;
  string model;
};

// Program starts here
int main() {
  // Create a Car
  Car my_car, your_car;

  // Setup myCar's Data
  my_car.year = 2005;
  my_car.doors = 4;
  my_car.horse_power = 255;
  my_car.make = "Honda";
  my_car.model = "Pilot";

  // Get the user's info
  cout << "What is the year of your car? ";
  cin >> your_car.year;
  cout << "How many doors does your car have? ";
  cin >> your_car.doors;
  cout << "How much horsepower does your car have? ";
  cin >> your_car.horse_power;
  cout << "What is the make of your car? ";
  cin >> your_car.make;
  cout << "What is the model of your car? ";
  cin >> your_car.model;

  // Output the comparisons
  cout << endl << endl;
  cout << setw(26) << "My Car" << setw(15) << "Your Car" << endl;
  cout << "-----------------------------------------\n";
  cout << "Year:      " << setw(15) << my_car.year
       << setw(15) << your_car.year << endl;
  cout << "Doors:     " << setw(15) << my_car.doors
       << setw(15) << your_car.doors << endl;
  cout << "Horsepower:" << setw(15) << my_car.horse_power
       << setw(15) << your_car.horse_power << endl;
  cout << "Make:      " << setw(15) << my_car.make
       << setw(15) << your_car.make << endl;
  cout << "Model:     " << setw(15) << my_car.model
       << setw(15) << your_car.model << endl;

  // This ends our program
  return 0;
}

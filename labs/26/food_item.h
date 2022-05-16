#ifndef FOOD_ITEM
#define FOOD_ITEM
#include "item.h"
#include <iostream>
#include <iomanip>
class FoodItem : public Item {
 public:
  FoodItem(std::string name = "fooditem", unsigned int value = 0,
  unsigned int calories = 0, std::string unit_of_measure = "nounits",
  double units = 0.0);
  ~FoodItem();
  unsigned int calories() const;
  std::string unit_of_measure() const;
  double units() const;
  void set_calories(unsigned int new_calories);
  void set_unit_of_measure(std::string new_unit_of_measure);
  void set_units(double new_units);
  std::string ToString();
 private:
  unsigned int calories_;
  std::string unit_of_measure_;
  double units_;
};
#endif

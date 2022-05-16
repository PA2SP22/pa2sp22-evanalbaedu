#include "food_item.h"

FoodItem::FoodItem(std::string name, unsigned int value,
unsigned int calories, std::string unit_of_measure,
double units) : Item(name, value) {
  Item(name, value);
  calories_ = calories;
  unit_of_measure_ = unit_of_measure;
  units_ = units;
}

FoodItem::~FoodItem() {}

unsigned int FoodItem::calories() const {
  return calories_;
}

std::string FoodItem::unit_of_measure() const {
  return unit_of_measure_;
}

double FoodItem::units() const {
  return units_;
}

void FoodItem::set_calories(unsigned int new_calories) {
  calories_ = new_calories;
}

void FoodItem::set_unit_of_measure(std::string new_unit_of_measure) {
  unit_of_measure_ = new_unit_of_measure;
}

void FoodItem::set_units(double new_units) {
  units_ = new_units;
}

std::string FoodItem::ToString() {
  std::stringstream s;
  s << Item::ToString() << ", " << std::setprecision(2) << std::fixed << units_
  << " " << unit_of_measure_ << ", " << calories_ << " calories";
  return s.str();
}

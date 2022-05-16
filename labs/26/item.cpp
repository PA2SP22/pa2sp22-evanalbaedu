#include "item.h"

Item::Item(std::string name, unsigned int value) {
  name_ = name;
  value_ = value;
}

Item::~Item() {}

std::string Item::name() const {
  return name_;
}

unsigned int Item::value() const {
  return value_;
}

void Item::set_name(std::string new_name) {
  name_ = new_name;
}

void Item::set_value(unsigned int new_value) {
  value_ = new_value;
}

std::string Item::ToString() {
  std::stringstream s;
  s << name_ << ", $" << value_;
  return s.str();
}

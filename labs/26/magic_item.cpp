#include "magic_item.h"

MagicItem::MagicItem(std::string name, unsigned int value,
std::string description, unsigned int mana_required) : Item(name, value) {
  Item(name, value);
  description_ = description;
  mana_required_ = mana_required;
}

MagicItem::~MagicItem() {}

std::string MagicItem::description() const {
  return description_;
}

unsigned int MagicItem::mana_required() const {
  return mana_required_;
}

void MagicItem::set_description(std::string new_description) {
  description_ = new_description;
}

void MagicItem::set_mana_required(unsigned int new_mana) {
  mana_required_ = new_mana;
}

std::string MagicItem::ToString() {
  std::stringstream s;
  s << Item::ToString() << ", " << description_ << ", requires " <<
  mana_required_ <<  " mana";
  return s.str();
}

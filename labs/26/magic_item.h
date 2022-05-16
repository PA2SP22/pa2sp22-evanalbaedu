#ifndef MAGIC_ITEM
#define MAGIC_ITEM
#include "item.h"
class MagicItem : public Item {
 public:
  MagicItem(std::string name = "magicitem", unsigned int value = 0,
  std::string description = "no description", unsigned int mana_required = 0);
  ~MagicItem();
  std::string description() const;
  unsigned int mana_required() const;
  void set_description(std::string new_description);
  void set_mana_required(unsigned int new_mana);
  std::string ToString();
 private:
  std::string description_;
  unsigned int mana_required_;
};
#endif

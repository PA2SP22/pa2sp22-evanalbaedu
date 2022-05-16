#ifndef IN_ITEM
#define IN_ITEM
#include <string>
#include <sstream>
class Item {
 public:
  Item(std::string name = "item", unsigned int value = 0);
  ~Item();
  std::string name() const;
  unsigned int value() const;
  void set_name(std::string new_name);
  void set_value(unsigned int new_value);
  std::string ToString();
 private:
  std::string name_;
  unsigned int value_;
};
#endif

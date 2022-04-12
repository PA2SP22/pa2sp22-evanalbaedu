#ifndef SL_LIST
#define SL_LIST
#include "sl_node.h"
#include <cstddef>
#include <string>
#include <sstream>
#include <iostream>

class SLList {
 public:
  SLList() {
    head_ = nullptr;
    size_ = 0;
  }
  ~SLList() {
    Clear();
  }
  void InsertHead(int content);
  void RemoveHead();
  void Clear();
  unsigned int size() const;
  std::string ToString() const;
 private:
  SLNode* head_;
  unsigned int size_;
};
#endif

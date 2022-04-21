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
    tail_ = nullptr;
    size_ = 0;
  }
  ~SLList() {
    Clear();
  }
  void Insert(int content);
  bool RemoveFirstOccurence(int content);
  void InsertHead(int content);
  void InsertTail(int content);
  void RemoveHead();
  void RemoveTail();
  int GetHead() const;
  int GetTail() const;
  void Clear();
  unsigned int size() const;
  std::string ToString() const;

 private:
  SLNode* head_;
  SLNode* tail_;
  unsigned int size_;
};
#endif

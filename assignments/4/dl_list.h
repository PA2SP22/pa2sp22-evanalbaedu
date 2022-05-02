#ifndef DL_LIST
#define DL_LIST
//#include <iostream>
#include <string>
#include "dl_node.h"

class DLList {
 public:
  DLList();
  ~DLList();
  int GetSize() const;
  void PushFront(int num);
  void PushBack(int num);
  int GetFront() const;
  int GetBack() const;
  void PopFront();
  void PopBack();
  void RemoveFirst(int num);
  void RemoveAll(int num);
  bool Exists(int num);
  void Clear();
  std::string ToStringForwards();
  std::string ToStringBackwards();
 private:
  int size_;
  DLNode* head_;
  DLNode* tail_;
};
#endif


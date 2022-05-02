#include "dl_list.h"

DLList::DLList() {
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0;
}

DLList::~DLList() {
  Clear();
}

int DLList::GetSize() const {
  return size_;
}

void DLList::PushFront(int num) {} 

void DLList::PushBack(int num) {}

int DLList::GetFront() const {}

int DLList::GetBack() const {}

void DLList::PopFront() {}

void DLList::PopBack() {}

void DLList::RemoveFirst(int num) {}

void DLList::RemoveAll(int num) {}

bool DLList::Exists(int num) {}

void DLList::Clear() {}

std::string DLList::ToStringForwards() {}

std::string DLList::ToStringBackwards() {}


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

void DLList::PushFront(int num) {
  DLNode* new_node = new DLNode();
  size_ += 1;
  new_node->SetContents(num);
  if (head_ == nullptr) {
    tail_ = head_;
  }
  new_node->SetNext(head_);
  if (head_ != nullptr) {
    head_->SetPrevious(new_node);
  }
  head_ = new_node;
} 

void DLList::PushBack(int num) {
  if (head_ == nullptr) {
    PushFront(num);
  } else {
    DLNode* new_node = new DLNode();
    size_ += 1;
    new_node->SetContents(num);
    new_node->SetNext(head_);
    tail_ = new_node;
  }
 }

int DLList::GetFront() const {
  if (head_ == nullptr) {
    std::cerr << "List Empty";
    return 0;
  }
  return head_->GetContents();
}

int DLList::GetBack() const {
  if (head_ == nullptr) {
    std::cerr << "List Empty";
    return 0;
  }
  return tail_->GetContents();
}

void DLList::PopFront() {
  if (head_ == nullptr) {
    std::cerr << "List Empty";
    return;
  }
  DLNode* first = head_;
  head_ = head_->GetNext();
  delete first;
  size_ -= 1;
  if (head_ == nullptr) {
    tail_ = nullptr;
  }
}

void DLList::PopBack() {
  if (head_ == nullptr) {
    std::cerr << "List Empty";
    return;
  }
}

void DLList::RemoveFirst(int num) {
  std::cerr << "Not Found";
}

void DLList::RemoveAll(int num) {
  std::cerr << "Not Found";
}

bool DLList::Exists(int num) {
  DLNode* it = head_;
  while (it != nullptr) {
    if (it->GetContents() == num) {
      return true;
    }
    it = it->GetNext(); 
  }
  return false;
}

void DLList::Clear() {}

std::string DLList::ToStringForwards() {
  if (head_ == nullptr) {
    std::cerr << "List Empty"; 
    return "";
  }
  std::stringstream s;
  DLNode* first = head_;
  while (first != nullptr) {
    if (first->GetNext() == nullptr) {
      s << first->GetContents();
    } else {
      s << first->GetContents() << ", ";
    }
    first = first->GetNext();
  }
  std::cout << s.str() << std::endl;
  return s.str();
}

std::string DLList::ToStringBackwards() {
 if (size_ == 0) {
    std::cerr << "List Empty"; 
    return "";
  }
}


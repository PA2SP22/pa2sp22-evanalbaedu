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
    new_node->SetPrevious(nullptr);
    new_node->SetNext(nullptr);
    head_ = new_node;
    tail_ = new_node;
  } else {
    DLNode* old_head = head_;
    old_head->SetPrevious(new_node);
    new_node->SetPrevious(nullptr); 
    new_node->SetNext(old_head);
    head_ = new_node;
  }
}

void DLList::PushBack(int num) {
  if (head_ == nullptr) {
    DLNode* new_node = new DLNode();
    size_ += 1;
    new_node->SetContents(num);
    new_node->SetPrevious(nullptr);
    new_node->SetNext(nullptr);
    head_ = new_node;
    tail_ = new_node;
  } else {
    DLNode* new_node = new DLNode();
    size_ += 1;
    new_node->SetContents(num);
    DLNode* old_tail = tail_;
    old_tail->SetNext(new_node);
    new_node->SetPrevious(old_tail);
    new_node->SetNext(nullptr);
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
  if (head_ != nullptr) {
    head_->SetPrevious(nullptr);
  }
}

void DLList::PopBack() {
  if (head_ == nullptr) {
    std::cerr << "List Empty";
  } else if (size_ == 1) {
    PopFront();
  } else {
    DLNode* last = tail_;
    tail_  = tail_->GetPrevious();
    delete last;
    size_ -= 1;
    tail_->SetNext(nullptr);
  }
}

void DLList::RemoveFirst(int num) {
  DLNode* it = head_;
  DLNode* trailer = head_;
  while (it != nullptr && num != it->GetContents()) {
    trailer = it;
    it = it->GetNext();
  }
  if (it == nullptr) {
    std::cerr << "Not Found";
  } else if (it == head_) {
    PopFront();
  } else if (it == tail_) {
    PopBack();
  } else {
    trailer->SetNext(it->GetNext());
    delete it;
    size_ -= 1;
  }
}

void DLList::RemoveAll(int num) {
// Look through list
// loop # of times using RemoveFirst()
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

void DLList::Clear() {
  if (head_ == nullptr) {
    return;
  }
  DLNode* it = head_;
  while (it != nullptr) {
    head_ = head_->GetNext();
    delete it;
    it = head_;
  }
  size_ = 0;
  tail_ = nullptr;
}

std::string DLList::ToStringForwards() {
  if (size_ == 0) {
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
  std::stringstream s;
  DLNode* back  = tail_;
  while (back != nullptr) {
    if (back->GetPrevious() == nullptr) {
      s << back->GetContents();
    } else {
      s << back->GetContents() << ", ";
    }
    back = back->GetPrevious();
  }
  std::cout << s.str() << std::endl;
  return s.str();
}


#include "sl_list.h"

void SLList::InsertHead(int content) {
  SLNode* new_node = new SLNode(content);
  size_ += 1;
  new_node->set_next_node(head_);
  head_ = new_node;
}

void SLList::RemoveHead() {
  if (head_ == nullptr) {
    return;
  }
  SLNode* temp = head_;
  head_ = head_->next_node();
  delete temp;
  size_ -= 1;
}

void SLList::Clear() {
  if (head_ == nullptr) {
    return;
  }
  SLNode* it = head_;
  while (it != nullptr) {
    head_ = head_->next_node();
    delete it;
    it = head_;
  }
  size_ = 0;
}

unsigned int SLList::size() const {
  return size_;
}

std::string SLList::ToString() const {
  if (head_ == nullptr) {
    return "";
  }
  std::stringstream s;
  SLNode* it = head_;
  while (it != nullptr) {
    if (it->next_node() == nullptr) {
      s << it->contents();
    } else {
      s << it->contents() << ", ";
    }
    it = it->next_node();
  }
  return s.str();
}


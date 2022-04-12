#include "sl_list.h"

void SLList::InsertHead(int content) {
  if (head_ == nullptr) {
    head_ = new SLNode(content);
  } else {
    head_->set_next_node();
  } 
  size_ += 1;
}

void SLList::RemoveHead() {

} 

void SLList::Clear() {

}

unsigned int SLList::size() const {
  return size_;
}

std::string SLList::ToString() const {
  //if (head_ != nullptr) {
  //  std::stringstream s;
  //  while (head_ != nullptr) {
  //    s << head_->contents();
  //  }
  //  return s.str();
  //}
  return "";
}


#include "dl_node.h"

DLNode::DLNode() {
  contents_ = 0;
  prev_ = nullptr;
  next_ = nullptr;
}

DLNode::~DLNode() {}

void DLNode::SetContents(int contents) {
  contents_ = contents;
}

void DLNode::SetNext(DLNode* next) {
  next_ = next;
}

void DLNode::SetPrevious(DLNode* prev) {
  prev_ = prev;
}

int DLNode::GetContents() const {
  return contents_;
}

DLNode* DLNode::GetNext() const {
  return next_;
}

DLNode* DLNode::GetPrevious() const {
  return prev_;
}


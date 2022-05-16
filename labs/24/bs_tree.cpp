#include "bs_tree.h"

BSTree::BSTree() {
  root_ = nullptr;
  size_ = 0;
}

BSTree::~BSTree() {
  Clear();
}

bool BSTree::Insert(int data) {
  return Insert(data, root_);
}

void BSTree::Clear() {
  Clear(root_);
}

unsigned int BSTree::GetSize() const {
  return size_;
}

std::string BSTree::InOrder() {
  return InOrder(root_);
}

/* PRIVATE */
bool BSTree::Insert(int data, BSTNode*& subroot) {
  if (subroot == nullptr) {
    BSTNode* new_node = new BSTNode(data);
    subroot  = new_node;
    size_ += 1;
    return true;
  } else if (data < subroot->GetContents()) {
    return Insert(data, subroot->GetLeftChild());
  } else if (data > subroot->GetContents()) {
    return Insert(data, subroot->GetRightChild());
  } else {
    return false;
  }
}

void BSTree::Clear(BSTNode*& subroot) {
  if (subroot == nullptr) {
    return;
  }
  Clear(subroot->GetLeftChild());
  Clear(subroot->GetRightChild());
  delete subroot;
  size_ -= 1;
  subroot = nullptr;
}

std::string BSTree::InOrder(BSTNode* subroot) {
  if (subroot == nullptr) {
    return "";
  }
  std::stringstream s;
  s << InOrder(subroot->GetLeftChild());
  s << subroot->GetContents() << " ";
  s << InOrder(subroot->GetRightChild());
  return s.str();
}

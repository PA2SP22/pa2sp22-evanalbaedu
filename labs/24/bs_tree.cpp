#include "bs_tree.h"

BSTree::BSTree() {
  root_ = nullptr;
  size_ = 0;
}

BSTree::~BSTree() {
   Clear();
}

bool BSTree::Insert(int data) {
  Insert(data, root_);
}

void BSTree::Clear() {

}

unsigned int BSTree::GetSize() const {
  return size_;
}

std::string BSTree::InOrder() {
  return "test";

}

/* PRIVATE */
bool BSTree::Insert(int data, BSTNode*& subroot) {
  if (subroot == nullptr) {
    BSTNode* new_node = new BSTNode(data);
    subroot  = new_node;
    size_ += 1;
    return true;
  } else if (data < subroot->GetContents()) {
    subroot = subroot->GetLeftChild();
    return Insert(data, subroot); 
  } else if (data > subroot->GetContents()) {
    subroot  = subroot->GetRightChild();
    return Insert(data, subroot);
  } else {
    return false;
  }
}

void BSTree::Clear(BSTNode*& subroot) {

}

std::string BSTree::InOrder(BSTNode* subroot) {

  std::stringstream s;
  if (subroot != nullptr) {
    s << InOrder(subroot->GetLeftChild());
    s << subroot->GetContents() << " ";
    s << InOrder(subroot->GetRightChild());
  }
  return s.str();
}
 

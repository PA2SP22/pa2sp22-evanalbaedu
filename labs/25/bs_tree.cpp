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

bool BSTree::Remove(int data) {
  return Remove(data, root_);
}

int BSTree::FindMin() {
  FindMin(root_);
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

bool BSTree::Remove(int data, BSTNode*& subroot) {
  if (subroot == nullptr) {
    return false;
  } else if (subroot->GetContents() == data) {
    // No Children
    if (subroot->GetLeftChild() == nullptr && subroot->GetRightChild() == nullptr) {
      delete subroot;
      subroot == nullptr;
    // 1 Child
    } else if (subroot->GetLeftChild() != nullptr || subroot->GetRightChild() != nullptr) {
      BSTNode* temp = subroot;
      if (subroot->GetLeftChild() != nullptr) {
        root_ = subroot->GetLeftChild();
      } else {
        root_ = subroot->GetRightChild();
      }
      delete temp;
    // 2 Children
    } else if (subroot->GetLeftChild() != nullptr && subroot->GetRightChild() != nullptr) {
      // Test
    }
    return true;
  } else if (data > subroot->GetContents()) {
    return Remove(data, subroot->GetRightChild());
  } else if (data < subroot->GetContents()) {
    return Remove(data, subroot->GetLeftChild());
  }
}

int BSTree::FindMin(BSTNode* subroot) const {
  if (subroot == nullptr) {
    return 0;
  } else if (subroot->GetLeftChild() == nullptr) {
    return subroot->GetContents();
  }
  return FindMin(subroot->GetLeftChild());
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

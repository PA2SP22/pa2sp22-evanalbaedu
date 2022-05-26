#ifndef BST_TREET
#define BST_TREET
#include <cstddef>
#include <string>
#include <sstream>
#include "bst_nodet.h"

template <typename T>
class BSTreeT {
 public:
  BSTreeT() {
    root_ = nullptr;
    size_ = 0;
  }

  ~BSTreeT() {
    Clear();
  }

// Returns the number of nodes in the tree.
  int GetSize() const {
    return size_;
  }

// Deletes all nodes in the tree.
  void Clear() {
    Clear(root_);
  }

// Has a parameter which is the value to add. If the
// value is already in the tree just increment that node's count.
// Returns the count of the value in the node. i.e. returns 1 the first
// time the value is added to the tree. Returns 2 the second time the
// value is added, 3 the third time, etc.
  int Insert(T data) {
    return Insert(data, root_);
  }

// Searches your tree for a particular value. If found
// returns true, else returns false.
  bool Exists(T data) {
    return Exists(data, root_);
  }

// Searches your tree for a particular value and
// decrements the corresponding count. If the current count is 1
// remove the node instead of decrementing the count. Returns the
// current count of the value in the tree, 0 if it was just removed, and
// -1 if it doesn't exist in the tree.
  int Remove(T data) {
    return Remove(data, root_);
  }

// Searches for a particular value. Returns a pointer to
// the node if found otherwise returns NULL.
  BSTNodeT<T>* Get(T data) {
    return Get(data, root_);
  }

// Outputs the contents of the nodes in
// the tree (in order) as a comma separated list ("hello", "goodbye",
// etc). If the list is empty return the empty string.
  std::string ToStringForwards() {
    return ToStringForwards(root_);
  }

// Outputs the contents of the nodes in
// the tree (in backwards order) as a comma separated list
// ("goodbye", "hello", etc). If the list is empty return the empty
// string.
  std::string ToStringBackwards() {
    return ToStringBackwards(root_);
  }

 private:
  BSTNodeT<T>* root_;
  unsigned int size_;

  void Clear(BSTNodeT<T>*& subroot) {
    if (subroot == nullptr) {
      return;
    }
    Clear(subroot->GetLeft());
    Clear(subroot->GetRight());
    delete subroot;
    subroot = nullptr;
    size_ -= 1;
  }

  int Insert(T data, BSTNodeT<T>*& subroot) {
    if (subroot == nullptr) {
      BSTNodeT<T>* new_node = new BSTNodeT<T>(data);
      subroot  = new_node;
      size_ += 1;
      subroot->IncrementCount();
      return subroot->GetCount();
    } else if (data < subroot->GetContents()) {
      return Insert(data, subroot->GetLeft());
    } else if (data > subroot->GetContents()) {
      return Insert(data, subroot->GetRight());
    } else {
      subroot->IncrementCount();
      return subroot->GetCount();
    }
  }

  bool Exists(T data, BSTNodeT<T>*& subroot) {
    if (subroot == nullptr) {
      return false;
    } else if (data == subroot->GetContents()) {
      return true;
    } else if (data < subroot->GetContents()) {
      return Exists(data, subroot->GetLeft());
    } else {
      return Exists(data, subroot->GetRight());
    }
  }

  int Remove(T data, BSTNodeT<T>*& subroot) {
    // Search through Binary Tree.
    if (subroot == nullptr) {
      return -1;
    } else if (data < subroot->GetContents()) {
      return Remove(data, subroot->GetLeft());
    } else if (data > subroot->GetContents()) {
      return Remove(data, subroot->GetRight());
    }

    // Run this if Tree Node is found to remove.
    // If Tree Node has already been deleted previously.
    if (subroot->GetCount() > 1) {
      subroot->DecrementCount();
      return subroot->GetCount();
    // No Children
    } else if ( (subroot->GetLeft() == nullptr) &&
    (subroot->GetRight() == nullptr) ) {
      delete subroot;
      subroot = nullptr;
      size_ -= 1;
      return 0;
    // 2 Children
    } else if ( (subroot->GetLeft() != nullptr) &&
    (subroot->GetRight() != nullptr) ) {
      BSTNodeT<T>* temp = subroot;
      subroot = subroot->GetLeft();
      delete temp;
      size_ -= 1;
      return 0;
    // 1 Child
    } else if ( (subroot->GetLeft() != nullptr) ||
    (subroot->GetRight() != nullptr) ) {
      BSTNodeT<T>* temp = subroot;
      if (subroot->GetLeft() != nullptr) {
        subroot = subroot->GetLeft();
      } else {
        subroot = subroot->GetRight();
      }
      delete temp;
      size_ -= 1;
      return 0;
    } else {
      T min = FindMin(subroot->GetRight());
      subroot->SetContents(min);
      return Remove(min, subroot->GetRight());
    }
    return -1;
  }

  BSTNodeT<T>* Get(T data, BSTNodeT<T>*& subroot) {
    if (subroot == nullptr) {
      return nullptr;
    } else if (data == subroot->GetContents()) {
      return subroot;
    } else if (data < subroot->GetContents()) {
      return Get(data, subroot->GetLeft());
    } else {
      return Get(data, subroot->GetRight());
    }
  }

  std::string ToStringForwards(BSTNodeT<T>*& subroot) {
    std::stringstream s;
    if (subroot == nullptr) {
      return s.str();
    }
    if (subroot->GetLeft() != nullptr) {
      s << ToStringForwards(subroot->GetLeft()) << ", ";
    }
    s << subroot->GetContents();
    if (subroot->GetRight() != nullptr) {
      s << ", " << ToStringForwards(subroot->GetRight());
    }
    return s.str();
  }

  std::string ToStringBackwards(BSTNodeT<T>*& subroot) {
    std::stringstream s;
    if (subroot == nullptr) {
      return s.str();
    }
    if (subroot->GetRight() != nullptr) {
      s << ToStringBackwards(subroot->GetRight()) << ", ";
    }
    s << subroot->GetContents();
    if (subroot->GetLeft() != nullptr) {
      s << ", " << ToStringBackwards(subroot->GetLeft());
    }
    return s.str();
  }

  T FindMin(BSTNodeT<T>* subroot) const {
    if (subroot == nullptr) {
      return 0;
    } else if (subroot->GetLeft() == nullptr) {
      return subroot->GetContents();
    }
    return FindMin(subroot->GetLeft());
  }
};
#endif

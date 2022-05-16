#ifndef BS_TREE
#define BS_TREE
#include "bst_node.h"
#include <string>
#include <sstream>
class BSTree {
 public:
  BSTree();
  ~BSTree();
  bool Insert(int data);
  bool Remove(int data);
  int FindMin();
  void Clear();
  unsigned int GetSize() const;
  std::string InOrder();
 private:
  BSTNode* root_;
  unsigned int size_;
  bool Insert(int data, BSTNode*& subroot);
  bool Remove(int data, BSTNode*& subroot);
  int FindMin(BSTNode* subroot) const;
  void Clear(BSTNode*& subroot);
  std::string InOrder(BSTNode* subroot);
};
#endif


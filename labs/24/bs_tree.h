#ifndef BS_TREE
#define BS_TREE
#include "bst_node.h"
#include <string>
class BSTree {
 public:
  BSTree();
  ~BSTree();
  bool Insert(int data);
  void Clear();
  unsigned int GetSize() const;
  std::string InOrder();
 private:
  BSTNode* root_;
  unsigned int size_;
  bool Insert(int data, BSTNode*& subroot);
  void Clear(BSTNode*& subroot); 
  std::string InOrder(BSTNode* subroot);
};
#endif


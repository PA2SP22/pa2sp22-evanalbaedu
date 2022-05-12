#ifndef BST_NODE
#define BST_NODE
#include <cstddef>


class BSTNode {
 public:
  BSTNode();
  BSTNode(int data);
  ~BSTNode();
  void SetContents(int data);
  int GetContents() const;
  int& GetContents();
  void SetLeftChild(BSTNode* child);
  void SetRightChild(BSTNode* child);
  BSTNode* GetLeftChild() const;
  BSTNode*& GetLeftChild();
  BSTNode* GetRightChild() const;
  BSTNode*& GetRightChild();
 private:
  BSTNode* left_;
  BSTNode* right_;
  int contents_;
};
#endif


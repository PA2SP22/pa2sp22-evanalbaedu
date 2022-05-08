#include "bst_node.h"

BSTNode::BSTNode() {
  left_ = nullptr;
  right_ = nullptr;
  contents_ = 0;
}

BSTNode::BSTNode(int data) {
  left_ = nullptr;
  right_ = nullptr;
  contents_ = data;
}

BSTNode::~BSTNode() {
  left_ = nullptr;
  right_ = nullptr;
}

void BSTNode::SetContents(int data) {
  contents_ = data;
}

int BSTNode::GetContents() const {
  return contents_;
}

int& BSTNode::GetContents() {
  return contents_;
}

void BSTNode::SetLeftChild(BSTNode* child) {
  left_ = child;
}

void BSTNode::SetRightChild(BSTNode* child) {
  right_ = child;
}

BSTNode* BSTNode::GetLeftChild() const {
  return left_;
}

BSTNode*& BSTNode::GetLeftChild() {
  return left_;
}

BSTNode* BSTNode::GetRightChild() const {
  return right_;
}

BSTNode*& BSTNode::GetRightChild() {
  return right_;
}


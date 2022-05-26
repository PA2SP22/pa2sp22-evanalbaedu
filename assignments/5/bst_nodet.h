#ifndef BST_NODET
#define BST_NODET
#include <cstddef>
#include <string>

template <typename T>
class BSTNodeT {
 public:
  BSTNodeT() {
    contents_ = T();
    count_ = 0;
    left_ = nullptr;
    right_ = nullptr;
  }

  BSTNodeT(T data) {
    contents_ = data;
    count_ = 0;
    left_ = nullptr;
    right_ = nullptr;
  }

  ~BSTNodeT() {
    left_ = nullptr;
    right_ = nullptr;
  }

  void SetContents(T data) {
    contents_ = data;
  }

  void SetLeft(BSTNodeT* child) {
    left_ = child;
  }

  void SetRight(BSTNodeT* child) {
    right_ = child;
  }

  void IncrementCount() {
    count_ += 1;
  }

  void DecrementCount() {
    count_ -= 1;
  }

  T GetContents() const {
    return contents_;
  }

  BSTNodeT*& GetLeft() {
    return left_;
  }

  BSTNodeT*& GetRight() {
    return right_;
  }

  unsigned int GetCount() const {
    return count_;
  }

 private:
  T contents_;
  unsigned int count_;
  BSTNodeT<T>* left_;
  BSTNodeT<T>* right_;
};
#endif

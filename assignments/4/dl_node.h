#ifndef DL_NODE
#define DL_NODE
#include <cstddef>

class DLNode {
 public:
  DLNode();
  ~DLNode();
  void SetContents(int contents);
  void SetNext(DLNode* next);
  void SetPrevious(DLNode* prev);
  int GetContents() const;
  DLNode* GetNext() const;
  DLNode* GetPrevious() const;
 private:
  int contents_;
  DLNode* prev_; 
  DLNode* next_;
};
#endif


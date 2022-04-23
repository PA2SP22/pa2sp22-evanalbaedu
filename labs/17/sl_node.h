#ifndef SL_NODE
#define SL_NODE
class SLNode {
 public:
  SLNode() {
    next_node_ = nullptr;
    contents_ = 0;
  }

  SLNode(int load) {
    next_node_ = nullptr;
    contents_ = load;
  }

  void set_contents(int content);
  int contents() const;
  void set_next_node(SLNode* next_node);
  SLNode* next_node() const;
 private:
  SLNode* next_node_;
  int contents_;
};

#endif

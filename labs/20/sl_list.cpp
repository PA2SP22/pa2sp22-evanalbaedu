#include "sl_list.h"

void SLList::Insert(int content) {
  if ((head_ == nullptr) || (content <= head_->contents())) {
    InsertHead(content);
  } else if (content >= tail_->contents()) {
    InsertTail(content);
  } else {
    SLNode* it = head_;
    SLNode* trailer = head_;
    while (it->contents() < content) {
      trailer = it;
      it = it->next_node();
    }
    SLNode* new_node = new SLNode(content);
    size_ += 1;
    new_node->set_next_node(it);
    trailer->set_next_node(new_node);
  }
}

bool SLList::RemoveFirstOccurence(int content) {
  if (head_ == nullptr) {
    return false;
  }
  SLNode* it = head_;
  SLNode* trailer = head_;
  while (it != nullptr && content != it->contents()) {
    trailer = it;
    it = it->next_node();
  }
  if (it == nullptr) {
    return false;
  } else if (it == head_) {
    RemoveHead();
    return true;
  } else if (it == tail_) {
    RemoveTail();
    return true;
  } else {
    trailer->set_next_node(it->next_node());
    delete it;
    size_ -= 1;
    return true;
  }
}


void SLList::InsertHead(int content) {
  SLNode* new_node = new SLNode(content);
  size_ += 1;
  new_node->set_next_node(head_);
  if (head_ == nullptr) {
    tail_ = new_node;
  }
  head_ = new_node;
}

void SLList::InsertTail(int content) {
  if (head_ == nullptr) {
    InsertHead(content);
  } else {
    SLNode* new_node = new SLNode(content);
    tail_->set_next_node(new_node);
    tail_ = new_node;
    size_++;
  }
}

void SLList::RemoveHead() {
  if (head_ != nullptr) {
    if (head_ == tail_) {
      SLNode* temp = head_;
      head_ = head_->next_node();
      delete temp;
      if (head_ == nullptr) {
        tail_ = nullptr;
      }
      size_--;
    } else {
      SLNode* temp = head_;
      head_ = head_->next_node();
      delete temp;
      size_--;
    }
  }
}

void SLList::RemoveTail() {
  if (head_ != nullptr) {
    if (head_ != nullptr &&  head_ == tail_) {
      RemoveHead();
    } else {
      SLNode* it = head_;
      while (it->next_node() != tail_) {
        it = it->next_node();
      }
      it->set_next_node(nullptr);
      delete tail_;
      tail_ = it;
      size_ -= 1;
    }
  }
}

int SLList::GetHead() const {
  if (head_ != nullptr) {
    return head_->contents();
  }
  return 0;
}

int SLList::GetTail() const {
  if (tail_ != nullptr) {
    return tail_->contents();
  }
  return 0;
}

void SLList::Clear() {
  if (head_ == nullptr) {
    return;
  }
  SLNode* it = head_;
  while (it != nullptr) {
    head_ = head_->next_node();
    delete it;
    it = head_;
  }
  size_ = 0;
  tail_ = nullptr;
}

unsigned int SLList::size() const {
  return size_;
}

std::string SLList::ToString() const {
  if (head_ == nullptr) {
    if (tail_ != nullptr) {
      return std::to_string(tail_->contents());
    }
    return "";
  }
  std::stringstream s;
  SLNode* it = head_;
  while (it != nullptr) {
    if (it->next_node() == nullptr) {
      s << it->contents();
    } else {
      s << it->contents() << ", ";
    }
    it = it->next_node();
  }
  return s.str();
}


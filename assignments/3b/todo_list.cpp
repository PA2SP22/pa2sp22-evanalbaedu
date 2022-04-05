/*
 * Name        : todo_list.cpp
 * Author      : Evan Alba
 * Description : CPP File for class TodoList.
 */
#include "todo_list.h"

void TodoList::AddItem(TodoItem* add) {
  if (size_ == cap_) {
    IncreaseCap();
  }
  list_[size_] = add;
  size_ += 1;
}

void TodoList::DeleteItem(unsigned int area) {
  if ((area > 0) && (area <= size_)) {
    delete list_[area - 1];
    list_[area - 1] = nullptr;
    size_ -= 1;
    TightenArray(area - 1);
  }
}

TodoItem* TodoList::GetItem(int spot) {
  if ((size_ > 0) && (size_ <= cap_)) {
    if (list_[spot-1] == nullptr) {
      return nullptr;
    }
    return list_[spot - 1];
  }
  return nullptr;
}

unsigned int TodoList::GetSize() const {
  return size_;
}

unsigned int TodoList::GetCapacity() const {
  return cap_;
}

void TodoList::Sort() {
  for (unsigned int i = 0; i <= (size_ - 1); i++) {
    int j = i;
    while ((j > 0) && (list_[j]->priority() < list_[j - 1]->priority())) {
      std::swap(list_[j], list_[j - 1]);
      j -= 1;
    }
  }
}

std::string TodoList::ToFile() {
  if ((size_ > 0) && (size_ <= cap_)) {
    std::stringstream all;
    for (unsigned int i = 0; i < size_; i++) {
        all << list_[i]->ToFile() << std::endl;
    }
    return all.str();
  }
  return "";
}

std::ostream &operator << (std::ostream &out, const TodoList &obj) {
  for (unsigned int i = 0; i < obj.size_; i++) {
    out << obj.list_[i]->description() << obj.list_[i]->priority()
    << obj.list_[i]->completed() << std::endl;
  }
  return out;
}

/* PRIVATE */
void TodoList::IncreaseCap() {
  cap_ += 10;
  TodoItem** extend = new TodoItem*[cap_];
  for (unsigned int i = 0; i < size_; i++) {
    extend[i] = list_[i];
  }
  for (unsigned int i = size_; i < cap_; i++) {
    extend[i] = nullptr;
  }
  delete[] list_;
  list_ = extend;
}

void TodoList::TightenArray(int start) {
  for (unsigned int i = start; i < size_; i++) {
    if (list_[i + 1] != nullptr) {
      list_[i] = list_[i + 1];
    }
  }
}

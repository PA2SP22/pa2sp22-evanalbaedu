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

void TodoList::DeleteItem(int area) {
  if (list_[area-1] != nullptr) {
    list_[area-1] = nullptr;
    TightenArray(); 
    size_ -= 1;
  }
}

TodoItem* TodoList::GetItem(int spot) {
  if (list_[spot-1] == nullptr) {
    return nullptr;
  }
  return list_[spot-1];
}

unsigned int TodoList::GetSize() const {
  return size_;
}

unsigned int TodoList::GetCapacity() const {
  return cap_;
}

void TodoList::Sort() {}

std::string TodoList::ToFile() {
  if (size_ == 0) {
    return "";
  }
  std::stringstream all;
  for (int i = 0; i < cap_; i++) {
    if (list_[i] != nullptr) {
      all << list_[i]->ToFile() << std::endl;
    }
  }
  return all.str();
}

std::ostream& operator << (std::ostream &out, const TodoList &obj) {
  // Call toFile()
  for (int i = 0; i < cap_; i++) {
    if (list_[i] != nullptr) {
      out << i;
    }
  }
  // return out;
}

/* PRIVATE */
void TodoList::IncreaseCap() {
  cap_ += 10;
  TodoItem** extend = new TodoItem*[cap_];
  for (unsigned int i = 0; i < cap_; i++) {
    extend[i] = list_[i];
  }
  delete[] list_;
  list_ = extend;
}

void TodoList::TightenArray() {
  unsigned int need = size_;
  for (unsigned int i = 0; i < cap_; i++) {
      
    if (need > 0) {
    
      if (list_[i] == nullptr) {
        // Look for number
        for (unsigned int x = 0; i < cap_; i++) {
          if (list_[x] != nullptr) {
            list_[i] = list_[x];
              break;
          }
        }
        need -= 1;
      }
        
    } else {
      break;
    }
      
  }
}
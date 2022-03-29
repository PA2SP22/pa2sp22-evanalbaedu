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
  for (int i = 0; i < cap_; i++) {
    if (list_[i] == nullptr) {
      list_[i] = add;
      size_ += 1;
      break;
    }
  }
}

void TodoList::DeleteItem(int area) {
  if (list_[area-1] != nullptr) {
    list_[area-1] = nullptr;
    TightenArray(); 
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

std::string TodoList::ToFile() {}

std::ostream& operator << (std::ostream &out, const TodoList &obj) {}

/* PRIVATE */
void TodoList::IncreaseCap() {
  cap_ += 10;
}

void TodoList::TightenArray() {
  if (size_  >= 1) {
    int need = size_;
    for (int i = 0; i < cap_; i++) {
      
      if (need > 0) {
    
        if (list_[i] == nullptr) {
          // Look for number
          for (int x = 0; i < cap_; i++) {
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
}
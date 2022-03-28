/*
 * Name        : todo_list.cpp
 * Author      : Evan Alba
 * Description : CPP File for class TodoList.
 */
#include "todo_list.h"
#include "todo_item.cpp"

void TodoList::AddItem(TodoItem* add = new TodoItem()) {
  if (size_ == cap_) {
    cap_ += 10;
  }
  for (int i = 0; i < cap_; i++) {
    if (list_[i] == nullptr) {
      list_[i] = add;
      break;
    }
  }
}
void TodoList::DeleteItem(int area) {}
int* TodoList::GetItem(int spot) {}
unsigned int TodoList::GetSize() const {
  return size_;
}
unsigned int TodoList::GetCapacity() const {
  return cap_;
}
void TodoList::Sort() {}
std::string TodoList::ToFile() {}
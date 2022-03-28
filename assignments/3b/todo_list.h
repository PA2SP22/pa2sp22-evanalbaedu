/*
 * Name        : todo_item.cpp
 * Author      : Evan Alba
 * Description : Header File for class TodoList.
 */
#ifndef TODO_LIST
#define TODO_LIST
#include <iostream>
#include <string>

class TodoList {
 public:
    TodoList() {
      list_ = new std::string[cap_];
      for (unsigned int i = 0; i < cap_; i++) {
        list_[i] = nullptr;
      }
    }
    
    ~TodoList() {}
  
 private:
    unsigned int size_ = 0; /* Current size of your list. */
    unsigned int cap_ = 25; /* Max capacity of your list. */
    std::string* list_; /* Pointer to TodoItem*. */
};
#endif

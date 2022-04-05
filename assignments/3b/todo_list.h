/*
 * Name        : todo_item.cpp
 * Author      : Evan Alba
 * Description : Header File for class TodoList.
 */
#ifndef TODO_LIST
#define TODO_LIST
#include "todo_item.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

class TodoList {
 public:
    TodoList() {
      list_ = new TodoItem*[cap_];
      for (unsigned int i = 0; i < cap_; i++) {
        list_[i] = nullptr;
      }
    }
    ~TodoList() {
      for (unsigned int i = 0; i < size_; i++) {
        delete list_[i];
      }
      delete[] list_;
    }
    void AddItem(TodoItem* add);
    void DeleteItem(unsigned int area);
    TodoItem* GetItem(int spot);
    unsigned int GetSize() const;
    unsigned int GetCapacity() const;
    void Sort();
    std::string ToFile();
    friend std::ostream& operator << (std::ostream &out, const TodoList &obj);

 private:
    unsigned int size_ = 0; /* Current size of your list. */
    unsigned int cap_ = 25; /* Max capacity of your list. */
    TodoItem** list_; /* Pointer to TodoItem*. */
    void IncreaseCap();
    void TightenArray(int start);
};
#endif

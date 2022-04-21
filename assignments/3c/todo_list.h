/*
 * Name        : todo_list.h
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
    /* PUBLIC Setters Prototypes for Todo List Class */
    TodoList();
    ~TodoList();
    void AddItem(TodoItem* add);
    void DeleteItem(unsigned int location);
    TodoItem* GetItem(int location);
    unsigned int GetSize() const;
    unsigned int GetCapacity() const;
    void Sort();
    std::string ToFile();
    friend std::ostream& operator << (std::ostream &out, const TodoList &obj);

 private:
    /* PRIVATE Data for Todo List Class */
    unsigned int size_; /* Current size of your list. */
    unsigned int cap_; /* Max capacity of your list. */
    TodoItem** list_; /* Pointer to TodoItem*. */
    /* PRIVATE Prototypes for Todo List Class */
    void IncreaseCap();
    void TightenArray(int start);
};
#endif

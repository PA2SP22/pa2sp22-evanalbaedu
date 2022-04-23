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
    /* 
      Creates a dynamic array of 25 elements and initializes the elements 
      to NULL. 
    */
    TodoList();

    /* 
      Frees the memory for all TodoItems 
      Frees the memory for the dynamic TodoItem* array
    */
    ~TodoList();

    /*
      Add an item to the list.
      If there is room in the array add the new 
      dynamic instance to the first available spot (i.e. the current size). If
      the array is full, increase capacity by 10 and then add the item. 
    */
    void AddItem(TodoItem* add);

    /*
       Delete a item from the list given the location.
       Checks first if location valid to delete item from list.
       Please note the location (area) is in human-readable form, i.e. 
       location 1 is really array index 0. After you delete the item you will 
       need to pack your array (shift all items "down" so there are no 
       empty slots between items). 
    */
    void DeleteItem(unsigned int location);

    /*
       Gets an item from the list given the location.
       Checks first if location valid to get an item from the list.
       Please note the location is in human-
       readable form, i.e. location 1 is really array index 0. This function 
       will return a pointer to the TodoItem requested. If that location 
       doesn't exist it returns NULL. 
    */
    TodoItem* GetItem(int location);

    /* 
       Returns an unsigned integer containing the 
       current size of the list (number of items present).
    */
    unsigned int GetSize() const;

    /* 
       Returns an unsigned integer containing the
       current maximum capacity of the list (number of slots).
    */
    unsigned int GetCapacity() const;

    /*
       Sorts the array by the priorities of the items. (1 is 
       highest priority, 5 is lowest). 
    */
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

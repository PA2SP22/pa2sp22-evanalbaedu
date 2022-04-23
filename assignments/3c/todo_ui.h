/*
* Name        : todo_ui.h
* Author      : Evan Alba
* Description : Header File for class TodoUI.
*/
#ifndef TODO_UI
#define TODO_UI
#include "CinReader.h"
#include "todo_item.h"
#include "todo_list.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <term.h>
class TodoUI {
 public:
  /* Create a new Todo List */
  TodoUI();

  /* Delete the dynamic TodoList and set the pointer to the List to NULL */
  ~TodoUI();

  /* Display the menu ui to the user and give them the options of:
     1. Exiting the program
     2. Create a new item
     3. Edit an Item
     4, Delete all items
     5. View a specific item
     6. View all items
  */
  void menu();

 private:
  /* Initialize CinReader */
  CinReader reader;
  TodoList* interface_;

  /* Create a new item by asking the user the
     description of the item todo, priority, and
     if the item on the list has been completed. */
  void NewItem();

  /* Ask the user what they want to edit a specific item's of the following: 
     Description, Priority, and if it was completed. 
     After that edit the part of the item they want to edit out. */
  void EditItem();

  /* Allows user to delete a specific item in the Todo List */
  void DeleteItem();

  /* Deletes all the items in the Todo List. */
  void DeleteItems();

  /* Prints out a specific item in the Todo List */
  void ViewItem();

  /* Prints out all the items in the Todo List */
  void ViewItems();
};
#endif


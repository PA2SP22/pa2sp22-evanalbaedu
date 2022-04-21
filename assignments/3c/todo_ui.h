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
  TodoUI();
  ~TodoUI();
  void menu();

 private:
  CinReader reader;
  TodoList* interface_;
  void NewItem();
  void EditItem();
  void DeleteItem();
  void DeleteItems();
  void ViewItem();
  void ViewItems();
};
#endif


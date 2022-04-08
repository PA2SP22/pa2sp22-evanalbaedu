/*
* Name        : todo_ui.cpp
* Author      : Evan Alba
* Description : CPP File for class TodoUI.
*/
#include "todo_ui.h"
 
TodoUI::TodoUI() {
  interface_ = new TodoList;
}

~TodoUI::TodoUI() {
  delete[] interface_;
  interface_ = nullptr;
}

void TodoUI::menu() {
  std::cout << "Welcome to the terminal-based Todo List.\n" << std::endl;
  while (choice != 0) {
    std::cout <<
    "Please type a number to select one of the following options below.\n\n:"
    << "0: Exit the program.\n" << "1: Create a new item.\n"
    << "2: Edit an item.\n" << "3: Delete an item.\n"
    << "4: View all items.\n" << "5. View a specific item.\n"
    << "6. Delete a item.\n" << std::endl;
    int choice = reader.readInt();
    switch (choice) {
      case 0:
        break;
      case 1:
        NewItem();
    }
  }
}

/* PRIVATE */
void NewItem() {}

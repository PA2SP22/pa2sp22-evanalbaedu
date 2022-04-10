/*
* Name        : todo_ui.cpp
* Author      : Evan Alba
* Description : CPP File for class TodoUI.
*/

#include "todo_ui.h"
 
TodoUI::TodoUI() {
  interface_ = new TodoList;
}

TodoUI::~TodoUI() {
  //delete[] interface_;
  //interface_ = nullptr;
}

void TodoUI::menu() {
  std::cout << "Welcome to the console-based Todo List.\n\nPlease type any " <<
  "integer number to start." << std::endl;
  reader.readInt();
  std::cout << std::string( 100, '\n' );
  //cout << "\033[2J\033[1;1H";
  int choice;
  while (choice != 0) {
    std::cout << std::string( 100, '\n' );
    std::cout <<
    "Please type a number to select one of the following options below:\n\n"
    << "0: Exit the program.\n" << "1: Create a new item.\n"
    << "2: Edit an item.\n" << "3: Delete an item.\n"
    << "4: Delete all items.\n" << "5. View a specific item.\n"
    << "6. View all items.\n" << std::endl;
    choice = reader.readInt();
    switch (choice) {
      case 0:
        choice = 0;
        break;
      case 1:
        NewItem();
        break;
      case 2:
        EditItem();
        break;
      case 3:
        DeleteItem();
        break;
      case 4:
        DeleteItems();
        break;
      case 5:
        ViewItem();
        break;
      case 6:
        ViewItems();
        break;
    }
  }
}

/* PRIVATE */
void TodoUI::NewItem() {
  std::cout << "Please type a description for your item: " << std::endl;
  std::string desc = reader.readString();
  std::cout << "Please type the number from 1-5 (1 = Highest) for your item's priority: " << std::endl;
  int num = reader.readInt(1, 5);
  std::cout << "Has the item been completed? Please type the word true if the item is completed. If the item is not completed, please type the word false: " << std::endl;
  bool status = reader.readBool(); 
  interface_->AddItem(new TodoItem(desc, num, status));
}

// Ask Luke EditItem how to cause no function exists in TodoList and for other functions.

void TodoUI::EditItem() {}

void TodoUI::DeleteItem() {
  std::cout << "Please type the location of the item you want to remove from the Todo List: " << std::endl;
  int num = reader.readInt();
  interface_->DeleteItem(num);
}

void TodoUI::DeleteItems() {}

void TodoUI::ViewItem() {
  //std::cout << interface->
}

void TodoUI::ViewItems() {
  std::cout << interface_->ToFile() << std::endl;
}


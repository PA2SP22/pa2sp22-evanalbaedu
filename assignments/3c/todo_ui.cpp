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
  delete interface_;
}

void TodoUI::menu() {
  std::cout << "Welcome to the console-based Todo List.\n\nPlease type any " <<
  "integer number to start." << std::endl;
  reader.readInt();
  int choice = -1;
  while (choice != 0) {
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
  std::cout << "Please type a description for your item:" << std::endl;
  std::string desc = reader.readString();
  std::cout <<
  "Please type the number from 1-5 (1 = Highest) for your item's priority:"
  << std::endl;
  int num = reader.readInt(1, 5);
  std::cout <<
  "Has the item been completed?" <<
  " Please type the word true if the item is completed." <<
  "If the item is not completed, please type the word false: "
  << std::endl;
  bool status = reader.readBool();
  interface_->AddItem(new TodoItem(desc, num, status));
}

void TodoUI::EditItem() {
  if (interface_->GetSize() == 0) {
    std::cout << "No items on the Todo List to edit.\n" << std::endl;
    return;
  }
  std::cout <<
  "Please type the number corresponding to the location" <<
  " of the item you want to edit:"
  << std::endl;
  int location = reader.readInt(1, interface_->GetSize());
  std::cout << "Please type the number corresponding on what part " <<
  "you want to edit of the item you have chosen. (1 = Description" <<
  " | 2 = Priority | 3 = Completion Status)\n\n" << std::endl;
  int option = reader.readInt(1, 3);
  if (option == 1) {
    std::cout << "Please type new description you want to set:" << std::endl;
    std::string desc = reader.readString();
    interface_->GetItem(location)->set_description(desc);
  } else if (option == 2) {
    std::cout << "Please type a new number from 1 to 5 to set the new " <<
    "priority of the item:" << std::endl;
    int num = reader.readInt(1, 5);
    interface_->GetItem(location)->set_priority(num);
  } else if (option == 3) {
    std::cout << "Has the item been completed? Please type the word " <<
    "true if the item is completed. If the item is not completed, " <<
    "please type the word false:" << std::endl;
    bool status = reader.readBool();
    interface_->GetItem(location)->set_completed(status);
  }
}

void TodoUI::DeleteItem() {
  if (interface_->GetSize() == 0) {
    std::cout << "No items on the Todo List to delete.\n" << std::endl;
    return;
  }
  std::cout << "Please type the location of the item you want to " <<
  "remove from the Todo List:" << std::endl;
  int num = reader.readInt(1, interface_->GetSize());
  interface_->DeleteItem(num);
}

void TodoUI::DeleteItems() {
  if (interface_->GetSize() == 0) {
    std::cout << "No items on the Todo List to delete.\n" << std::endl;
    return;
  }
  std::cout << "All items on the Todo List have been deleted.\n" << std::endl;
  while (interface_->GetItem(1) != nullptr) {
    interface_->DeleteItem(1);
  }
}

void TodoUI::ViewItem() {
  std::cout << "Please type the number corresponding to the location " <<
  "of the item you want to view:" << std::endl;
  int location = reader.readInt();
  std::cout << "\nDescription:\n" <<
  interface_->GetItem(location)->description()
  << "\nPriority:\n" << interface_->GetItem(location)->priority() <<
  "\nIs it completed? (1 = True | 2 = False)\n" <<
  interface_->GetItem(location)->completed() <<
  "\n\n" << std::endl;
}

void TodoUI::ViewItems() {
  if (interface_->GetSize() == 0) {
    std::cout << "No items on the Todo List to view.\n" << std::endl;
    return;
  }
  std::cout << *interface_ << std::endl;
}


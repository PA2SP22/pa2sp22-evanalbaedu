/*
 * Name        : todo_item.cpp
 * Author      : Evan Alba
 * Description : CPP File for class TodoItem.
 */

#include "todo_item.h"

/* Set the desciption of the item. */
void TodoItem::set_description(std::string info) {
  description_ = info;
}

/* Check if priority number of item given is a number of 1 - 5.
If TRUE, set priority number. 
If the priority number invalid, set to 5. */
void TodoItem::set_priority(int rank) {
  if ((rank >= 1) && (rank <= 5)) {
    priority_ = rank;
  } else {
    priority_ = 5;
  }
}

/* State if the item on the Todo List has been completed. */
void TodoItem::set_completed(bool state) {
  completed_ = state;
}

/* Returns a string containing the description, 
priority, and completed status, separated by the @ symbol. */
std::string TodoItem::ToFile() {
  return scrub(description_) + "@" + std::to_string(priority_) + "@"
  + std::to_string(completed_);
}

/* PRIVATE FUNCTION BELLOW */
/* Replace @ in the description with ` symbol. */
std::string TodoItem::scrub(std::string edit) {
  std::replace(edit.begin(), edit.end(), '@', '`');
  return edit;
}

/*
 * Name        : todo_item.cpp
 * Author      : Evan Alba
 * Description : CPP File for class TodoItem.
 */

#include "todo_item.h"

void TodoItem::set_description(std::string info) {
  description_ = info;
}

void TodoItem::set_priority(int rank) {
  if ((rank >= 1) && (rank <= 5)) {
    priority_ = rank;
  } else {
    priority_ = 5;
  }
}

void TodoItem::set_completed(bool state) {
  completed_ = state;
}

std::string TodoItem::ToFile() {
  return scrub(description_) + "@" + std::to_string(priority_) + "@"
  + std::to_string(completed_);
}

/* PRIVATE FUNCTION BELLOW */
std::string TodoItem::scrub(std::string edit) {
  std::replace(edit.begin(), edit.end(), '@', '`');
  return edit;
}

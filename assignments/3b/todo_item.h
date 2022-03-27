/*
 * Name        : todo_item.h
 * Author      : Evan Alba
 * Description : Header File for class TodoItem.
 */

#ifndef TODO_ITEM
#define TODO_ITEM
#include <algorithm>
#include <iostream>
#include <string>

class TodoItem {
 public:
    /* Create Item on the Todo list. */
    TodoItem(std::string info, int rank = 1, bool done = false) {
      description_ = info;
      priority_ = rank;
      completed_ = done;
    }
    /* Get the Description. */
    std::string description() const {
      return description_;
    }
    /* Get the Priority ranking of item on the Todo List. */
    int priority() const {
      return priority_;
    }
    /* Get back if the item on the Todo List has been completed. */
    bool completed() const {
      return completed_;
    }
    /* PUBLIC Setters Prototypes for Todo Item Class */
    void set_description(std::string text);
    void set_priority(int rank);
    void set_completed(bool state);
    std::string ToFile();

 private:
    /* PRIVATE Data for Todo Item Class */
    std::string description_;
    int priority_;
    bool completed_;
    /* PRIVATE Prototype for Scrub Function */
    std::string scrub(std::string edit);
};
#endif

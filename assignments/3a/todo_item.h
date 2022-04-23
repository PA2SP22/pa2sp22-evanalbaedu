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
    /* Set the description of the item. */
    void set_description(std::string text);

    /* Check if priority number of item given is a number of 1 - 5.
    If TRUE, set priority number. 
    If the priority number invalid, set to 5. */
    void set_priority(int rank);

    /* State if the item on the Todo List has been completed. */
    void set_completed(bool state);

    /* Returns a string containing the description, 
    priority, and completed status, separated by the @ symbol. */
    std::string ToFile();

 private:
    /* PRIVATE Data for Todo Item Class */
    std::string description_;
    int priority_;
    bool completed_;

    /* PRIVATE Prototype for Scrub Function */
    /* Replace @ in the description with ` symbol. */
    std::string scrub(std::string edit);
};
#endif

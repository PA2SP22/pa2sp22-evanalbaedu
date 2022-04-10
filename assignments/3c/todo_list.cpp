/*
 * Name        : todo_list.cpp
 * Author      : Evan Alba
 * Description : CPP File for class TodoList.
 */
#include "todo_list.h"

/*
  Add an item to the list.
  If there is room in the array add the new 
  dynamic instance to the first available spot (i.e. the current size). If
  the array is full, increase capacity by 10 and then add the item. 
*/
void TodoList::AddItem(TodoItem* add) {
  if (size_ == cap_) {
    IncreaseCap();
  }
  list_[size_] = add;
  size_ += 1;
}

/*
  Delete a item from the list given the location.
  Checks first if location valid to delete item from list.
  Please note the location (area) is in human-readable form, i.e. 
  location 1 is really array index 0. After you delete the item you will 
  need to pack your array (shift all items "down" so there are no 
  empty slots between items). 
*/
void TodoList::DeleteItem(unsigned int area) {
  if ((area > 0) && (area <= size_)) {
    delete list_[area - 1];
    list_[area - 1] = nullptr;
    size_ -= 1;
    TightenArray(area - 1);
  }
}

/*
  Gets an item from the list given the location.
  Checks first if location valid to get an item from the list.
  Please note the location is in human-
  readable form, i.e. location 1 is really array index 0. This function 
  will return a pointer to the TodoItem requested. If that location 
  doesn't exist it returns NULL. 
*/
TodoItem* TodoList::GetItem(int spot) {
  if ((size_ > 0) && (size_ <= cap_) && (list_[spot-1] != nullptr)) {
    return list_[spot - 1];
  }
  return nullptr;
}

/* 
  Returns an unsigned integer containing the 
  current size of the list (number of items present).
*/
unsigned int TodoList::GetSize() const {
  return size_;
}

/* 
  Returns an unsigned integer containing the
  current maximum capacity of the list (number of slots).
*/
unsigned int TodoList::GetCapacity() const {
  return cap_;
}

/*  
  Sorts the array by the priorities of the items. (1 is 
  highest priority, 5 is lowest). 
*/
void TodoList::Sort() {
  for (unsigned int i = 0; i <= (size_ - 1); i++) {
    int j = i;
    while ((j > 0) && (list_[j]->priority() < list_[j - 1]->priority())) {
      std::swap(list_[j], list_[j - 1]);
      j -= 1;
    }
  }
}

/*
  Returns a string containing all TodoItems in the list.
  Uses the TodoItems ToFile function to create. Each item should be
  on its own line.
*/
std::string TodoList::ToFile() {
  if ((size_ > 0) && (size_ <= cap_)) {
    std::stringstream all;
    for (unsigned int i = 0; i < size_; i++) {
        all << list_[i]->ToFile() << std::endl;
    }
    return all.str();
  }
  return "";
}

/* Outputs a numbered list of all TodoItem present in the list. */
std::ostream &operator << (std::ostream &out, const TodoList &obj) {
  for (unsigned int i = 0; i < obj.size_; i++) {
    out << obj.list_[i]->description() << obj.list_[i]->priority()
    << obj.list_[i]->completed() << std::endl;
  }
  return out;
}

/* PRIVATE */
/*
  Increases the capacity of the array by 10. Should be called by
  AddItem at the appropriate time.
*/
void TodoList::IncreaseCap() {
  cap_ += 10;
  TodoItem** extend = new TodoItem*[cap_];
  for (unsigned int i = 0; i < size_; i++) {
    extend[i] = list_[i];
  }
  for (unsigned int i = size_; i < cap_; i++) {
    extend[i] = nullptr;
  }
  delete[] list_;
  list_ = extend;
}

/* 
  Compacts the array to get rid of an empty spot in the array. 
  Should be called by DeleteItem at the appropriate time. 
*/
void TodoList::TightenArray(int start) {
  for (unsigned int i = start; i < size_; i++) {
    if (list_[i + 1] != nullptr) {
      list_[i] = list_[i + 1];
    }
  }
}

#ifndef DL_LIST
#define DL_LIST
#include <iostream>
#include <string>
#include <sstream>
#include "dl_node.h"

class DLList {
 public:
  // Initializes head and tail to NULL, size to 0. 
  DLList();

  // Calls the Clear() Function 
  ~DLList();

  // Returns the size of the list 
  int GetSize() const;

  /* Has one parameter, an integer to add to the 
  list. Creates a DLNode with the contents of the parameter and adds 
  that node to the front of the list. */
  void PushFront(int num);

  /* Has one parameter, an integer to add to the list. 
  Creates a DLNode with the contents of the parameter and adds that 
  node to the end of the list */
  void PushBack(int num);

  /* Returns the integer value of the node at the 
  beginning of the list. const function. Output "List Empty" to 
  standard error output if the list is empty and return 1. */
  int GetFront() const;

  /* Returns the integer value of the node at the end 
  of the list. const function. Output "List Empty" to standard error 
  output if the list is empty and return 0. */
  int GetBack() const;

  /* Removes the first node in the list. Output "List 
  Empty" to standard error output if the list was already empty. */
  void PopFront();

  /* Removes the last node in the list. Output "List 
  Empty" to standard error output if the list was already empty. */
  void PopBack();

  /* Has one parameter, an integer to find. If the 
  value is found, remove that node from the list. Will only remove the 
  first node that matches the value. If the value is not found, output 
  "Not Found" to standard error output. */
  void RemoveFirst(int num);

  /* Has one parameter, an integer to find. If the 
  value is found, remove that node from the list. Will remove all 
  nodes that match the value. If the value is not found, output "Not 
  Found" to standard error output. */
  void RemoveAll(int num);

  /* Has one parameter, an integer to find. If the value 
  is found, return true, else return false. */
  bool Exists(int num);

  /* Clears all nodes from the list, resets the size to 0 and 
  head and tail to NULL. */
  void Clear();

  /* Outputs the contents of the list as a 
  comma separated list ("1, 2, 3, etc") starting at the first node and 
  ending at the last node. If the list is empty return the empty string 
  and output "List Empty" to standard error output. */
  std::string ToStringForwards();

  /* Outputs the contents of the list as a 
  comma separated list ("1, 2, 3, etc") starting at the last node and 
  ending at the first node. If the list is empty return the empty string 
  and output "List Empty" to standard error output. */
  std::string ToStringBackwards();
 private:
  int size_;
  DLNode* head_;
  DLNode* tail_;
};
#endif


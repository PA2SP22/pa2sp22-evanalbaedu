/*
 * Name        : assignment_4_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit Test for class DLNode.
 *               THIS FILE SHOUD NOT BE ALTERED, UNLESS DEBUGGING IN MAIN
 */

#include "dl_list.h"
// Double Include to Test for Header Guards
#include "dl_list.h"
#include "dl_node.h"
#include "dl_node.h"

#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// For testing (DO NOT ALTER)
void Test(bool test, string more_info = "");
void UnitTest();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// For testing (DO NOT ALTER)
void UnitTest() {
  string temp = "This unit test will test some of your code:\n";
  cout << temp << string(temp.length() - 1, '-') << endl;
  cout << "There are 112 tests!" << endl;
  // Tests
  DLNode *node1 = new DLNode;

  Test(node1->GetContents() == 0, "Default Constructor & GetContents()");
  Test(node1->GetNext() == NULL, "Default Constructor & GetNext()");
  Test(node1->GetPrevious() == NULL, "Default Constructor & GetPrevious()");

  DLNode *node2 = new DLNode;
  node1->SetNext(node2);
  Test(node1->GetNext() == node2, "SetNext() & GetNext()");
  node2->SetPrevious(node1);
  Test(node2->GetPrevious() == node1, "SetPrevious() & GetPrevious()");

  node1->SetNext(NULL);
  Test(node1->GetNext() == NULL, "SetNext(NULL) & GetNext()");
  node2->SetPrevious(NULL);
  Test(node2->GetPrevious() == NULL, "SetPrevious(NULL) & GetPrevious()");

  delete node1;
  delete node2;
  Test(true, "Destructor");

  DLList list;
  std::stringstream sserr;
  std::streambuf* old_cerr = std::cerr.rdbuf(sserr.rdbuf());
  string empty = "List Empty";
  string no_value = "Not Found";
  std::stringstream full_head_list, half_head_list, full_tail_list,
                    half_tail_list;
  for (int i = 999; i > 0; i--) {
    full_head_list << i << ", ";
    if (i < 500)
      half_head_list << i << ", ";
  }
  full_head_list << 0;
  half_head_list << 0;

  for (int i = 0; i < 999; i++) {
    full_tail_list << i << ", ";
    if (i < 499)
      half_tail_list << i << ", ";
  }
  full_tail_list << 999;
  half_tail_list << 499;

  Test(list.GetSize() == 0, "Default Constructor & GetSize()");
  Test(list.ToStringForwards() == "" && sserr.str() == empty,
       "ToStringForwards()");
  sserr.str("");
  Test(list.ToStringBackwards() == "" && sserr.str() == empty,
       "ToStringBackwards()");
  sserr.str("");
  Test(list.GetFront() == 0 && sserr.str() == empty, "GetFront()");
  sserr.str("");
  Test(list.GetBack() == 0 && sserr.str() == empty, "GetBack()");
  sserr.str("");
  Test(list.Exists(10) == false, "Exists(10)");

  list.RemoveFirst(0);
  Test(sserr.str() == no_value, "RemoveFirst(0)");
  sserr.str("");
  list.RemoveAll(0);
  Test(sserr.str() == no_value, "RemoveAll(0)");
  sserr.str("");

  list.PopFront();
  Test(list.GetSize() == 0 && sserr.str() == empty, "PopFront() & GetSize()");
  sserr.str("");

  list.PopBack();
  Test(list.GetSize() == 0 && sserr.str() == empty, "PopBack() & GetSize()");
  sserr.str("");

  list.PushFront(1);
  Test(list.GetSize() == 1, "PushFront(1) & GetSize()");
  Test(list.ToStringForwards() == "1", "ToStringForwards()");
  Test(list.ToStringBackwards() == "1", "ToStringBackwards()");
  Test(list.Exists(1) == true, "Exists(1)");

  list.PopFront();
  Test(list.GetSize() == 0, "PopFront() & GetSize()");
  Test(list.ToStringForwards() == "", "ToStringForwards()");
  Test(list.ToStringBackwards() == "", "ToStringBackwards()");

  list.PushBack(5);
  Test(list.GetSize() == 1, "PushBack(5) & GetSize()");
  Test(list.ToStringForwards() == "5", "ToStringForwards()");
  Test(list.ToStringBackwards() == "5", "ToStringBackwards()");

  list.PopBack();
  Test(list.GetSize() == 0, "PopBack() & GetSize()");
  Test(list.ToStringForwards() == "", "ToStringForwards()");
  Test(list.ToStringBackwards() == "", "ToStringBackwards()");

  list.PushFront(10);
  list.PushFront(20);
  Test(list.GetSize() == 2, "PushFront(10), PushFront(20) & GetSize()");
  Test(list.ToStringForwards() == "20, 10", "ToStringForwards()");
  Test(list.ToStringBackwards() == "10, 20", "ToStringBackwards()");
  Test(list.Exists(10) == true, "Exists(10)");
  Test(list.Exists(1) == false, "Exists(1)");

  list.PopFront();
  Test(list.GetSize() == 1, "PopFront() & GetSize()");
  Test(list.ToStringForwards() == "10", "ToStringForwards()");
  Test(list.ToStringBackwards() == "10", "ToStringBackwards()");

  list.PushFront(20);
  list.PopBack();
  Test(list.GetSize() == 1, "PushFront(20), PopBack() & GetSize()");
  Test(list.ToStringForwards() == "20", "ToStringForwards()");
  Test(list.ToStringBackwards() == "20", "ToStringBackwards()");

  list.PushFront(5);
  Test(list.GetSize() == 2, "PushFront(5) & GetSize()");
  Test(list.ToStringForwards() == "5, 20", "ToStringForwards()");
  Test(list.ToStringBackwards() == "20, 5", "ToStringBackwards()");

  list.Clear();
  Test(list.GetSize() == 0, "Clear() & GetSize()");
  Test(list.ToStringForwards() == "", "ToStringForwards()");
  Test(list.ToStringBackwards() == "", "ToStringBackwards()");

  list.PushFront(10);
  list.PushFront(5);
  list.PushBack(20);
  list.PushBack(25);
  Test(list.GetSize() == 4,
       "PushFront(10), PushFront(5), PushBack(20), PushBack(25) & GetSize()");
  Test(list.ToStringForwards() == "5, 10, 20, 25", "ToStringForwards()");
  Test(list.ToStringBackwards() == "25, 20, 10, 5", "ToStringBackwards()");
  Test(list.Exists(10) == true, "Exists(10)");

  Test(list.GetFront() == 5, "GetFront()");
  Test(list.GetBack() == 25, "GetBack()");
  Test(list.GetSize() == 4, "GetSize()");
  Test(list.ToStringForwards() == "5, 10, 20, 25", "ToStringForwards()");
  Test(list.ToStringBackwards() == "25, 20, 10, 5", "ToStringBackwards()");

  list.PopFront();
  list.PopBack();
  list.PopFront();
  list.PopBack();
  Test(list.GetSize() == 0,
       "PopFront(), PopBack(), PopFront(), PopBack() & GetSize()");
  Test(list.ToStringForwards() == "", "ToStringForwards()");
  Test(list.ToStringBackwards() == "", "ToStringBackwards()");
  Test(list.Exists(10) == false, "Exists(10)");

  list.Clear();
  list.PushFront(20);
  list.PushFront(30);
  list.PushFront(40);
  list.PushFront(50);
  list.PushBack(60);
  list.PushBack(70);
  list.PushBack(80);
  list.PushBack(10);\
  Test(list.GetSize() == 8,
       "PushFront(20, 30, 40 ,50), PushBack(60, 70, 80, 10");
  Test(list.ToStringForwards() == "50, 40, 30, 20, 60, 70, 80, 10",
       "ToStringForwards()");
  Test(list.ToStringBackwards() == "10, 80, 70, 60, 20, 30, 40, 50",
       "ToStringBackwards()");

  sserr.str("");
  list.RemoveFirst(1);
  Test(sserr.str() == no_value, "RemoveFirst(1)");
  sserr.str("");
  list.RemoveFirst(50);
  Test(sserr.str() == "", "RemoveFirst(50)");
  Test(list.GetSize() == 7, "GetSize()");
  Test(list.ToStringForwards() == "40, 30, 20, 60, 70, 80, 10",
       "ToStringForwards()");
  Test(list.ToStringBackwards() == "10, 80, 70, 60, 20, 30, 40",
       "ToStringBackwards()");
  sserr.str("");
  list.RemoveFirst(10);
  Test(sserr.str() == "", "RemoveFirst(10)");
  Test(list.GetSize() == 6, "GetSize()");
  Test(list.ToStringForwards() == "40, 30, 20, 60, 70, 80",
       "ToStringForwards()");
  Test(list.ToStringBackwards() == "80, 70, 60, 20, 30, 40",
       "ToStringBackwards()");
  sserr.str("");
  list.RemoveFirst(30);
  Test(sserr.str() == "", "RemoveFirst(30)");
  Test(list.GetSize() == 5, "GetSize()");
  Test(list.ToStringForwards() == "40, 20, 60, 70, 80", "ToStringForwards()");
  Test(list.ToStringBackwards() == "80, 70, 60, 20, 40", "ToStringBackwards()");
  list.Clear();
  list.PushFront(20);
  list.PushFront(30);
  list.PushFront(40);
  list.PushFront(50);
  list.PushBack(50);
  list.PushBack(70);
  list.PushBack(80);
  list.PushBack(20);
  Test(list.GetSize() == 8,
       "PushFront(20, 30, 40 ,50), PushBack(50, 70, 80, 20");
  Test(list.ToStringForwards() == "50, 40, 30, 20, 50, 70, 80, 20",
       "ToStringForwards()");
  Test(list.ToStringBackwards() == "20, 80, 70, 50, 20, 30, 40, 50",
       "ToStringBackwards()");
  list.RemoveAll(20);
  Test(list.GetSize() == 6, "RemoveAll(20), GetSize()");
  Test(list.ToStringForwards() == "50, 40, 30, 50, 70, 80",
       "ToStringForwards()");
  Test(list.ToStringBackwards() == "80, 70, 50, 30, 40, 50",
       "ToStringBackwards()");

  sserr.str("");
  list.RemoveAll(15);
  Test(sserr.str() == no_value, "RemoveAll(15)");
  sserr.str("");

  list.RemoveAll(80);
  Test(list.GetSize() == 5, "RemoveAll(80), GetSize()");
  Test(list.ToStringForwards() == "50, 40, 30, 50, 70", "ToStringForwards()");
  Test(list.ToStringBackwards() == "70, 50, 30, 40, 50", "ToStringBackwards()");

  list.RemoveAll(50);
  Test(list.GetSize() == 3, "RemoveAll(50), GetSize()");
  Test(list.ToStringForwards() == "40, 30, 70", "ToStringForwards()");
  Test(list.ToStringBackwards() == "70, 30, 40", "ToStringBackwards()");

  list.Clear();
  for (unsigned int i = 0; i < 1000; i++)
    list.PushFront(i);
  Test(list.GetSize() == 1000, "PushFront() \"HIGH LOAD\" & GetSize()");
  Test(list.ToStringForwards() == full_head_list.str(), "ToStringForwards()");
  Test(list.ToStringBackwards() == full_tail_list.str(), "ToStringBackwards()");
  Test(list.Exists(500) == true, "Exists(500)");
  Test(list.Exists(-1) == false, "Exists(-1)");

  for (unsigned int i = 0; i < 500; i++)
    list.PopFront();
  Test(list.GetSize() == 500, "PopFront() \"HIGH LOAD / 2\" & GetSize()");
  Test(list.ToStringForwards() == half_head_list.str(), "ToStringForwards()");
  Test(list.ToStringBackwards() == half_tail_list.str(), "ToStringBackwards()");
  for (unsigned int i = 0; i < 600; i++)
    list.PopFront();
  Test(list.GetSize() == 0, "PopFront() \"HIGH LOAD / 2\" & GetSize()");
  Test(list.ToStringForwards() == "", "ToStringForwards()");
  Test(list.ToStringBackwards() == "", "ToStringBackwards()");

  for (unsigned int i = 0; i < 1000; i++)
    list.PushBack(i);
  Test(list.GetSize() == 1000, "PushBack() \"HIGH LOAD\" & GetSize()");
  Test(list.ToStringForwards() == full_tail_list.str(), "ToStringForwards()");
  Test(list.ToStringBackwards() == full_head_list.str(), "ToStringBackwards()");
  Test(list.Exists(500) == true, "Exists(500)");
  Test(list.Exists(-1) == false, "Exists(-1)");
  for (unsigned int i = 0; i < 500; i++)
    list.PopBack();
  Test(list.GetSize() == 500, "PopBack() \"HIGH LOAD / 2\" & GetSize()");
  Test(list.ToStringForwards() == half_tail_list.str(), "ToStringForwards()");
  Test(list.ToStringBackwards() == half_head_list.str(), "ToStringBackwards()");
  for (unsigned int i = 0; i < 600; i++)
    list.PopBack();
  Test(list.GetSize() == 0, "PopBack() \"HIGH LOAD / 2\" & GetSize()");
  Test(list.ToStringForwards() == "", "ToStringForwards()");
  Test(list.ToStringBackwards() == "", "ToStringBackwards()");

  // Restore cerr
  std::cerr.rdbuf(old_cerr);
  cout << string(temp.length() - 1, '-') << endl;
  cout << "Unit Test Complete!\n" << "Passed: " << ut_passed << " / "
       << ut_total << endl << "Failed: " << ut_failed << " / " << ut_total
       << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, string more_info) {
  static int test_number = 1;
  if (test) {
    cout << "PASSSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED  TEST ";
    ut_failed++;
  }
  cout << test_number << " " << more_info << "!" << endl;
  test_number++;
  ut_total++;
}

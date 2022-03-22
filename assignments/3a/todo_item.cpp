#include "todo_item.h"

// TodoItem::TodoItem(std::string info, int rank, bool done) {
//   description_ = info;
//   priority_ = rank;
//   completed_ = done;
// }

void TodoItem::set_description(std::string info) {
  description_ = info;
}

void TodoItem::set_rank(int rank) {
  if ((rank != 1) || (rank != 2) || (rank != 3) || (rank != 4) || (rank != 5)) {
    priority_ = 5;
  } else {
    priority_ = rank;
  }
}

void TodoItem::is_done(bool state) {
  completed_ = state;
}

std::string TodoItem::ToFile() {
  // std::string file;
  // std::stringstream s;
  return "test";
}

std::string TodoItem::Scrub(std::string modified) {
  return "test";
}

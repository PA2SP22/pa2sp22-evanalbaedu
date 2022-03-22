#ifndef item
#define item
#include <iostream>
#include <string>

class TodoItem {
  public:
    TodoItem(std::string info, int rank = 1, bool done = false) {
      description_ = info;
      priority_ = rank;
      completed_ = done;
    }
    
    std::string description() const {
      return description_;
    }
    
    int priority() const {
      return priority_;
    }
    
    bool completed() const {
      return completed_;
    }
 
    void set_description(std::string text);
    void set_rank(int rank);
    void is_done(bool state);
    std::string ToFile();
  
  
  private:
    std::string description_;
    int priority_;
    bool completed_;
    std::string Scrub(std::string modified);
};
#endif

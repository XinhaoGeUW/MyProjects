#ifndef _PREV_CONTROLLER_H
#define _PREV_CONTROLLER_H

#include <map>
#include <string>
#include <vector>

struct prev_controller {
  std::map<std::string, std::vector<std::string> *> inst;

  public:
  prev_controller() {
    std::string arr[20] = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown",
      "norandom", "random", "sequence", "I", "J", "L", "O", "S", "Z", "T", "restart", "rename"};
    for (int i = 0; i < 20; i++) {
      inst[arr[i]] = new std::vector<std::string>{};
    }
  }
  std::map<std::string, std::vector<std::string> *> getinst() {
    return inst;
  }
  ~prev_controller() {}
};

#endif

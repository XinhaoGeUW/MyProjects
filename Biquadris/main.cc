#include "Controller.h"
#include <string>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
  bool textOnly = false;
  int startlev = 0;
  long int randID = static_cast<long int>(time(nullptr));
  string seq1 = "";
  string seq2 = "";
  int maxLevel = 4;
  
  int total_participator = 2;
  
  for (int i = 1; i < argc; i++) {
    if (string(argv[i]) == "-text") textOnly = true;
    else if (string(argv[i]) == "-seed") {
      randID = stoi(string(argv[i+1]));
    }
    else if (string(argv[i]) == "-scriptfile1") {
      seq1 = string(argv[i+1]);
    }
    else if (string(argv[i]) == "-scriptfile2") {
      seq2 = string(argv[i+1]);
    }
    else if (string(argv[i]) == "-startlevel") {
      startlev = stoi(string(argv[i+1]));
    }
  }
  Controller ctler{randID, seq1, seq2, (total_participator > 2 && startlev == 0 ? 1 : startlev), textOnly, total_participator, maxLevel};
  try {
    ctler.mod();
  } catch (int n) {
    if (n == 2) return EXIT_FAILURE;
  }
}

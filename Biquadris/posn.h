#ifndef LAST_POSN_H
#define LAST_POSN_H
#include <cstddef>

struct Posn {
    int r;
    int c;
    Posn(int r, int c);
    bool operator==(const Posn &rhs) const;
    void setR(const int row);
    void setC(const int col);
};
#endif 

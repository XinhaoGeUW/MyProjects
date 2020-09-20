#include "textdisplay.h"
#include "subject.h"


// TextDisplay(n) will construct a 2-D vector in theDisplay where the middle four
//   char is following the initialization pattern
TextDisplay::TextDisplay(int n): theDisplay{}, gridSize{n} {
    std::vector<char> row;
    for (int c = 0; c < n; c++) {
        row.emplace_back('-');
    }
    for (int r = 0; r < n; ++r) {
        theDisplay.emplace_back(row);
    }
    theDisplay[n / 2 - 1][n / 2 - 1] = 'B';
    theDisplay[n / 2 - 1][n / 2] = 'W';
    theDisplay[n / 2][n / 2 - 1] = 'W';
    theDisplay[n / 2][n / 2] = 'B';
}


// notify(whoNotified) updates the corresponding char in theDisplay with
//   new updated Cell object
void TextDisplay::notify(Subject<Info, State> &whoNotified) {
    Info info = whoNotified.getInfo();
    char new_cell;
    if (info.colour == Colour::NoColour) {
        new_cell = '-';
    } else if (info.colour == Colour::Black) {
        new_cell = 'B';
    } else {
        new_cell = 'W';
    }
    theDisplay[info.row][info.col] = new_cell;
}

// print out the 2D-textdisplay
std::ostream & operator<<(std::ostream & out, const TextDisplay &td) {
    for (auto r : td.theDisplay) {
        for (auto c : r) {
            out << c;
        }
        out << std::endl;
    }
    return out;
}

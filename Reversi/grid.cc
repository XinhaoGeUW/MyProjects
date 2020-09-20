#include "grid.h"
#include "textdisplay.h"
#include <iostream>
using namespace std;

// dtor
Grid::~Grid() {
    delete td;
}

// see grid.h for details
void Grid::setObserver(Observer<Info, State> *ob) {
    this->ob = ob;
}

// see grid.h for details
bool Grid::isFull() const {
    bool full = false;
    for (auto line : theGrid) {
        for (auto cell : line) {
            if (cell.getInfo().colour == Colour::NoColour) {
                return full;
            }
        }
    }
    full = true;
    return full;
}

// see grid.h for details
Colour Grid::whoWon() const {
    int white = 0;
    int black = 0;
    for (auto line : theGrid) {
        for (auto cell : line) {
            if (cell.getInfo().colour == Colour::Black) {
                ++black;
            } else {
                ++white;
            }
        }
    }
    if (white > black)  return Colour::White;
    if (black > white)  return Colour::Black;
    return Colour::NoColour;
}

// set theGrid[r][c] to be cell's neighbour/observer if theGrid[r][c] is valid cell
//  in the grid, <size> is the size of the grid
void Grid::set_neighbour(Cell &cell, const int r, const int c, const int size) {
    if ((r < 0) || (c < 0) || (r >= size) || (c >= size)) { // not a valid cell
        return;
    }
    cell.attach(&(theGrid[r][c]));
}

// see grid.h for details
void Grid::init(size_t n) {
    const int grid_size = n;
    td = new TextDisplay{grid_size};
    for (int row = 0; row < grid_size; ++row) {
        std::vector<Cell> line;
        for (int col = 0; col < grid_size; ++col) {
            size_t r = row;
            size_t c = col;
            Cell cell{r, c};
            if (((r == n / 2 - 1) && (c == n / 2 - 1)) ||
                ((r == n / 2) && (c == n / 2))) {
                cell.setPiece(Colour::Black);
            }
            if (((r == n / 2 -1) && (c == n / 2)) ||
                ((r == n / 2) && (c == n / 2 - 1))) {
                cell.setPiece(Colour::White);
            }
            line.emplace_back(cell);
        }
        theGrid.emplace_back(line);

    }
    for (auto &line : theGrid) { // set observers of each cell
        for (auto &cell : line) {
            cell.attach(td);
            size_t row = cell.getInfo().row, col = cell.getInfo().col;
            set_neighbour(cell, row - 1, col - 1, grid_size);
            set_neighbour(cell, row - 1, col, grid_size);
            set_neighbour(cell, row - 1, col + 1, grid_size);
            set_neighbour(cell, row, col - 1, grid_size);
            set_neighbour(cell, row, col + 1, grid_size);
            set_neighbour(cell, row + 1, col - 1, grid_size);
            set_neighbour(cell, row + 1, col, grid_size);
            set_neighbour(cell, row + 1, col + 1, grid_size);
        }
    }
}

// see grid.h for details
void Grid::setPiece(size_t r, size_t c, Colour colour) {
    theGrid[r][c].setPiece(colour);
    td->notify(theGrid[r][c]);
    theGrid[r][c].notifyObservers();
}

// see grid.h for details
void Grid::toggle(size_t r, size_t c) {
    (theGrid[r][c]).toggle();
}

// see grid.h for details
std::ostream & operator<< (std::ostream & out, const Grid &g) {
    out << *(g.td);
    return out;
}

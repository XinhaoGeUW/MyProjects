#include "cell.h"
#include <iostream>
using namespace std;

Cell::Cell(size_t r, size_t c): r{r}, c{c}, colour{Colour::NoColour} {}
void Cell::setPiece(Colour colour){
    if (this->colour != Colour::NoColour) {
        return;
    }
    this->colour = colour;
    State s{StateType::NewPiece, colour};
    this->setState(s);
}
void Cell::toggle() {
    if (colour == Colour::NoColour) {
        return;
    } else if (colour == Colour::Black) {
        colour = Colour::White;
    } else {
        colour = Colour::Black;
    }
}
Info Cell::getInfo () const{
    return Info {r, c, colour};
}
Direction get_direction(const Subject<Info, State> &sub, const Subject<Info, State> &me) {
    size_t sub_r = sub.getInfo().row, sub_c = sub.getInfo().col;
    size_t me_r = me.getInfo().row, me_c = me.getInfo().col;
    if ((me_r == sub_r+1) && (me_c == sub_c+1)) return Direction::NW;
    if ((me_r == sub_r+1) && (me_c == sub_c)) return Direction::N;
    if ((me_r == sub_r+1) && (me_c == sub_c-1)) return Direction::NE;
    if ((me_r == sub_r) && (me_c == sub_c-1)) return Direction::E;
    if ((me_r == sub_r-1) && (me_c == sub_c-1)) return Direction::SE;
    if ((me_r == sub_r-1) && (me_c == sub_c)) return Direction::S;
    if ((me_r == sub_r-1) && (me_c == sub_c+1)) {
        return Direction::SW;
    } else {
        return Direction::W;
    }
}

void Cell::notify(Subject<Info, State> &whoFrom){
    // Keep in mind: this is the cell being notified
    if (colour == Colour::NoColour) return;
    State sub_state = whoFrom.getState();
    if (sub_state.type == StateType::NewPiece) {
        if (sub_state.colour == colour) return;
        else { // different colour
            State newS = {StateType::Relay, sub_state.colour, get_direction(*this, whoFrom)};
            setState(newS);
            notifyObservers();
        }
    } else if (sub_state.type == StateType::Reply) {
        if (get_direction(whoFrom, *this) != sub_state.direction) return;
        if (sub_state.colour != colour) {
            State newS = {StateType::Reply, sub_state.colour, sub_state.direction};
            toggle();
            setState(newS);
            notifyObservers();
        } else {
            return;
        }
    } else {
        if (get_direction(*this, whoFrom) != sub_state.direction) return;
        if (sub_state.colour != colour) {
            State newS = {StateType::Relay, sub_state.colour, sub_state.direction};
            setState(newS);
            notifyObservers();
        } else {
            State newS = {StateType::Reply, colour, sub_state.direction};
            setState(newS);
            notifyObservers();
        }
    }
}



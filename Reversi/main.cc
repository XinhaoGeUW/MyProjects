#include <iostream>
#include <string>
#include "grid.h"
#include "state.h"

using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd;
    Grid g;
    int grid_size = 0;
    bool blackturn = true;
    try {
        while (true) {
            cin >> cmd;
            if (cmd == "new") {
                int n;
                cin >> n;
                if ((n >= 4) && ((n % 2) == 0)) { // check if n is valid
                    g.init(n);
                    blackturn = true;
                    grid_size = n;
                    cout << g;
                }
            }
            else if (cmd == "play") {
                int r = 0, c = 0;
                cin >> r >> c;
                if ((r >= 0) && (c >= 0) && (r < grid_size) && (c < grid_size)) {
                    if (blackturn) {
                        g.setPiece(r, c, Colour::Black);
                        blackturn = false;
                    } else {
                        g.setPiece(r, c, Colour::White);
                        blackturn = true;
                    }
                    cout << g;
                    if (g.isFull()) {
                        Colour winner = g.whoWon();
                        if (winner == Colour::White) {
                            cout << "White wins!" << endl;
                        } else if (winner == Colour::Black) {
                            cout << "Black wins!" << endl;
                        } else {
                            cout << "Tie!" << endl;
                        }
                    }
                }
            }
        }
    }
    catch (ios::failure &) {}  // Any I/O failure quits
}

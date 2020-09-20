#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Expr.h"
using namespace std;

// You will need to write your own test harness


// Read and construct expression object. Returns a pointer to a heap-allocated
// object (caller must delete it).
istream &operator>>(istream &in, Expression *&e) {
    string s;
    vector<Expression *> stack;
    stack.clear();
    while (in >> s) {
        istringstream ss(s);
        int num;
        if (ss >> num) {
            Expression *l_expr = new Lone(num);
            stack.emplace_back(l_expr);
        }
        else if (s == "NEG" || s == "ABS") {
            Expression *u_item = stack.back();
            stack.pop_back();
            Expression *u_expr = new Unary(s, u_item);
            stack.emplace_back(u_expr);
        }
        else if (s == "+" || s == "-" || s == "*" || s == "/") {
            Expression *r_item = stack.back();
            stack.pop_back();
            Expression *l_item = stack.back();
            stack.pop_back();
            Expression *b_expr = new Binary(s, l_item, r_item);
            stack.emplace_back(b_expr);
        }
        else if (s == "done") {
            if (stack.size() != 1) {
                e = stack.front();
            } else {
                e = stack.back();
            }
            cout << e->prettyprint() << endl;
            break;
        }
        else {
            Expression *v_expr = new Var(0, s, false);
            stack.emplace_back(v_expr);
        }
    }
    return in;
}

int main () {
    string s;
    Expression *e;
    cin >> e;
    // Command interpreter
    while (cin >> s) {
        try {
            if (s == "eval") {
                cout << e->evaluate() << endl;
            }
        }
        catch (string error) {
            cout << error << endl;
        }
        if (s == "set") {
            string var;
            int val;
            cin >> var >> val;
            e->set(val, var);
        } else if (s == "unset") {
            string var;
            cin >> var;
            e->unset(var);
        } else if (s == "print") {
            cout << e->prettyprint() << endl;
        } else if (s == "copy") {
            Expression *copy = e->copy();
            cout << copy->prettyprint() <<endl;
            copy->set(1, "x");
            cout << copy->prettyprint() <<endl;
            try {
                cout << copy->evaluate() << endl;
            }
            catch (string error) {
                cout << error << endl;
            }
            delete copy;
        }
    }
    delete e;
}

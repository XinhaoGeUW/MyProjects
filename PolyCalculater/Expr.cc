#include <iostream>
#include <string>
#include <sstream>
#include "Expr.h"
using namespace std;

Expression::~Expression() {}



Lone::Lone(int val) : val{val} {}
void Lone::set(int num, string var) { return; }
void Lone::unset(std::string var) { return; }
string Lone::prettyprint() {
    stringstream ss;
    ss << val;
    return ss.str();
}
int Lone::evaluate() {
    return val;
}
Lone::~Lone() {}
Lone *Lone::copy()  {
    return new Lone(*this);
}



Var::Var(int val, std::string var, bool setted):
        val{val}, var{var}, setted{setted} {}
void Var::set(int val, std::string var) {
    if (this->var == var) {
        this->val = val;
        this->setted = true;
    }
}
void Var::unset(std::string var) {
    if (this->var == var) {
        setted = false;
    }
}
string Var::prettyprint() {
    if (setted) {
        stringstream ss;
        ss << val;
        return ss.str();
    } else {
        return var;
    }
}
int Var::evaluate() {
    if (setted) {
        return val;
    } else {
        string error = var + " " + "has no value.";
        throw error;
    }
}
Var::~Var() {}
Var *Var::copy()   {
    return new Var(*this);
}



Unary::Unary(string u_op, Expression *e):
    u_op{u_op}, u_expr{e} {}
void Unary::set(int val, std::string var) {
    u_expr->set(val, var);
}
void Unary::unset(std::string var) {
    u_expr->unset(var);
}
string Unary::prettyprint() {
    if (u_op == "ABS") {
        return ("|" + u_expr->prettyprint() + "|");
    } else {
        return ("-" + u_expr->prettyprint());
    }
}
int Unary::evaluate() {
    if (u_op == "ABS") {
        return (u_expr->evaluate() < 0 ? -u_expr->evaluate() : u_expr->evaluate());
    } else {
        return -u_expr->evaluate();
    }
}
Unary::~Unary() { delete u_expr; }
Unary *Unary::copy()  {
    Expression *u_copy = u_expr->copy();
    return new Unary(u_op, u_copy);
}



Binary::Binary(std::string op, Expression *l_expr, Expression *r_expr):
        b_op{op}, l_expr{l_expr}, r_expr{r_expr} {}
void Binary::set(int val, std::string var) {
    l_expr->set(val, var);
    r_expr->set(val, var);
}
void Binary::unset(std::string var) {
    l_expr->unset(var);
    r_expr->unset(var);
}
string Binary::prettyprint() {
    return "(" + l_expr->prettyprint() + " " + b_op + " " + r_expr->prettyprint() + ")";
}
int Binary::evaluate() {
    if (b_op == "+") {
        return l_expr->evaluate() + r_expr->evaluate();
    } else if (b_op == "-") {
        return l_expr->evaluate() - r_expr->evaluate();
    } else if (b_op == "*") {
        return l_expr->evaluate() * r_expr->evaluate();
    } else {
        return l_expr->evaluate() / r_expr->evaluate();
    }
}
Binary::~Binary() {
    delete l_expr;
    delete r_expr;
}
Binary *Binary::copy() {
    Expression *l_copy = l_expr->copy();
    Expression *r_copy = r_expr->copy();
    return new Binary(b_op, l_copy, r_copy);
}

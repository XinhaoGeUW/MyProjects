#ifndef Expression_H
#define Expression_H
#include <iostream>
#include <sstream>

class Expression{
public:
    virtual Expression *copy() = 0;
    virtual std::string prettyprint() = 0;
    virtual void set(int val, std::string var) = 0;
    virtual void unset(std::string var) = 0;
    virtual int evaluate() = 0;
    virtual ~Expression();

};

class Lone: public Expression{
    int val;
public:
    Lone(int val);
    std::string prettyprint();
    void set(int val, std::string var);
    void unset(std::string var);
    int evaluate();
    ~Lone();
    Lone *copy() override;
};

class Var: public Expression{
    int val;
    std::string var;
    bool setted;
public:
    Var(int val, std::string var, bool setted);
    std::string prettyprint();
    void set(int val, std::string var);
    void unset(std::string var);
    int evaluate();
    ~Var();
    Var *copy()  override;
};

class Unary: public Expression{
    std::string u_op;
    Expression* u_expr;
public:
    Unary(std::string u_op, Expression* u_expr);
    std::string prettyprint();
    void set(int val, std::string var);
    void unset(std::string var);
    int evaluate();
    ~Unary();
    Unary *copy() override;
};

class Binary: public Expression{
    std::string b_op;
    Expression* l_expr;
    Expression* r_expr;
public:
    Binary(std::string op, Expression* l_expr, Expression* r_expr);
    std::string prettyprint();
    void set(int val, std::string var);
    void unset(std::string var);
    int evaluate();
    ~Binary();
    Binary *copy() override;
};

#endif




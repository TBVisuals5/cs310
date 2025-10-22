#ifndef STACK_H
#define STACK_H

#include <iostream>
const int MAX_STACK = 100;
typedef int ItemType;

class Stack {
public:
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void push(ItemType item) = 0;
    virtual ItemType pop() = 0;
    virtual ItemType peek() = 0;
    virtual void makeEmpty() = 0;
    virtual ~Stack() {}
};

#endif

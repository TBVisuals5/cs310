#include "Stack.h"

class ArrayStack : public Stack {
private:
    ItemType* stackArray;
    int top;

public:
    ArrayStack() {
        stackArray = new ItemType[MAX_STACK];
        top = -1;
    }

    ~ArrayStack() {
        delete[] stackArray;
    }

    bool isEmpty() override {
        return top == -1;
    }

    bool isFull() override {
        return top == MAX_STACK - 1;
    }

    void push(ItemType item) override {
        if (!isFull()) {
            stackArray[++top] = item;
        }
    }

    ItemType pop() override {
        if (!isEmpty()) {
            return stackArray[top--];
        }
        return -999;
    }

    ItemType peek() override {
        return isEmpty() ? -999 : stackArray[top];
    }

    void makeEmpty() override {
        top = -1;
    }
};

// LinkedStack.cpp
#include "Stack.h"

struct Node {
    ItemType data;
    Node* next;
    Node(ItemType item) : data(item), next(nullptr) {}
};

class LinkedStack : public Stack {
private:
    Node* top;

public:
    LinkedStack() : top(nullptr) {}

    ~LinkedStack() {
        makeEmpty();
    }

    bool isEmpty() override {
        return top == nullptr;
    }

    bool isFull() override {
        return false;
    }

    void push(ItemType item) override {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
    }

    ItemType pop() override {
        if (top) {
            ItemType item = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return item;
        }
        return -999;
    }

    ItemType peek() override {
        return top ? top->data : -999;
    }

    void makeEmpty() override {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

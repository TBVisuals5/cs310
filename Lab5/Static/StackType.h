#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "ItemType.h"

const int MAX_ITEMS = 500;

class FullStack {};
class EmptyStack {};

class StackType {
public:
    StackType();
    StackType(const StackType& other);
    StackType& operator=(const StackType& other);

    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType item);
    void Pop();
    void Pop(ItemType& item);
    ItemType Top();

private:
    int top;
    ItemType items[MAX_ITEMS];
};

#endif

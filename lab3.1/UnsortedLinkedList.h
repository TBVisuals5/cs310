#ifndef UNSORTEDLINKEDLIST_H
#define UNSORTEDLINKEDLIST_H

#include <iostream>

template <typename T>
class UnsortedLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    Node* current;

public:
    UnsortedLinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}

    ~UnsortedLinkedList() {
        clear();
    }

    void add(const T& item) {
        Node* newNode = new Node(item);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(const T& item) {
        Node* prev = nullptr;
        Node* temp = head;
        while (temp) {
            if (temp->data == item) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if (temp == tail) {
                    tail = prev;
                }
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    void reset() {
        current = head;
    }

    T* getNext() {
        if (current) {
            T* dataPtr = &current->data;
            current = current->next;
            return dataPtr;
        }
        return nullptr;
    }

    void clear() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = current = nullptr;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

#endif

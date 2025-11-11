#include <iostream>
#include <string>
#include <stdexcept>

// Assuming these classes are already implemented:
#include "CircularLinkedStack.h"
#include "CircularLinkedQueue.h"
#include "CircularLinkedList.h"

template <typename T>
class TextEditorBuffer {
private:
    CircularLinkedStack<T> buffer;
    CircularLinkedQueue<T> redoQueue;
    CircularLinkedList<std::string> history;

public:
    void type(T item) {
        buffer.push(item);
        history.insertRear("Typed: " + toString(item));
    }

    void undo() {
        if (buffer.isEmpty()) {
            std::cout << "Nothing to undo.\n";
            return;
        }
        T item = buffer.pop();
        redoQueue.enqueue(item);
        history.insertRear("Undo: " + toString(item));
    }

    void redo() {
        if (redoQueue.isEmpty()) {
            std::cout << "Nothing to redo.\n";
            return;
        }
        T item = redoQueue.dequeue();
        buffer.push(item);
        history.insertRear("Redo: " + toString(item));
    }

    void displayBuffer() const {
        std::cout << "Buffer: ";
        buffer.display(); // Assumes display prints from top to bottom
    }

    void displayHistory() const {
        std::cout << "History:\n";
        history.display();
    }

private:
    std::string toString(const T& item) const {
        if constexpr (std::is_same<T, char>::value)
            return std::string(1, item);
        else
            return item;
    }
};

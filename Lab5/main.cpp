#include <fstream>
#include "StackType.h"
#include "ItemType.h"

int main() {
    StackType stack;
    std::ifstream inFile("StackType.in");
    std::ofstream outFile("StackType.out");

    ItemType item;

    // Load stack from file
    while (inFile >> item) {
        stack.Push(item);
    }

    // 1. Second element (remove top two)
    ItemType secondElement;
    stack.Pop(); // discard top
    stack.Pop(secondElement);
    outFile << "Second element: " << secondElement << std::endl;

    // Reload stack for next operations
    inFile.clear();
    inFile.seekg(0);
    while (inFile >> item) {
        stack.Push(item);
    }

    // 2. Bottom element (leave stack empty)
    ItemType bottom;
    while (!stack.IsEmpty()) {
        stack.Pop(bottom);
    }
    outFile << "Bottom element (emptied): " << bottom << std::endl;

    // Reload stack again
    inFile.clear();
    inFile.seekg(0);
    while (inFile >> item) {
        stack.Push(item);
    }

    // 3. Bottom element (leave stack unchanged)
    StackType tempStack = stack;
    while (!tempStack.IsEmpty()) {
        tempStack.Pop(bottom);
    }
    outFile << "Bottom element (unchanged): " << bottom << std::endl;

    // 4. Copy of stack
    StackType copyStack = stack;
    outFile << "Copied stack contents: ";
    while (!copyStack.IsEmpty()) {
        copyStack.Pop(item);
        outFile << item << " ";
    }
    outFile << std::endl;

    inFile.close();
    outFile.close();
    return 0;
}

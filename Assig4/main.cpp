#include <iostream>
#include "Stack.h"
#include "ArrayStack.cpp" // or "LinkedStack.cpp"
#include "postfix.h"      // if using separate postfix file

using namespace std;

int main() {
    Stack* stack = new ArrayStack(); // or new LinkedStack()

    // Basic stack tests
    for (int i = 1; i <= 10; ++i) stack->push(i);
    for (int i = 0; i < 5; ++i) cout << "Pop: " << stack->pop() << endl;

    // Postfix evaluation tests
    cout << "Expr '23+': " << evaluatePostfix("23+", *stack) << endl;
    cout << "Expr '231*+4-': " << evaluatePostfix("231*+4-", *stack) << endl;
    cout << "Expr '2++': " << evaluatePostfix("2++", *stack) << endl;

    delete stack;
    return 0;
}

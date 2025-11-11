int main() {
    // Stack Test
    Stack<char> stack;
    try {
        stack.push('A');
        stack.push('B');
        stack.push('C');
        stack.push('D');
        stack.push('E');
        std::cout << "Stack top: " << stack.top() << "\n";
        stack.pop();
        stack.pop();
        stack.pop();
        std::cout << "Stack top after pops: " << stack.top() << "\n";
        std::cout << "Stack size: " << stack.size() << "\n";
        stack.pop();
        stack.pop();
        stack.pop(); // Should throw
    } catch (const std::exception& e) {
        std::cout << "Stack Exception: " << e.what() << "\n";
    }

    // Queue Test
    Queue<int> queue;
    try {
        for (int i = 1; i <= 5; ++i) queue.enqueue(i);
        std::cout << "Queue front: " << queue.front() << "\n";
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        std::cout << "Queue front after dequeues: " << queue.front() << "\n";
        std::cout << "Queue size: " << queue.size() << "\n";
        queue.dequeue();
        queue.dequeue();
        queue.dequeue(); // Should throw
    } catch (const std::exception& e) {
        std::cout << "Queue Exception: " << e.what() << "\n";
    }

    // Circular Linked List Test
    CircularLinkedList<std::string> list;
    try {
        list.insertFront("one");
        list.insertRear("two");
        list.insertFront("zero");
        list.insertRear("three");
        list.insertRear("four");
        list.display();
        list.deleteFront();
        list.deleteRear();
        list.display();
        list.deleteFront();
        list.deleteFront();
        list.deleteFront();
        list.deleteFront(); // Should throw
    } catch (const std::exception& e) {
        std::cout << "List Exception: " << e.what() << "\n";
    }

    // TextEditorBuffer Test (char)
    TextEditorBuffer<char> editor;
    std::string input = "hello world";
    for (char ch : input) editor.type(ch);
    editor.displayBuffer();
    editor.undo();
    editor.undo();
    editor.undo();
    editor.displayBuffer();
    editor.redo();
    editor.redo();
    editor.displayBuffer();
    editor.displayHistory();

    // TextEditorBuffer Test (string)
    TextEditorBuffer<std::string> wordEditor;
    wordEditor.type("Hello");
    wordEditor.type("World");
    wordEditor.type("!");
    wordEditor.displayBuffer();
    wordEditor.undo();
    wordEditor.displayBuffer();
    wordEditor.redo();
    wordEditor.displayBuffer();
    wordEditor.displayHistory();

    return 0;
}

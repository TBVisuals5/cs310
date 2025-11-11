template <typename T>
class CircularLinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* topNode;
    int count;

public:
    CircularLinkedStack() : topNode(nullptr), count(0) {}

    void push(T item) {
        Node* newNode = new Node(item);
        if (!topNode) {
            newNode->next = newNode;
        } else {
            newNode->next = topNode->next;
            topNode->next = newNode;
        }
        topNode = newNode;
        ++count;
    }

    T pop() {
        if (isEmpty()) throw std::underflow_error("Stack underflow");
        Node* temp = topNode->next;
        T val = temp->data;
        if (topNode == temp) {
            topNode = nullptr;
        } else {
            topNode->next = temp->next;
        }
        delete temp;
        --count;
        return val;
    }

    T top() const {
        if (isEmpty()) throw std::underflow_error("Stack is empty");
        return topNode->next->data;
    }

    bool isEmpty() const { return count == 0; }
    int size() const { return count; }

    ~CircularLinkedStack() {
        while (!isEmpty()) pop();
    }
};

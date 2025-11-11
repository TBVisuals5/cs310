template <typename T>
class CircularLinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* rear;
    int count;

public:
    CircularLinkedQueue() : rear(nullptr), count(0) {}

    void enqueue(T item) {
        Node* newNode = new Node(item);
        if (!rear) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        ++count;
    }

    T dequeue() {
        if (isEmpty()) throw std::underflow_error("Queue underflow");
        Node* front = rear->next;
        T val = front->data;
        if (rear == front) {
            rear = nullptr;
        } else {
            rear->next = front->next;
        }
        delete front;
        --count;
        return val;
    }

    T front() const {
        if (isEmpty()) throw std::underflow_error("Queue is empty");
        return rear->next->data;
    }

    bool isEmpty() const { return count == 0; }
    int size() const { return count; }

    ~CircularLinkedQueue() {
        while (!isEmpty()) dequeue();
    }
};

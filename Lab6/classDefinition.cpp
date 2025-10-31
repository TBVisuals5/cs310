class Queue {
private:
    static const int MAX_SIZE = 100;
    char data[MAX_SIZE];
    int front;
    int rear;
    int length;

public:
    Queue();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(char item);
    char dequeue();
    int size() const;
    void display() const;
};

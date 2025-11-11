template <typename T>
class Queue {
private:
    T* arr;
    int capacity;
    int frontIndex, rearIndex;
    int count;

public:
    Queue() : capacity(100), frontIndex(0), rearIndex(-1), count(0) {
        arr = new T[capacity];
    }

    void enqueue(T item) {
        if (isFull()) throw std::overflow_error("Queue overflow");
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = item;
        ++count;
    }

    T dequeue() {
        if (isEmpty()) throw std::underflow_error("Queue underflow");
        T val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        --count;
        return val;
    }

    T front() const {
        if (isEmpty()) throw std::underflow_error("Queue is empty");
        return arr[frontIndex];
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    int size() const { return count; }

    ~Queue() { delete[] arr; }
};

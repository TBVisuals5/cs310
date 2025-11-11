template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

    void resize() {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i <= topIndex; ++i)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    Stack() : capacity(100), topIndex(-1) {
        arr = new T[capacity];
    }

    void push(T item) {
        if (isFull()) resize();
        arr[++topIndex] = item;
    }

    T pop() {
        if (isEmpty()) throw std::underflow_error("Stack underflow");
        return arr[topIndex--];
    }

    T top() const {
        if (isEmpty()) throw std::underflow_error("Stack is empty");
        return arr[topIndex];
    }

    bool isEmpty() const { return topIndex == -1; }
    bool isFull() const { return topIndex == capacity - 1; }
    int size() const { return topIndex + 1; }

    ~Stack() { delete[] arr; }
};




template <typename T, int Capacity>
class ArrayStack {

private:
    T data[Capacity];
    int topIndex = -1

public:
    void push(T value) {
        if (topIndex >=Capacity - 1) {
            throw std::overflow_error(s:"Stack is full");
        }
        data[++topIndex] = value
    }

    T pop() {
        if (topIndex < 0) {
            throw std::underflow_error(s:"Stack is Empty");
        }
        return data[topIndex--];
    }
}
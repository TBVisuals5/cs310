Queue::Queue() {
    front = 0;
    rear = 0;
    length = 0;
}

bool Queue::isEmpty() const {
    return length == 0;
}

bool Queue::isFull() const {
    return length == MAX_SIZE;
}

void Queue::enqueue(char item) {
    if (!isFull()) {
        data[rear] = item;
        rear = (rear + 1) % MAX_SIZE;
        length++;
    }
}

char Queue::dequeue() {
    if (!isEmpty()) {
        char item = data[front];
        front = (front + 1) % MAX_SIZE;
        length--;
        return item;
    }
    return '\0'; // Indicates empty
}

int Queue::size() const {
    return length;
}

void Queue::display() const {
    std::cout << "Queue: ";
    for (int i = 0; i < length; ++i) {
        std::cout << data[(front + i) % MAX_SIZE] << " ";
    }
    std::cout << std::endl;
}

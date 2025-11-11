template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    int count;

public:
    CircularLinkedList() : head(nullptr), count(0) {}

    void insertFront(T item) {
        Node* newNode = new Node(item);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* tail = head;
            while (tail->next != head) tail = tail->next;
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
        ++count;
    }

    void insertRear(T item) {
        Node* newNode = new Node(item);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* tail = head;
            while (tail->next != head) tail = tail->next;
            tail->next = newNode;
            newNode->next = head;
        }
        ++count;
    }

    void deleteFront() {
        if (isEmpty()) throw std::underflow_error("List is empty");
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* tail = head;
            while (tail->next != head) tail = tail->next;
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        --count;
    }

    void deleteRear() {
        if (isEmpty()) throw std::underflow_error("List is empty");
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* prev = nullptr;
            Node* curr = head;
            while (curr->next != head) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = head;
            delete curr;
        }
        --count;
    }

    void display() const {
        if (isEmpty()) return;
        Node* curr = head;
        do {
            std::cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        std::cout << std::endl;
    }

    bool isEmpty() const { return count == 0; }
    int size() const { return count; }

    ~CircularLinkedList() {
        while (!isEmpty()) deleteFront();
    }
};

#ifndef HEAPMASTER_H
#define HEAPMASTER_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <type_traits>

// ====================== TASK STRUCT (for challenges 6–10) ======================
struct Task {
    int id;
    int priority;      // higher number = higher priority
    int arrivalTime;
    int burstTime;
    int deadline;

    void print() const {
        std::cout << "Task#" << id 
                  << " pri=" << priority
                  << " arrive=" << arrivalTime
                  << " burst=" << burstTime
                  << " dead=" << deadline;
    }
};

// Example comparators for Task (use in challenges 6–7)
struct TaskPriorityCmp {
    // Return true when a is "worse than" b for heap ordering
    // Larger priority = better (max-heap behavior)
    bool operator()(const Task& a, const Task& b) const {
        return a.priority < b.priority;
    }
};

struct TaskDeadlineCmp {
    // Earlier deadline = better (min-heap behavior)
    bool operator()(const Task& a, const Task& b) const {
        return a.deadline > b.deadline;
    }
};

// ============================= HEAP MASTER CLASS =============================
template<typename T, int MAX_SIZE = 1000005, typename Compare = std::less<T>>
class HeapMaster {
private:
    T data[MAX_SIZE];
    int sz;                    // current size
    Compare comp;              // comparator (generic: comp(parent, child) means parent worse than child)

    int parent(int i) const { return (i - 1) / 2; }
    int left(int i) const   { return 2 * i + 1; }
    int right(int i) const  { return 2 * i + 2; }

    void heapifyUp(int i);
    void heapifyDown(int i);

    // internal utility for pretty printing
    int height() const {
        int h = 0, cnt = sz;
        while (cnt > 0) { cnt >>= 1; h++; }
        return h;
    }

public:
    HeapMaster() : sz(0), comp(Compare()) {}

    bool empty() const { return sz == 0; }
    int size() const   { return sz; }
    const T& top() const;

    void push(const T& val);
    void pop();
    void clear() { sz = 0; }

    // Challenge 8 – decrease/increase key (index provided by caller)
    // decreaseKey: newVal must improve priority relative to old
    bool decreaseKey(int index, const T& newVal);
    // increaseKey: newVal must worsen priority relative to old
    bool increaseKey(int index, const T& newVal);

    // Challenge 9 – build heap bottom-up in O(n)
    void buildHeap(T arr[], int n);

    // Challenge 4 – in-place heap sort using only heapifyDown style operations
    // Provide both ascending and descending (param 'ascending')
    static void heapSort(T arr[], int n, bool ascending = true);

    void printHeap() const;        // pretty print as tree
    void printArray() const;       // raw array view

    // Expose raw access for testing (read-only)
    const T* raw() const { return data; }
};

#include "HeapMaster.hpp"   // implementation in separate file
#endif

#include "HeapMaster.h"
#include <functional>
#include <random>

int main() {
    std::cout << "HeapMaster Lab – Complete the challenges!\n\n";

    // Challenge 1–3: basic integers, test max-heap (std::less) and min-heap (std::greater)
    {
        std::cout << "Test: Max-heap integers\n";
        HeapMaster<int, 64, std::less<int>> maxH;
        int vals[] = {12, 3, 25, 7, 19, 30, 2, 18};
        for (int v : vals) maxH.push(v);
        maxH.printArray();
        std::cout << "Top (max): " << maxH.top() << "\n";
        maxH.printHeap();
        std::cout << "\n";
    }
    {
        std::cout << "Test: Min-heap integers\n";
        HeapMaster<int, 64, std::greater<int>> minH;
        int vals[] = {12, 3, 25, 7, 19, 30, 2, 18};
        for (int v : vals) minH.push(v);
        minH.printArray();
        std::cout << "Top (min): " << minH.top() << "\n";
        minH.printHeap();
        std::cout << "\n";
    }

    // Challenge 8: decreaseKey/increaseKey correctness
    {
        std::cout << "Test: decreaseKey/increaseKey on max-heap\n";
        HeapMaster<int, 64, std::less<int>> h;
        for (int v : {10, 20, 5, 7, 15}) h.push(v); // top=20
        h.printArray();
        // Make an element better (increase value in max-heap)
        // Suppose index 2 currently holds 5 → make it 50 (better)
        bool ok1 = h.decreaseKey(2, 50);
        std::cout << "decreaseKey(2,50): " << (ok1 ? "ok" : "fail") 
                  << ", top=" << h.top() << "\n";
        // Make top worse (lower)
        bool ok2 = h.increaseKey(0, 3);
        std::cout << "increaseKey(0,3): " << (ok2 ? "ok" : "fail") 
                  << ", new top=" << h.top() << "\n";
        h.printHeap();
        std::cout << "\n";
    }
    {
        std::cout << "Test: decreaseKey/increaseKey on min-heap\n";
        HeapMaster<int, 64, std::greater<int>> h;
        for (int v : {10, 20, 5, 7, 15}) h.push(v); // top=5
        h.printArray();
        // Make an element better (decrease value in min-heap)
        // Suppose index 1 currently holds 20 → make it 1 (better)
        bool ok1 = h.decreaseKey(1, 1);
        std::cout << "decreaseKey(1,1): " << (ok1 ? "ok" : "fail")
                  << ", top=" << h.top() << "\n";
        // Make top worse (larger)
        bool ok2 = h.increaseKey(0, 100);
        std::cout << "increaseKey(0,100): " << (ok2 ? "ok" : "fail")
                  << ", new top=" << h.top() << "\n";
        h.printHeap();
        std::cout << "\n";
    }

    // Challenge 9: buildHeap vs n×push (basic functional test)
    {
        std::cout << "Test: buildHeap bottom-up\n";
        int arr[] = {9, 1, 7, 3, 5, 2, 8, 4, 6};
        HeapMaster<int, 64, std::less<int>> h; // max-heap
        h.buildHeap(arr, 9);
        h.printArray();
        std::cout << "Top: " << h.top() << "\n";
        h.printHeap();
        std::cout << "\n";
    }

    // Challenge 4: heapSort in-place
    {
        std::cout << "Test: heapSort ascending\n";
        int arr[] = {9, 1, 7, 3, 5, 2, 8, 4, 6};
        // Use std::greater<T> comparator to naturally get ascending
        HeapMaster<int, 64, std::greater<int>>::heapSort(arr, 9, true);
        std::cout << "[";
        for (int i = 0; i < 9; ++i) { if (i) std::cout << ", "; std::cout << arr[i]; }
        std::cout << "]\n\n";

        std::cout << "Test: heapSort descending\n";
        int arr2[] = {9, 1, 7, 3, 5, 2, 8, 4, 6};
        // Use std::less<T> comparator to naturally get descending
        HeapMaster<int, 64, std::less<int>>::heapSort(arr2, 9, false);
        std::cout << "[";
        for (int i = 0; i < 9; ++i) { if (i) std::cout << ", "; std::cout << arr2[i]; }
        std::cout << "]\n\n";
    }

    // Challenge 6–7: Task by priority and deadline
    {
        std::cout << "Test: Task Priority (max-heap by priority)\n";
        HeapMaster<Task, 64, TaskPriorityCmp> hp;
        hp.push({1, 5, 0, 10, 50});
        hp.push({2, 9, 1, 3, 20});
        hp.push({3, 7, 2, 6, 40});
        hp.printArray();
        std::cout << "Top (highest priority): "; hp.top().print(); std::cout << "\n";
        hp.printHeap();
        std::cout << "\n";
    }
    {
        std::cout << "Test: Task Deadline (min-heap by earliest deadline)\n";
        HeapMaster<Task, 64, TaskDeadlineCmp> hd;
        hd.push({1, 5, 0, 10, 50});
        hd.push({2, 9, 1, 3, 20});
        hd.push({3, 7, 2, 6, 40});
        hd.printArray();
        std::cout << "Top (earliest deadline): "; hd.top().print(); std::cout << "\n";
        hd.printHeap();
        std::cout << "\n";
    }

    std::cout << "All tests executed.\n";
    return 0;
}

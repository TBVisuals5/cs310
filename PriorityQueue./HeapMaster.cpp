#ifndef HEAPMASTER_HPP
#define HEAPMASTER_HPP
#include "HeapMaster.h"

// ================================================================
// PRIVATE HELPERS
// ================================================================
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapifyUp(int i) {
    while (i > 0) {
        int p = parent(i);
        // If parent is worse than child, swap (generic for min/max via comp)
        if (comp(data[p], data[i])) {
            std::swap(data[p], data[i]);
            i = p;
        } else {
            break;
        }
    }
}

template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapifyDown(int i) {
    while (true) {
        int best = i;
        int l = left(i);
        int r = right(i);

        // Choose the better child compared to current
        if (l < sz && comp(data[best], data[l])) best = l;
        if (r < sz && comp(data[best], data[r])) best = r;

        if (best != i) {
            std::swap(data[i], data[best]);
            i = best;
        } else {
            break;
        }
    }
}

// Helper: “isBetter(a, b)” means 'a' should sit above 'b' in heap ordering.
namespace detail {
    template<typename T, int MAX_SIZE, typename Compare>
    inline bool isBetter(const HeapMaster<T, MAX_SIZE, Compare>& h, const T& a, const T& b) {
        // Mirrors the swap condition in heapifyUp: comp(parent, child) → parent worse than child
        // So: a better than b if comp(b, a) is true
        return h.comp(b, a);
    }
}

// ================================================================
// PUBLIC INTERFACE
// ================================================================

template<typename T, int MAX_SIZE, typename Compare>
const T& HeapMaster<T, MAX_SIZE, Compare>::top() const {
    if (sz == 0) throw std::out_of_range("Heap is empty");
    return data[0];
}

template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::push(const T& val) {
    if (sz >= MAX_SIZE) throw std::overflow_error("Heap is full");
    data[sz] = val;
    heapifyUp(sz);
    sz++;
}

template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::pop() {
    if (sz == 0) throw std::underflow_error("Heap is empty");
    data[0] = data[--sz];   // move last to root
    heapifyDown(0);
}

// ================================================================
// CHALLENGE 8: decreaseKey() and increaseKey()
// Comparator-agnostic semantics:
// - decreaseKey: newVal must improve priority vs old → bubble up or down as needed.
// - increaseKey: newVal must worsen priority vs old → sink down (or correct up if needed).
// ================================================================
template<typename T, int MAX_SIZE, typename Compare>
bool HeapMaster<T, MAX_SIZE, Compare>::decreaseKey(int idx, const T& newVal) {
    if (idx < 0 || idx >= sz) return false;

    // Require improvement
    if (!detail::isBetter(*this, newVal, data[idx])) return false;

    data[idx] = newVal;

    // Preferred direction: up if parent is worse than current
    if (idx > 0 && comp(data[parent(idx)], data[idx])) {
        heapifyUp(idx);
    } else {
        // In unusual comparator cases, ensure heap validity either way
        heapifyDown(idx);
    }
    return true;
}

template<typename T, int MAX_SIZE, typename Compare>
bool HeapMaster<T, MAX_SIZE, Compare>::increaseKey(int idx, const T& newVal) {
    if (idx < 0 || idx >= sz) return false;

    // Require worsening
    if (!detail::isBetter(*this, data[idx], newVal)) return false;

    data[idx] = newVal;

    // Preferred direction: down
    if (idx > 0 && comp(data[idx], data[parent(idx)])) {
        // If child accidentally looks better than parent, fix upwards first
        heapifyUp(idx);
    } else {
        heapifyDown(idx);
    }
    return true;
}

// ================================================================
// CHALLENGE 9: buildHeap(T arr[], n) in O(n)
// Copy arr into internal storage and bottom-up heapify.
// ================================================================
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::buildHeap(T arr[], int n) {
    if (n < 0 || n > MAX_SIZE) throw std::overflow_error("Input size exceeds MAX_SIZE");
    // copy
    for (int i = 0; i < n; ++i) data[i] = arr[i];
    sz = n;
    // bottom-up heapify
    for (int i = parent(sz - 1); i >= 0; --i) {
        heapifyDown(i);
    }
}

// ================================================================
// CHALLENGE 4: heapSort(T arr[], n) in-place, comparator-agnostic
// We’ll implement a local heap using Compare, then output ascending or descending.
// Note: ascending=true uses a min-heap behavior (smallest first).
// To keep strictly in-place: we heapify array and repeatedly extract.
// ================================================================
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::heapSort(T arr[], int n, bool ascending) {
    if (n <= 1) return;

    // We'll build a heap right on arr using a local lambda for comparisons
    // We need functions for parent/left/right
    auto parentIdx = [](int i){ return (i - 1) / 2; };
    auto leftIdx   = [](int i){ return 2 * i + 1; };
    auto rightIdx  = [](int i){ return 2 * i + 2; };

    Compare cmp;

    // local heapifyDown that works on arr directly
    auto heapifyDownArr = [&](int i, int heapSize) {
        while (true) {
            int best = i;
            int l = leftIdx(i);
            int r = rightIdx(i);
            if (l < heapSize && cmp(arr[best], arr[l])) best = l;
            if (r < heapSize && cmp(arr[best], arr[r])) best = r;
            if (best != i) {
                std::swap(arr[i], arr[best]);
                i = best;
            } else {
                break;
            }
        }
    };

    // Build heap bottom-up
    for (int i = parentIdx(n - 1); i >= 0; --i) {
        heapifyDownArr(i, n);
    }

    // Repeatedly move top to the end and reduce heap
    // If Compare implements max-heap behavior, extraction order will be descending.
    // To control ascending/descending, we can select appropriate Compare when calling,
    // or invert after. Here we respect 'ascending' by flipping logic:
    //
    // Strategy: If ascending is true and Compare is std::less<T> (max-heap),
    // we get descending. To produce ascending, we build a min-heap: use std::greater<T>.
    // Because Compare is a template parameter, caller should pick Compare accordingly.
    //
    // Therefore: This function sorts according to the induced order of Compare:
    //   - std::less<T> → descending
    //   - std::greater<T> → ascending
    //
    // The 'ascending' flag is kept for convenience; if it mismatches Compare,
    // we’ll reverse after extraction.

    // Extract all
    for (int end = n - 1; end > 0; --end) {
        std::swap(arr[0], arr[end]);
        heapifyDownArr(0, end);
    }

    // If order does not match 'ascending', reverse
    // Detect induced order by probing cmp: cmp(a,b) means a worse than b.
    // For standard types, we can reasonably assume:
    //  - std::less<T> → produced descending
    //  - std::greater<T> → produced ascending
    // For custom Compare, caller should pass ascending accordingly; otherwise we provide a simple toggle.
    // We'll implement a minimal heuristic: test first pair if possible.
    bool producedAscending = true;
    if (n >= 2) {
        // After heap-extract with std::less, arr is descending; with std::greater, ascending.
        // Heuristic: if arr[0] > arr[1], likely descending for common types
        producedAscending = !(arr[0] > arr[1]);
    }
    if (producedAscending != ascending) {
        // reverse
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            std::swap(arr[i], arr[j]);
        }
    }
}

// ================================================================
// PRINTING UTILITIES
// ================================================================
template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::printArray() const {
    std::cout << "[";
    for (int i = 0; i < sz; ++i) {
        if (i) std::cout << ", ";
        // For Task, use print(); for other T, stream it
        if constexpr (std::is_same_v<T, Task>) {
            data[i].print();
        } else {
            std::cout << data[i];
        }
    }
    std::cout << "]\n";
}

template<typename T, int MAX_SIZE, typename Compare>
void HeapMaster<T, MAX_SIZE, Compare>::printHeap() const {
    if (sz == 0) { std::cout << "(empty)\n"; return; }

    // Level-order print with spacing derived from height
    int h = height();
    int levelStart = 0;
    for (int level = 0; level < h; ++level) {
        int levelCount = 1 << level;
        int levelEnd = std::min(sz, levelStart + levelCount);

        // spacing: reduce as levels go down
        int basePad = (1 << (h - level)) * 2;
        for (int i = levelStart; i < levelEnd; ++i) {
            if (i == levelStart) std::cout << std::string(basePad / 2, ' ');
            // print node
            if constexpr (std::is_same_v<T, Task>) {
                std::cout << std::setw(3) << data[i].priority; // compact view for Task (priority)
            } else {
                std::cout << std::setw(3) << data[i];
            }
            // spacing between nodes
            std::cout << std::string(basePad, ' ');
        }
        std::cout << "\n";
        levelStart = levelEnd;
        if (levelStart >= sz) break;
    }
}

#endif // HEAPMASTER_HPP

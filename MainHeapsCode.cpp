#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>  // For setting spacing to visualize tree

using namespace std;

// Helper function to display a heap in a tree-like structure
void displayHeapTree(const vector<int>& heap) {
    int level = 0;
    int nextLevel = 1;
    int width = 4;  // Controls the spacing between elements

    // Loop through the heap and print each level
    for (size_t i = 0; i < heap.size(); ++i) {
        if (i == nextLevel - 1) {
            cout << endl;
            nextLevel = nextLevel * 2 + 1;
        }
        cout << setw(4) << heap[i];
    }
    cout << endl;
}

// Task 1: Insert elements into a Max-Heap
void task1InsertMaxHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    push_heap(heap.begin(), heap.end());
    cout << "\033[1;32mAdding task with priority \033[1;33m" << value << "\033[1;32m to the Max-Heap!\033[0m\n";
    cout << "\033[1;34mCurrent Max-Heap (Tree View):\033[0m\n";
    displayHeapTree(heap);
}

// Task 2: Remove the root of a Max-Heap
void task2DeleteRoot(vector<int>& heap) {
    while (!heap.empty()) {
        cout << "\033[1;31mRemoving root task with highest priority: \033[1;33m" << heap.front() << "\033[1;31m!\033[0m\n";
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        cout << "\033[1;34mUpdated Max-Heap (Tree View):\033[0m\n";
        displayHeapTree(heap);
    }
}

// Task 3: Heapify an array into a Min-Heap
void task3HeapifyToMinHeap(vector<int>& array) {
    cout << "\033[1;35mOriginal Task Priorities:\033[0m\n";
    for (int val : array) {
        cout << "\033[1;36m" << val << "\033[0m ";
    }
    cout << endl;
    make_heap(array.begin(), array.end(), greater<>()); // Min-Heap
    cout << "\033[1;32mConverted to Min-Heap:\033[0m\n";
    displayHeapTree(array);
}

int main() {
    // Task 1: Max-Heap insertion
    cout << "\033[1;33mWelcome to the Superhero Mission Control Heap Challenge!\033[0m\n";
    cout << "In this challenge, you will manage superhero tasks based on priority using heaps.\n";
    cout << "\n\033[1;36mTask 1: Inserting tasks into a Max-Heap\033[0m\n";
    vector<int> maxHeap;
    make_heap(maxHeap.begin(), maxHeap.end());
    int value;
    cout << "\033[1;32mEnter the priority of superhero tasks one by one (enter -1 to stop):\033[0m\n";
    while (true) {
        cout << "Enter priority: ";
        cin >> value;
        if (value == -1) break;
        task1InsertMaxHeap(maxHeap, value);
    }

    // Task 2: Delete root from Max-Heap
    cout << "\n\033[1;36mTask 2: Deleting the highest-priority task from the Max-Heap\033[0m\n";
    task2DeleteRoot(maxHeap);

    // Task 3: Heapify an array into a Min-Heap
    cout << "\n\033[1;36mTask 3: Heapify a random list of task priorities into a Min-Heap\033[0m\n";
    cout << "\033[1;32mEnter an array of task priorities (space-separated):\033[0m ";
    vector<int> array;
    int num;
    while (cin >> num) {
        array.push_back(num);
        if (cin.peek() == '\n') break;
    }
    task3HeapifyToMinHeap(array);

    return 0;
}
    
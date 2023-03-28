//
// Created by Vahe Aleksanyan on 28.03.23.
//

#ifndef HEAP_MINHEAP_H
#define HEAP_MINHEAP_H


void swap(int *x, int *y);

class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);

    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }

    int right(int i) { return (2*i + 2); }

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin() { return harr[0]; }

    void deleteKey(int i);

    void insertKey(int k);
};


#endif //HEAP_MINHEAP_H
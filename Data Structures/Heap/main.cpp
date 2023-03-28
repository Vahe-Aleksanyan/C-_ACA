//
// Created by Vahe Aleksanyan on 28.03.23.
//
#include<iostream>
#include "MinHeap.h"
using namespace std;
int main()
{
    MinHeap h(33);
    h.insertKey(4);
    h.insertKey(67);
    h.deleteKey(45);
    h.insertKey(44);
    h.insertKey(44);
    h.insertKey(787);
    h.insertKey(0);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(0, 1);
    cout << h.getMin();
    return 0;
}


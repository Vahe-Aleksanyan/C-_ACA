//
// Created by Vahe Aleksanyan on 17.02.23.
//This is the file queue.cpp. This is the implementation of the
//template class Queue. The interface for the template class Queue is
//in the header file queue.h.
//

#include <iostream>
#include <cstdlib>
#include "queue.h"

using namespace ListVahe;

namespace VaheQueue {
    template<class T>
    Queue<T>::Queue():front(nullptr), back(nullptr) {}

    template<class T>
    bool Queue<T>::isEmpty() const {
        return (back == nullptr);//front == nullptr would also work
    }

    template<class T>
    Queue<T>::Queue(const Queue<T> &aQueue) {
        if (aQueue.isEmpty()) {
            front = back = nullptr;
        } else {
            Node<T> &temp = aQueue.front; // temp moves
            back = new Node<T>(temp->getData(), nullptr);
            front = back;
            //First node created and filled with data.
            //New nodes are now added AFTER this first node.
            temp = temp.getLink();
            while (temp != nullptr) {
                back->setLink(new Node<T>(temp.getData, nullptr));
                back = back->getLink();
                temp = temp.getLink();
            }
        }
    }

    template<class T>
    Queue<T> &Queue<T>::operator=(const Queue<T> &rightSide) {
        if (front = rightSide.front) { // in case the queues are the same
            return *this;
        } else {
            T next;
            while (!isEmpty()) {
                next = remove(); // remove deletes and returns deleted element
            }
            if (rightSide.isEmpty()) {
                front = back = nullptr;
                return *this;
            } else {

            }
        }
    }

    template<class T>
    Queue<T>::~Queue() {
        T next;
        while (!isEmpty()) {
            next = remove();
        }
    }

    template<class T>
    void Queue<T>::add(T item) {
        if (isEmpty())
            front = back = new Node<T>(item, nullptr);//Sets both
            //front and back to point to the only node
        else {
            back->setLink(new Node<T>(item, nullptr));
            back = back->getLink();
        }
    }

    template<class T>
    T Queue<T>::remove() {
        if (isEmpty()) {
            std::cout << "Error: Removing an item from an empty queue.\n";
            exit(1);
        }
        T result = front->getData();

        Node<T> *discard;
        discard = front;
        front = front->getLink();
        if (front == nullptr)
            back = nullptr;
        delete discard;
        return result;
    }
}

//
// Created by Vahe Aleksanyan on 17.02.23.
//This is the header file queue.h. This is the interface for the class
//Queue, which is a template class for a queue of items of type T,
//including iterators.
//

#ifndef ITERATOR_QUEUE_H
#define ITERATOR_QUEUE_H

#include "Iterator.h"

using namespace ListVahe;
namespace VaheQueue {
    template<class T>
    class Queue {
    public:
        typedef ListIterator<T> Iterator;

        Queue();

        Queue(const Queue<T> &aQueue);

        Queue<T> &operator=(const Queue<T> &rightSide);

        virtual ~Queue();

        void add(T item);

        T remove();

        bool isEmpty() const;

        Iterator begin() const { return Iterator(front); }

        Iterator end() const { return Iterator(); }
        //The end iterator has end( ).current == nullptr.
        //Note that you cannot dereference the end iterator.
    private:
        Node<T> *front;//Points to the head of a linked list.
        //Items are removed at the head.
        Node<T> *back; //Points to the node at the other end of
        //the linked list.
        //Items are added at this end.
    };
}

#endif //ITERATOR_QUEUE_H

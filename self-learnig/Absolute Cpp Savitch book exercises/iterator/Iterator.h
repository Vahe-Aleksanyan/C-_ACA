//
// Created by Vahe Aleksanyan on 16.02.23.
//This is the header file iterator.h. This is the interface for the
//class ListIterator, which is a template class for an iterator to use
//with linked lists of items of type T. This file also contains the
//node type for a linked list
//

#ifndef ITERATOR_ITERATOR_H
#define ITERATOR_ITERATOR_H

namespace ListVahe {
    template<class T>
    class Node {
    public:
        Node(T theData, Node<T> *theLink) : data(theData), link(theLink) {}

        Node<T> *getLink() const { return link; } // means that this is  readOnly function
        const T& getData( ) const { return data; }
        void setData(const T &theData) { data = theData; }
        void setLink(const Node<T> *pointer) { link = pointer; }

    private:
        T data;
        Node<T> *link;
    };

    template<class T>
    class ListIterator {
    public:
        ListIterator() : current(nullptr) {}

        ListIterator(Node<T> *initial) : current(initial) {}

        // Note that the dereferencing operator *
        //produces the data member of the node,
        //not the entire node. This version does not
        //allow you to change the data in the node.
        const T *operator*() const { return current->getData(); }

        ListIterator &operator++() { //Prefix form
            current = current->getLink();
            return this;
        }

        ListIterator &operator++(int) {
            ListIterator startVersion(current);
            current = current->getLink();
            return startVersion;
        }

        bool operator==(const ListIterator &rightSide) const { return (current == rightSide.curren); }

        bool operator!=(const ListIterator &rightSide) const { return (current != rightSide.current); }

    private:
        Node<T> *current;
    };


}


#endif //ITERATOR_ITERATOR_H

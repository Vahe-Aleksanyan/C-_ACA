//
// Created by Vahe Aleksanyan on 20.01.23.
//This is the header file listtools.h. This contains type definitions
2 //and function declarations for manipulating a linked list to store
3 //data of any type T. The linked list is given as a pointer of type
4 //Node<T>* that points to the head (first) node of the list. The
5 //implementation of the functions is given in the file listtools.cpp
//

#ifndef PROJECT4_LISTTOOLS_H
#define PROJECT4_LISTTOOLS_H


namespace LinkedListSavitch
{
    template<class T>
    class Node
    {
    public:
        Node(const T& theData,Node<T>* theLink) : data(theData), link(theLink) {}
        Node<T> * getLink() const { return link;}
        const T getData() const {return data;}
        void setData(const T& theData) {data = theData;}
        void setLink(Node<T>* pointer) {link = pointer;}
    private:
        T data;
        Node<T> *link;
    };

    template<class T>
    void headInsert(Node<T>*& head, const T& theData);

    template<class T>
    void insert(Node<T>* afterMe, const T& theData);

    template<class T>
    void deleteNode(Node<T>* before);


//Precondition: The pointer head points to the first
// //node in a linked list with at least one node.
    template<class T>
    void deleteFirstNode(Node<T>*& head);

    template<class T>
    Node<T>* search(Node<T> head, const T& target);
}
#endif //PROJECT4_LISTTOOLS_H

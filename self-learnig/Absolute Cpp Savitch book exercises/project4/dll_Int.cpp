//
// Created by Vahe Aleksanyan on 18.01.23.
//
class DoublyLinkedIntNode {
public:
    DoublyLinkedIntNode() {}
    DoublyLinkedIntNode(int theData, DoublyLinkedIntNode* previous, DoublyLinkedIntNode* next): data(theData), nextLink(next), previousLink(previous) {}
    DoublyLinkedIntNode * getNextLink() const { return nextLink;}
    DoublyLinkedIntNode* getPreviousLink() const {return previousLink;}
    int getData() const {return data;}
    void setData(int theData) { data = theData;}
    void setNextLink(DoublyLinkedIntNode* pointer) {nextLink = pointer;}
    void setPreviousLink(DoublyLinkedIntNode* pointer) {previousLink = pointer;}
private:
    int data;
    DoublyLinkedIntNode* nextLink;
    DoublyLinkedIntNode* previousLink;
};

typedef DoublyLinkedIntNode* DoublyLinkedIntNodePtr;


void headInsert(DoublyLinkedIntNode& head, int theData); // The pointer variable head points to the head of a linked list.

void headInsert(DoublyLinkedIntNodePtr& head, int theData)
{
    DoublyLinkedIntNode* newHead = new DoublyLinkedIntNode(theData, nullptr, head);
    head ->setPreviousLink(newHead);
    head = newHead;
}

//  The pointer variable head points to the head of a linked list and discard points to the node to remove.
void deleteNode(DoublyLinkedIntNodePtr& head, DoublyLinkedIntNodePtr discard);

void deleteNode(DoublyLinkedIntNodePtr& head, DoublyLinkedIntNodePtr discard)
{
    if (head == discard) // if deleting head
    {
        head = head->getNextLink();
        head->setPreviousLink(nullptr);
    } else {
        DoublyLinkedIntNodePtr prev = discard->getPreviousLink();
        DoublyLinkedIntNodePtr next = discard->getNextLink();
        prev->setPreviousLink(next);
        if (next != nullptr) // if it is not the last node
        {
            next ->setPreviousLink(prev);
        }
    }
    delete discard; // remember no garbage collection here, have to delete manually
}
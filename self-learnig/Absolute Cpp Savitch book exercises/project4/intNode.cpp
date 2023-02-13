//
// Created by Vahe Aleksanyan on 17.01.23.
//
class IntNode {
public:
    IntNode() {}
    IntNode(int theData, IntNode* theLink) : data(theData), link(theLink) {}
    IntNode* getLink() const {return link;}
    int getData() const { return data;}
    void setData(int theData) {data = theData;}
    void setLink(IntNode* pointer) {link = pointer;}
private:
    int data;
    IntNode *link;
};

typedef IntNode* IntNodePtr;


// function declaration
void headInsert(IntNodePtr& head, int theData);

// function definition, addFirst
void headInsert(IntNodePtr& head, int theData)
{
    head = new IntNode(theData, head);
}

// insert in the middle of the Linked List
void insert(IntNodePtr afterMe, int theData);

void insert(IntNodePtr afterMe, int theData)
{
    afterMe->setLink(new IntNode(theData, afterMe->getLink()));
}


IntNodePtr search(IntNodePtr head, int target);

IntNodePtr search(IntNodePtr head, int target) {
    IntNodePtr here = head;

    if(here == nullptr) return nullptr;
    else
    {
        while(here ->getData() != target && here->getLink() != nullptr)
            here = here ->getLink();

        if(here->getData() == target)
            return here;
        else
            return nullptr;
    }

}
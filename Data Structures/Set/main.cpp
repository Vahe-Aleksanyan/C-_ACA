//
// Created by Vahe Aleksanyan on 28.03.23.
// A Set is a collection of distinct elements. Elements cannot be modified once added.
// There are various operations associated with sets such as union, intersection, power set,
// Cartesian Product, set difference, complement, and equality.
//

#include <algorithm>
#include <iostream>
#include <math.h>
#include <stack>
#include <string>

using namespace std;

// Structure to implement a node of a BST
template<typename T>
struct Node {
    T data;
    Node *left;
    Node *right;

public:
// inorder traversal
    void inorder(Node *r) {
        if (r == NULL) {
            return;
        }
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }


//		Function to check if BST contains a node
//		with the given data
    int containsNode(Node *r, T d) {
        if (r == NULL)
            return 0;
        int x = r->data == d ? 1 : 0;
        return x | containsNode(r->left, d) | containsNode(r->right, d);
    }


// insert in the order, since we have ordered set
    Node *insert(Node *r, T d) {

        // if the given node is not valid, create a new one
        if (r == NULL) {
            Node<T> *tmp = new Node<T>;
            tmp->data = d;
            tmp->left = tmp->right = NULL;
            return tmp;
        }

        // Traverse the left subtree if data
        // is less than the current node
        if (d < r->data) {
            r->left = insert(r->left, d);
            return r;
        }

            // Traverse the right subtree if data
            // is greater than the current node
        else if (d > r->data) {
            r->right = insert(r->right, d);
            return r;
        } else
            return r;
    }
};

// Class to implement a Set using BST
template<typename T>
class Set {
    // Pointer to the root of the
    // BST storing the set data
    Node<T> *root;
    // The number of elements in the set
    int size;
public:
    // Default constructor
    Set() {
        root = NULL;
        size = 0;
    }

    // Copy constructor
    Set(const Set &s) {
        root = s.root;
        size = s.size;
    }

    // Function to Add an element to the set
    void add(const T data) {
        if (!root->containsNode(root, data)) {
            root = root->insert(root, data);
            size++;
        }
    }

    // Function to compute the union of two sets
    Set unionSet(Set &s) {
        Set<T> res;

        // if first set is empty
        if (root == NULL)
            return res;

        // if second set is empty
        if (s.root == NULL)
            return *this;

        // The elements of the first set are added to the resultant set
        stack<Node<T> *> nodeStack;
        nodeStack.push(root);

        // Preorder traversal of the BST
        while (!nodeStack.empty()) {
            Node<T> *node;
            node = nodeStack.top();
            nodeStack.pop();

            // The data is added to the resultant set
            res.add(node->data);

            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }

        // The elements of the second set
        // are added to the resultant set
        stack<Node<T> *> nodeStack1;
        nodeStack1.push(s.root);

        while (!nodeStack1.empty()) {
            Node<T> *node;
            node = nodeStack1.top();
            nodeStack1.pop();

            res.add(node->data);

            if (node->right)
                nodeStack1.push(node->right);
            if (node->left)
                nodeStack1.push(node->left);
        }

        return res;
    }
    Set intersectionSet(Set &s) {
        Set<T> res;
        stack<Node<T> *> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            Node<T> *node;
            node = nodeStack.top();
            nodeStack.pop();
            if (s.contains(node->data)) {
                res.add(node->data);
            }
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return res;
    }

    Set complementSet(Set &U) {
        return (U - *this);
    }


      // overload - to compute the difference of two sets
    Set operator-(Set &s) {
        Set<T> res;
        stack<Node<T> *> nodeStack;
        nodeStack.push(this->root);

        while (!nodeStack.empty()) {
            Node<T> *node;
            node = nodeStack.top();
            nodeStack.pop();
            if (!s.contains(node->data)) {
                res.add(node->data);
            }
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return res;
    }

        // overload == that checks equality of two sets
    bool operator==(Set &s) {
        if (s.getSize() != size) {
            return false;
        }
        stack<Node<T> *> nodeStack;
        nodeStack.push(this->root);

        while (!nodeStack.empty()) {
            Node<T> *node;
            node = nodeStack.top();
            nodeStack.pop();
            if (!s.contains(node -> data)) {
                return false;
            }
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return true;
    }


    //Function to print the cartesian product of two sets
    // just convert into array and do simple cartesian product
    void displayProduct(Set &s) {
        int i, j, n2 = s.getSize();
        T *A = toArray();
        T *B = s.toArray();

        i = 0;



        cout << "{ ";
        for (i = 0; i < size; i++) {
            for (j = 0; j < n2; j++) {
                cout << "{ " << A[i] << " " << B[j] << " } ";
            }
        }
        cout << "}" << endl;
    }


// function to convert set into array
    T *toArray() {
        T *A = new T[size];
        int i = 0;
        stack<Node<T> *> nodeStack;
        nodeStack.push(this->root);

        while (!nodeStack.empty()) {
            Node<T> *node;
            node = nodeStack.top();
            nodeStack.pop();

            A[i++] = node->data;

            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return A;
    }


//        Function to check whether the set contains an element

    bool contains(T data) {
        return root->containsNode(root, data) ? true : false;
    }

    // Function to print the contents of the set
    void displaySet() {
        cout << "{ ";
        root->inorder(root);
        cout << "}" << endl;
    }

    /*
        Function to return the current size of the Set

        @return size of set
    */
    int getSize() {
        return size;
    }
};

// Driver code
int main() {

    // Create Set A
    Set<int> A;

    // Add elements to Set A
    A.add(6);
    A.add(4);
    A.add(2);


    // Display the contents of Set A
    cout << "A is ";
    A.displaySet();


    // Check if Set A contains some elements
    cout << "A " << (A.contains(6) ? "contains"
                                   : "does not contain")
         << " 6" << endl;
    cout << "A " << (A.contains(44) ? "contains"
                                   : "does not contain")
         << " 44" << endl;
    cout << endl;

    // Create Set B
    Set<int> B;

    // Insert elements to Set B
    B.add(6);
    B.add(6);
    B.add(6);

    // Display the contents of Set B
    cout << "B = ";
    B.displaySet();

    cout << endl;

    // Create Set C
    Set<int> C;
    C.add(1);
    C.add(2);
    C.add(4);

    // Display the contents of Set C
    cout << "C = ";
    C.displaySet();
    cout << endl;

    // Set F contains the difference
    // of the Sets A and B
    Set<int> F = A - B;
    cout << "A - B = ";
    F.displaySet();
    cout << endl;

    // Set D contains the union
    // of the Sets A and B
    Set<int> D = A.unionSet(B);
    cout << "A union B = ";
    D.displaySet();
    cout << endl;

    // Set E contains the intersection
    // of the Sets A and B
    Set<int> E = A.intersectionSet(B);
    cout << "A intersection B = ";
    E.displaySet();
    cout << endl;

    // Display the product
    cout << "A x B = ";
    A.displayProduct(B);
    cout << endl;

    // Equality tests
    cout << "Equality of Sets:" << endl;

    cout << "A "
         << ((A == B) ? "" : "!") << "= B"
         << endl;
    cout << "B "
         << ((B == C) ? "" : "!") << "= C"
         << endl;
    cout << "A "
         << ((A == C) ? "" : "!") << "= C"
         << endl;
    cout << endl;

    Set<int> U;
    U.add(1);
    U.add(2);
    U.add(3);
    U.add(4);
    U.add(5);
    U.add(6);
    U.add(7);

    // Complements of the respective Sets
    Set<int> A1 = A.complementSet(U);
    Set<int> B1 = B.complementSet(U);
    Set<int> C1 = C.complementSet(U);

    cout << "A' = ";
    A1.displaySet();
    cout << "B' = ";
    B1.displaySet();
    cout << "C' = ";
    C1.displaySet();

    return 0;
}

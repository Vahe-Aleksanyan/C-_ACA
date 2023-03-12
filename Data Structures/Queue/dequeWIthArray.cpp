#include "iostream"
using namespace std;

// Class definition of the deque
template <class X>
class Deque {

private:
    // Stores the frontIndex
    int frontIndex;

    // Stores the backIndex
    int backIndex;

    // Stores the array
    X* arr;

    // Stores the size of deque
    int sizeVar;

    // Stores the size of array
    int capacityVar = 4;

public:
    // Deque class constructor
    Deque()
    {
        arr = new X[capacityVar];
        frontIndex = backIndex = -1;
        sizeVar = 0;
    }

    // Function methods
    bool empty();
    bool full();
    void push_back(X x);
    void push_front(X x);
    void pop_front();
    void pop_back();
    X front();
    X back();
    int capacity();
    int size();
};

// Function to find the capacity of the deque
template <class X>
int Deque<X>::capacity()
{
    return capacityVar;
}

// Function to find the number of elements
// present in deque
template <class X>
int Deque<X>::size() { return sizeVar; }

// Function to check if deque is empty or not
template <class X>
bool Deque<X>::empty()
{
    if (frontIndex == -1 && backIndex == -1)
        return true;
    else
        return false;
}

// Function to check if deque is full or not
template <class X>
bool Deque<X>::full()
{
    if (sizeVar == capacityVar)
        return true;
    else
        return false;
}

// Function to find the front element of the deque
template <class X>
X Deque<X>::front()
{
    // If deque is empty
    if (empty()) {
        cout << "Deque underflow" << endl;
        abort();
    }
    return arr[frontIndex];
}

// Function to find the last element of the deque
template <class X>
X Deque<X>::back()
{
    // If deque is empty
    if (empty()) {
        cout << "Deque underflow" << endl;
        abort();
    }
    return arr[backIndex];
}

// Function to insert the element
// to the back of the deque
template <class X>
void Deque<X>::push_back(X x)
{
    if (full()) {

        // If the deque is full, then
        // double the capacity
        capacityVar = capacityVar * 2;

        // Initialize new array of
        // double size
        X* temp = new X[capacityVar];

        // Copy the elements of the
        // previous array
        int i = frontIndex;
        int j = 0;
        while (i != backIndex) {
            temp[j] = arr[i];
            i = (i + 1) % sizeVar;
            j++;
        }
        temp[j] = arr[i];

        frontIndex = 0;
        backIndex = sizeVar - 1;

        // Deallocate the memory
        // of previous array
        delete[] arr;
        arr = temp;
    }

    // If size is zero
    if (empty()) {
        frontIndex = backIndex = 0;
        arr[backIndex] = x;
        sizeVar++;
        return;
    }

    // Increment back index cyclically
    backIndex = (backIndex + 1) % capacityVar;
    arr[backIndex] = x;
    sizeVar++;
    return;
}

// Function to insert the element
// to the front of the deque
template <class X>
void Deque<X>::push_front(X x)
{
    if (full()) {

        // If the deque is full, then
        // double the capacity
        capacityVar = capacityVar * 2;

        // Initialize new array of
        // double size
        X* temp = new X[capacityVar];

        // Copy the elements of the
        // previous array
        int i = frontIndex;
        int j = 0;
        while (i != backIndex) {
            temp[j] = arr[i];
            i = (i + 1) % sizeVar;
            j++;
        }
        temp[j] = arr[i];

        frontIndex = 0;
        backIndex = sizeVar - 1;

        // Deallocate the memory
        // of previous array
        delete[] arr;
        arr = temp;
    }

    // If size is zero
    if (empty()) {
        frontIndex = backIndex = 0;
        arr[backIndex] = x;
        sizeVar++;
        return;
    }

    // Decrement front index cyclically
    frontIndex
            = (frontIndex - 1 + capacityVar) % capacityVar;
    arr[frontIndex] = x;
    sizeVar++;
    return;
}

// Function to delete the element
// from the front of the deque
template <class X>
void Deque<X>::pop_front()
{
    // If deque is empty
    if (empty()) {
        cout << "Deque underflow" << endl;
        abort();
    }

    // If there is only one character
    if (frontIndex == backIndex) {

        // Mark deque as empty
        // and decrement sizeVar
        frontIndex = backIndex = -1;
        sizeVar--;
        return;
    }

    // Increment frontIndex cyclically
    frontIndex = (frontIndex + 1) % capacityVar;
    sizeVar--;
    return;
}

// Function to delete the element
// from the back of the deque
template <class X>
void Deque<X>::pop_back()
{
    // If deque is empty
    if (empty()) {
        cout << "Deque underflow" << endl;
        abort();
    }

    // If there is only one character
    if (frontIndex == backIndex) {

        // Mark deque as empty
        // and decrement sizeVar
        frontIndex = backIndex = -1;
        sizeVar--;
        return;
    }

    // Decrement backIndex cyclically
    backIndex = (backIndex - 1 + capacityVar) % capacityVar;
    sizeVar--;
    return;
}

// Driver Code
//int main()
//{
//    // Deque initialization
//    Deque<int> q;
//
//    // Iterate range [1, 100],
//    // push even numbers at the back
//    // and push odd numbers at the front
//    for (int i = 1; i < 10; i++)
//        if (i % 2 == 0)
//            q.push_back(i);
//        else
//            q.push_front(i);
//
//    // Print the current capacity
//    cout << "Current capacity " << q.capacity() << endl;
//
//    // Print the current size
//    cout << "Current size " << q.size() << endl;
//
//    // Print front elements of deque
//    cout << "Front element " << q.front() << endl;
//
//    // Print last element of the deque
//    cout << "Rear element " << q.back() << endl;
//
//    cout << endl;
//
//    cout << "Pop an element from front" << endl;
//
//    // Pop an element from the front of deque
//    q.pop_front();
//
//    cout << "Pop an element from back" << endl;
//
//    // Pop an element from the back of deque
//    q.pop_back();
//
//    cout << endl;
//
//    // Print the current capacity
//    cout << "Current capacity " << q.capacity() << endl;
//
//    // Print current size
//    cout << "Current size " << q.size() << endl;
//
//    // Print front elements of deque
//    cout << "Front element " << q.front() << endl;
//
//    // Print last element of the deque
//    cout << "Rear element " << q.back() << endl;
//
//    return 0;
//}
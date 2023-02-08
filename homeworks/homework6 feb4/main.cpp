//
// Created by Vahe Aleksanyan on 08.02.23.
//
int main() {
    return 1;
}

// ***************************************************
//
// ----------- All codes are submitted int he leetCode, all tests pass, all code works fine ----------
//
// ***************************************************


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 19. Remove Nth Node From End of List
class Solution19 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *slow = head;
        ListNode *fast = head;
        int i = 0;
        while (i < n) {
            fast = fast->next;
            i++;
        }
        if (!fast) {
            return head->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};


// 83. Remove Duplicates from Sorted List
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};


// 82. Remove Duplicates from Sorted List II
class Solution82 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *answer = new ListNode(0);
        ListNode *curr = answer;

        while (head) {
            bool flag = false;
            while (head->next && head->val == head->next->val) {
                flag = true;
                head = head->next;
            }
            if (!flag) {
                curr->next = head;
                curr = head;
                head = head->next;
                curr->next = nullptr;
            } else {
                head = head->next;
            }
        }

        return answer->next;
    }
};

//430. Flatten a Multilevel Doubly Linked List

// Definition for a Node.
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution430 {

public:
    Node *flatten(Node *head) {
        Node *cursor = head;
        while (cursor) {
            if (cursor->child) {
                Node *itr2 = flatten(cursor->child); // use recursion to flatten all layers
                Node *next = cursor->next;
                // Add child-list next to current node
                patch(cursor, itr2);
                while (itr2->next) itr2 = itr2->next;
                // Add 'next' node after last element of child list
                patch(itr2, next);
                cursor->child = nullptr;
                cursor = next;
            } else cursor = cursor->next;
        }
        return head;
    }

    // helper method to put the list in between current and next node.
    void patch(Node *current, Node *next) {
        if (current) current->next = next;
        if (next) next->prev = current;
    }

};

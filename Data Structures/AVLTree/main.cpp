//
// Created by Vahe Aleksanyan on 28.03.23.
//
#include<iostream>
#include "avl_tree.h"
using namespace std;
int main() {
    int c, i;
    avl_tree avl;
    while (1) {
        cout << "1.Insert" << endl;
        cout << "2.show" << endl;
        cout << "3.InOrder " << endl;
        cout << "4.PreOrder " << endl;
        cout << "5.PostOrder" << endl;
        cout << "6.Exit" << endl;
        cout << "Your Choice is  ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter value ";
                cin >> i;
                r = avl.insert(r, i);
                break;
            case 2:
                if (r == NULL) {
                    cout << "Tree is Empty" << endl;
                    continue;
                }
                cout << "Balanced AVL Tree:" << endl;
                avl.show(r, 1);
                cout << endl;
                break;
            case 3:
                cout << "Inorder Traversal:" << endl;
                avl.inorder(r);
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal:" << endl;
                avl.preorder(r);
                cout << endl;
                break;
            case 5:
                cout << "Postorder Traversal:" << endl;
                avl.postorder(r);
                cout << endl;
                break;
            case 6:
                exit(1);
                break;
            default:
                cout << "Wrong" << endl;
        }
    }
    return 0;
}
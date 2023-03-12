//
// Created by Vahe Aleksanyan on 23.02.23.
//
#include<iostream>
using namespace std;

template<typename T>class Node{
private:
    T data;
    Node<T>* next;
    template<typename U>friend class Stack;
};

template<typename T>class Stack{
private:
    Node<T>* top;
public:
    Stack(){
        this->top = NULL;
    }

    bool empty(){
        return this->top == NULL;
    }

    int size(){
        if(empty()) return 0;
        int s = 1;
        Node<T>* temp = top;
        while(temp != NULL){
            s++;
            temp = temp->next;
        }
    }

    void push(T item){
        Node<T>* node = new Node<T>[1];
        node->data = item;
        if(top == NULL){
            top = node;
        }else{
            node->next = top;
            top = node;
        }
        cout<<item<<" pushed"<<endl;
    }

    T topItem(){
        if(empty()) return NULL;
        return this->top->data;
    }

    void pop(){
        if(empty()){
            cout<<"stack is empty"<<endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        temp->next = NULL;
        cout<<"popped "<<temp->data<<endl;
        return;
    }
};

int main(){
    //int type stack
    Stack<int> stack;
    bool exit = false;
    do{
        cout<<"===================================="<<endl;
        cout<<"select option :"<<endl;
        cout<<"1 for push"<<endl;
        cout<<"2 for pop"<<endl;
        cout<<"3 for top item"<<endl;
        cout<<"4 for exit"<<endl;
        int ch;
        cin>>ch;
        cout<<"===================================="<<endl;
        switch(ch){
            case 1:
                cout<<"enter value to push"<<endl;
                int num;
                cin>>num;
                stack.push(num);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout<<"top item:"<<stack.topItem()<<endl;
                break;
            case 4:
                exit = true;
                cout<<"exiting..."<<endl;
                break;
            default:
                cout<<"invalid selection !"<<endl;
                break;
        }
    }while(!exit);

    return 0;
}
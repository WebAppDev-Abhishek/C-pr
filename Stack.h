#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

//Node structure
struct Node {
    int data;
    Node* next;
};

class stack {
    private:
    Node* topNode;
public:
    stack(): topNode(nullptr){}

    //Push oparation
    void push(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
        cout<<"Element "<<value<<"\nPushed to stack"<<endl;
    }

    //Pop operation
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow! Nothing to pop."<<endl;
            return;
        }

        Node* temp = topNode;
        int poppedVal = temp->data;
        topNode=topNode->next;
        delete temp;
        cout<<"Element "<<poppedVal<<"popped from stack."<<endl;
    }

    //Peek/Top operation
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
        }else{
            cout<<"Top element is: "<<topNode->data<<endl;
        }
    }

    bool isEmpty(){
        return topNode == nullptr;
    }

};

#endif
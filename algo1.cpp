#include <iostream>
using namespace std;

//Node structure
struct Node {
    int data;
    Node* next;
};

class stack {
    Node* topNode;

    stack(): topNode(nullptr){}

    void createNode(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
        cout<<"New node are"<<value<<"push as top node";
    }

    void display(){
        cout<<"This is a stack:";
        Node* temp = topNode;
        while(temp!=nullptr){
            cout<<temp->data<<"--";
            temp=temp->next;
        }
    }
};


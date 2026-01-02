#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val):data(val), next(nullptr){}
};

class LinkedList {
    public:
    Node* head;
    LinkedList():head(nullptr) {}

    //function to remove a specific value
    void removeItems(int value){
        Node* temp = head;
        Node* prev= nullptr;

        //Case 1: the list is Empty
        if(temp==nullptr) return;

        //Case 2: The items to be removed is the node
        if(temp!=nullptr && temp->data == value){
            head = temp->next;
            delete temp;
            return;
        }

        //Case 3: Search the value to be deleted
        while(temp!=nullptr && temp->data!=value){
            prev = temp;
            temp = temp->next;
        }

        //Case 4: If value was not present in the list
        if(temp == nullptr){
            cout<<"Value"<<value<<"Not found."<<endl;
            return;
        }

        //Case 5: Unlink the code from linked list
        prev->next = temp->next;
        delete temp; //free memory
    }
};
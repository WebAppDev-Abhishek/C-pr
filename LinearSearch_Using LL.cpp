#include <iostream>
using namespace std;

//Define the node structure 
struct Node {
    int data;
    Node* next;
};

//function to insert a new node at the beginning
void push(Node** headRef, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = (*headRef);
    (*headRef)= newNode;
}

//function to perform linear Seacrch
bool search(Node* head, int target){
    Node* current = head;
    int position = 0;

    while(current!=nullptr){
        if(current->data==target){
            cout<<"element"<<target<<"found at position"<<position<<endl;
            return true;
        }
        current = current->next;
        position++;
    }
    return false;
}

int main(){
    Node* head=nullptr;

    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    int target;
    cout<<"Enter value to search in linked list: ";
    cin>>target;

    if(!search(head, target)){
        cout<<"Element not found."<<endl;
    }
    return 0;

}

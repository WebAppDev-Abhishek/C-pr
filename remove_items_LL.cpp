#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    public:
    Node* head;
    LinkedList(){
        head = nullptr;
    }

    //Add a node at the beginning
    void insert(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    //function to remove a specific value
    void removeItems(int value){
        Node* temp = head;
        Node* prev= nullptr;

        //Case 1: the list is Empty
        if(temp==nullptr) {
            cout<<"List is empty, nothing to delete.\n";
            return;
        }

        //Case 2: The items to be removed is the node
        if(temp!=nullptr && temp->data == value){
            head = temp->next;
            delete temp;
            cout<<"Removed"<<value<<"from head.\n";
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

    void display(){
        if(head == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList list;

    //build the list
    list.insert(50);
    list.insert(40);
    list.insert(30);
    list.insert(50);

    cout<<"Original List: ";
    list.display();

    //Remove from the head
    list.removeItems(30);
    list.display();

    //Remove from the head
    list.removeItems(10);
    list.display();

    //try to remove non-existent item
    list.removeItems(100);
    list.display();

    return 0;
}
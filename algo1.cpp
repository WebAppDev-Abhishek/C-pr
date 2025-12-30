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

    //Display all elements
    void display(){
        Node* temp = topNode;
        while(temp!=nullptr){
            cout<<temp->data<<"--";
            temp=temp->next;
        }
    }
};

int main(){
    stack st;
    int choice, val;

    cout<<"----Linked lsit Stack Menu------"<<endl;
    do{
        cout<<"\n1. Push\n2. Pop\n3. Peek(top)\n4. Display stack\n5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter the value to push: ";
                cin>>val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                st.display();
                break;
            case 5:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please try again "<<endl;
        }
    }while(choice!=5);

    return 0;
    
}

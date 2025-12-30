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

    void createNode(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
        cout<<"New node are: "<<value<<"\npush as top node"<<endl;
    }

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
    int count, val;

    cout<<"Enter the number of nodes:"<<endl;
    cin>>count;

    for(int i = 0; i<count; i++){
        cout<<"Enter the node data"<<(i+1)<<" ";
        cin>>val;
        st.createNode(val);
    }

    cout<<"This is a stack:"<<endl;
    st.display();

    return 0;
}

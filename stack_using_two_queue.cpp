#include <iostream>
using namespace std;

//1.Custom Queue Node
struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr){}
};

//2.Custom Queue Implementation
class CustomQueue{
    private:
    Node *front, *rear;
    public:
    CustomQueue():front(nullptr), rear(nullptr){}

    void enqueue(int x){
        Node* temp = new Node(x);
        if(rear==nullptr){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    int dequeue(){
        if(front == nullptr) return -1;
        Node* temp = front;
        int data = temp->data;
        front = front->next;
        if(front == nullptr) rear = nullptr;
        delete temp;
        return data;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    int peek(){
        return (front!=nullptr)?front->data: -1;
    }
};

//3. Stack Implementation using two CustomQueue
class StackUsingQueues{
    CustomQueue q1,q2;

    public:
    void push(int x){
        //Add to q2
        q2.enqueue(x);

        //Move everything fromq1 to q2
        while(!q1.isEmpty()){
            q2.enqueue(q1.dequeue());
        }

        //Swap q1 and q2
        //In manual implementation, we simply re-assign logic
        CustomQueue temp = q1;
        q1 = q2;
        q2 = temp;

        cout<<"Pushed"<<x<<"to Stack"<<endl;
    }

    void pop(){
        if(q1.isEmpty()){
            cout<<"Stack Underflow!"<<endl;
            return;
        }
        cout<<"Popped"<<q1.dequeue()<<endl;
    }

    int top(){
        return q1.peek();
    }
};

int main(){
    StackUsingQueues myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout<<"Current Top:"<<myStack.top()<<endl;

    myStack.pop();
    cout<<"TopAfter one pop:"<<myStack.top()<<endl;
    return 0;
}





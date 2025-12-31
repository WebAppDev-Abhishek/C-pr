#include <iostream>
#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;

    public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull(){ return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1));}
    bool isEmpty() {return front == -1; }

    void enqueue(int value){
        if(isFull()){
            std::cout <<"Queue Overflow\n";
            return;
        }

        if(front == -1) front = 0; //first element
        rear = (rear + 1) % MAX;
        arr[rear] = value;
    }

    
}
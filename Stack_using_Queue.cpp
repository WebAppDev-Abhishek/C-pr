#include <iostream>

#define MAX 5 // Size of the circular queue

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1));
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Add an element to the back
    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue Overflow: Cannot add " << value << std::endl;
            return;
        }
        if (front == -1) { // Inserting the first element
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        std::cout << "Enqueued: " << value << std::endl;
    }

    // Remove an element from the front
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow: Nothing to remove" << std::endl;
            return -1;
        }
        int data = arr[front];
        if (front == rear) { 
            // Only one element was present, queue is now empty
            front = rear = -1; 
        } else {
            front = (front + 1) % MAX;
        }
        return data;
    }

    // Look at the front element
    void peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
        } else {
            std::cout << "Front element is: " << arr[front] << std::endl;
        }
    }

    // Helper function to print the current state
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        int i = front;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        std::cout << std::endl;
    }
};

int main(){
    Queue q;

    //1. fill the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    //2. try to overflow
    q.enqueue(60);

    //3.Dequeue elements
    std::cout<<"Dequeued: "<<q.dequeue()<<std::endl;
    std::cout<<"Dequeued: "<<q.dequeue()<<std::endl;

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();
    q.peek();

    return 0;
   
}
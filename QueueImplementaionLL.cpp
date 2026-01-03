#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue: Add element to the end
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        // If queue is empty, new node is both front and rear
        if (rear == nullptr) {
            front = rear = newNode;
            cout << "Enqueued: " << value << endl;
            return;
        }

        // Add the new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue: Remove element from the front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow (Empty)" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        // If front becomes NULL, then change rear also to NULL
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();
    
    return 0;
}
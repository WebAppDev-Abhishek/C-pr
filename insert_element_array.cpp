#include <iostream>
using namespace std;

//Function to display the array
void display(int arr[], int size){
    cout<<"Array elements: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Function to insert an element at a specific index
bool insertElement(int arr[], int &size, int capacity, int element, int index){
    //check if array is full or index is out of bounds
    if(size>=capacity){
        cout<<"Error: Array capacity reached."<<endl;
        return false;
    }

    if(index < 0 || index >size){
        cout<<"Error: Invalid index."<<endl;
        return false;
    }

    //Shift elements to the right starting from the end
    for(int i = size - 1; i >=index; i--){
        arr[i+1] = arr[i];
    }

    //Insert the elemet and incease size
    arr[index] = element;
    size++;
    return true;
}

int main() {
    int capacity = 100; // Maximum size of the array
    int arr[100] = {10, 20, 30, 40, 50}; // Initial elements
    int size = 5; // Current number of elements

    cout << "--- Initial Array ---" << endl;
    display(arr, size);

    int element, index;
    cout << "\nEnter element to insert: ";
    cin >> element;
    cout << "Enter index (0 to " << size << "): ";
    cin >> index;

    if (insertElement(arr, size, capacity, element, index)) {
        cout << "\nInsertion Successful!" << endl;
        display(arr, size);
    }

    return 0;
}
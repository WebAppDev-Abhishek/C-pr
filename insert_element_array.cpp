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

int main(){
    int capacity = 100;
    int 
}

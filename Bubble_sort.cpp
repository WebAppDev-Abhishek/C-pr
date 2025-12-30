#include <iostream>
using namespace std;

//function to perform bubble sort
void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                //Swap the elements
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            } 
        }
    }
}

//Function tp print the array
void printArray(int arr[], int size){
    for(int i= 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;

    cout<<"Enter the Number of the elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<"elements: "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Unsrted array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout<<"Sorted array: ";
    printArray(arr, n);

    return 0;
}
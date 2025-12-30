#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

//Linear Search: 0(n)
int linearSearch(int arr[], int n, int target){
    for(int i = 0; i<n; i++){
        if(arr[i] == target)
        return i;
    }
    return -1;
}

//Binary Search: 0(log n)
int binarySearch(int arr[], int n, int target){
    int low = 0, high = n-1;
    while (low<=high){
        int mid = low + (high-low)/2;
        if (arr[mid]==target)
            return mid;
        if (arr[mid]<target){
            low = mid + 1;
        }else high = mid - 1;
    }
    return -1;
}

#endif
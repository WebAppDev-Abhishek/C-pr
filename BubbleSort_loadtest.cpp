#include <iostream>
#include <chrono> //High-resolution timing
#include <cstdlib> //for rand()
#include <ctime> // to seed the random number generator
#include "bubbleSort.h"

using namespace std;
using namespace std::chrono;

int main(){
    //Set the number of entries
    const int N = 100000;

    //Allocate memory on the heap for latge data
    int* data = new int[N];

    //fill array with random number
    srand(time(0));
    for(int i = 0; i<N; i++){
        cout<<"-----Bubble Sort Load test ----"<<endl;
        cout<<"Input Size: "<<N<<"elements"<<endl;
        cout<<"Sorting..(This may take a few minutes for 100k items)"<<endl;

        //Start timer
        auto start = high_resolution_clock::now();

        bubbleSort(data, N);

        //Stop Timer
        auto stop = high_resolution_clock::now();

        //CAlculate duration
        auto duration = duration_cast<milliseconds>(stop-start);

        cout<<"Test Finished "<<endl;
        cout<<"Total execation time: "<<duration.count()<<"ms"
        <<"("<<duration.count()/1000.0<<" seconds)"<<endl;

        //Clean up heap memory
        delete[] data;

        return 0;
    }
}
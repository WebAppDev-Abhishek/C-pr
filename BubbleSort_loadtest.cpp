#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "bubbleSort.h"

using namespace std;
using namespace std::chrono;

int main() {
    const int N = 20000; 
    int* data = new int[N];

    srand(time(0));
    for (int i = 0; i < N; i++) {
        data[i] = rand() % 100000;
    }

    cout << "--- High Precision Load Test ---" << endl;
    
    // Start Timer
    auto start = high_resolution_clock::now();

    bubbleSort(data, N);

    // Stop Timer
    auto stop = high_resolution_clock::now();
    
    // CHANGE: Use microseconds for better precision
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Input Size: " << N << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
    cout << "Execution Time: " << duration.count() / 1000.0 << " milliseconds" << endl;

    // To prevent the compiler from optimizing away the sort, 
    // print a tiny piece of the result.
    cout << "Verification (Last element): " << data[N-1] << endl;

    delete[] data;
    return 0;
}
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "searchAlgorithms.h"

using namespace std;
using namespace std::chrono;

int main() {
    const int N = 100000;
    int* data = new int[N];

    // Create a sorted array (0, 1, 2...99999)
    for (int i = 0; i < N; i++) {
        data[i] = i;
    }

    int target = 99999; // Search for the very last element (Worst Case)

    cout << "---- The Great Search Race (N=" << N << ") ----" << endl;

    // ----- Test Linear Search (Measured in Microseconds) ------
    auto start1 = high_resolution_clock::now();
    linearSearch(data, N, target);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    // --- Test Binary Search (Measured in Nanoseconds for precision) ---
    auto start2 = high_resolution_clock::now();
    binarySearch(data, N, target);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);

    // Convert Linear Search to Nanoseconds for an accurate comparison
    long long linear_ns = duration_cast<nanoseconds>(stop1 - start1).count();
    long long binary_ns = duration2.count();

    cout << "Linear Search: " << duration1.count() << " microseconds" << endl;
    cout << "Binary Search: " << binary_ns << " nanoseconds" << endl;
    
    if (binary_ns > 0) {
        // Use double to show the exact multiplier
        double faster = static_cast<double>(linear_ns) / binary_ns;
        cout << "Binary Search was " << faster << "x faster!" << endl;
    } else {
        cout << "Binary Search was too fast to measure even in nanoseconds!" << endl;
    }

    delete[] data;
    return 0;
}
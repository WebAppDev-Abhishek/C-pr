#include <iostream>
#include <chrono> //for high precision timing
#include "Stack.h"

using namespace std;
using namespace std::chrono;

int main(){
    stack st;

    int iterations = 100000;

    cout<<"Starting load test with"<<iterations<<"Nodes..."<<endl;

    //Start timer
    auto start = high_resolution_clock::now();

    for(int i = 0; i<iterations; i++){
        st.push(i);
    }

    //End timer
    auto stop =  high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout <<"Successfully pushed"<<iterations<<"nodes"<<endl;
    cout <<"Total time taken: "<<duration.count()<<"miliseconds."<<endl;

    return 0;
}
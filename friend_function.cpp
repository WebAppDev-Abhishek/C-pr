#include <iostream>
#include <cassert>
using namespace std;

class Box {
    private:
    int width;
    public:
    Box(int w):width(w){}
    // friend declaration
    friend int getWidth(Box b);
};

int getWidth(Box b){
    return b.width; //Accessing private member
}

void testFriendFunction(){
    Box b(50);
    assert(getWidth(b) == 50);
    cout<<"Test passed: frined function successfully accessed private data!"<<endl;
}

int main(){
    testFriendFunction();
    return 0;
}
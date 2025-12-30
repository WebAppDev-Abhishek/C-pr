#include <iostream>
#include <iostream>
#include <iomanip>

struct Node{
    int data;
    int x, y, z;
    int id;
    Node *next, *prev, *up, *down; //up/down for Z-axis, next, next for X-axis
    Node *front, *back;            //We'll use these for the Y-axis (Depth)

    Node(int _x, int _y, int _z, int _id):x(_x),y(_y),z(_z),id(_id){
        data = _id*10;
        next = prev = up = down = front = back = nullptr;
    }
};

//Function to build a 10x10x10 Cude
Node* Build3DGrid(int size){
    //Using a 3D array of pointers to simplify the "stitching" process
    static Node* cube[10][20][30];
    int currentId = 1;

    //1.Instantiate nodes
    for(int z=0; z<size;z++){
        
    }
}
#include <iostream>
#include <iomanip>
#include <vector>

// --- CROSS-PLATFORM KEYBOARD INPUT ---
#ifdef _WIN32
    #include <conio.h>
    #define CLEAR "cls"
    #define GETCH() _getch()
#else
    #include <termios.h>
    #include <unistd.h>
    #define CLEAR "clear"
    // Custom getch for Linux/macOS
    int GETCH() {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif

struct Node {
    int data;
    int x, y, z;
    int id;
    Node *next, *prev, *up, *down, *front, *back;

    Node(int _x, int _y, int _z, int _id) 
        : x(_x), y(_y), z(_z), id(_id) {
        data = _id * 5; // Example data
        next = prev = up = down = front = back = nullptr;
    }
};

Node* build3DGrid(int size) {
    // 3D vector to store pointers for easy linking
    std::vector<std::vector<std::vector<Node*>>> cube(size, 
        std::vector<std::vector<Node*>>(size, std::vector<Node*>(size)));
    
    int idCounter = 1;
    for (int z = 0; z < size; z++)
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
                cube[z][y][x] = new Node(x, y, z, idCounter++);

    // Link the nodes
    for (int z = 0; z < size; z++) {
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                Node* n = cube[z][y][x];
                if (x + 1 < size) n->next  = cube[z][y][x + 1];
                if (x - 1 >= 0)   n->prev  = cube[z][y][x - 1];
                if (y + 1 < size) n->front = cube[z][y + 1][x];
                if (y - 1 >= 0)   n->back  = cube[z][y - 1][x];
                if (z + 1 < size) n->up    = cube[z + 1][y][x];
                if (z - 1 >= 0)   n->down  = cube[z - 1][y][x];
            }
        }
    }
    return cube[0][0][0];
}

void draw(Node* head, Node* current) {
    system(CLEAR);
    int cz = current->z;
    std::cout << "--- 3D NAVIGATOR (Z-Layer: " << cz << ") ---\n";
    std::cout << "WASD: Move | R: Up Level | F: Down Level | Q: Quit\n\n";

    // Find the start of the current Z-layer
    Node* layer = head;
    while(layer && layer->z != cz) layer = layer->up;

    while (layer) {
        Node* row = layer;
        while (row) {
            if (row == current) std::cout << "[" << std::setw(3) << row->id << "]";
            else std::cout << " " << std::setw(3) << row->id << " ";
            row = row->next;
        }
        std::cout << "\n\n";
        layer = layer->front;
    }
    std::cout << "Current Node: " << current->id << " at (" << current->x << "," << current->y << "," << current->z << ")\n";
}

int main() {
    Node* head = build3DGrid(10);
    Node* current = head;
    bool running = true;

    while (running) {
        draw(head, current);
        char key = GETCH();

        switch (key) {
            case 'w': if (current->back)  current = current->back;  break;
            case 's': if (current->front) current = current->front; break;
            case 'a': if (current->prev)  current = current->prev;  break;
            case 'd': if (current->next)  current = current->next;  break;
            case 'r': if (current->up)    current = current->up;    break;
            case 'f': if (current->down)  current = current->down;  break;
            case 'q': running = false; break;
        }
    }
    return 0;
}
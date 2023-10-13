#include <iostream>
using namespace std;
#include "necklace.h"

void necklace::insertpearl(int c, int s) {
    // 1. Create a pearl
    pearl* tmp = new pearl;

    // 2. Fill in the pearl
    tmp->color = c;
    tmp->size = s;
    tmp->hole = nullptr;

    // 3. Link it to the necklace
    if (head == nullptr) {
        head = tmp;
    } else {
        tmp->hole = head;
        head = tmp;
    }
}

void necklace::printrec(pearl *current) {
    if (current == nullptr) {
        return; // Base case: stop when we reach the end of the necklace
    }
    
    // Print the current pearl's details
    cout << "Color: " << current->color << ", Size: " << current->size << endl;
    
    // Recursively print the rest of the necklace
    printrec(current->hole);
}

// Public wrapper function to start the recursion from the head
void necklace::print() {
    cout << "Necklace Contents:" << endl;
    printrec(head);
}
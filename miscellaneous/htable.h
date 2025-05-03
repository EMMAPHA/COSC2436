#include <iostream>
//hashing works well with small size memory
//cache is most frequently used memory --so hashing is good for cache
using namespace std;
class htable {
private:
    int* elt;
    int size;

    int hfunction(int x) {
        return x % size;
    }

    int h2(int x) {
        return 1 + (x % (size - 1)); // Linear probing increment
    }

public:
    htable(int s = 10) {
        size = s;
        elt = new int[s]();
    }

    // Hashing with direct probing

//direct hashing
//disadvantage: overwriting, unused elements/space
//advantage: fast
//time complexity: O(1)
    void insert_direct(int x) {
        int i = hfunction(x);
        if (elt[i] == 0) {
            elt[i] = x;
        }
        else {
            // Handle collision using linear probing
            int j = i;
            do {
                j = (j + 1) % size; // Linear probing
                if (j == i) {
                    std::cout << "Table is full. Cannot insert " << x << std::endl;
                    return;
                }
            } while (elt[j] != 0);
            elt[j] = x;
        }
    }

    // Hashing with linear probing

//direct hashing vs linear probing - which one is better and why?

//Linear probing
//in case of collision
//check if the element/the next element is empty, then put it there
//advantage: all elments are used
//time complexity: O(n)
    void insert_linear(int x) {
        int i = hfunction(x);
        if (elt[i] == 0) {
            elt[i] = x;
        }
        else {
            // Handle collision using linear probing
            int j = i;
            int step = h2(x);
            do {
                j = (j + step) % size;
                if (j == i) {
                    std::cout << "Table is full. Cannot insert " << x << std::endl;
                    return;
                }
            } while (elt[j] != 0);
            elt[j] = x;
        }
    }

    // Hashing with quadratic probing

//trying to enhance linear
//i+ 1^2.. i+2^2... i+3^2...
//advantage: trying to enhance linear time...minimize O(n).
//works better with cache2
//disadvantage: 
//time complexity: O
    void insert_quadratic(int x) {
        int i = hfunction(x);
        if (elt[i] == 0) {
            elt[i] = x;
        }
        else {
            // Handle collision using quadratic probing
            int j = i;
            int k = 1;
            do {
                j = (j + k * k) % size;
                if (j == i) {
                    std::cout << "Table is full. Cannot insert " << x << std::endl;
                    return;
                }
                k++;
            } while (elt[j] != 0);
            elt[j] = x;
        }
    }

    // Hashing with double hashing

// h1(x) = x%10
// h2(x) = 3 - (x%3)
//in case of collision
//first collision: i = h1 + h2 
//second collision: i = h1 + h2 + h2
//third collision: i = h1 + h2 + h2 + h2
//advantage: 
//disdavantage:
    void insert_doubleh(int x) {
        int i = hfunction(x);
        if (elt[i] == 0) {
            elt[i] = x;
        }
        else {
            // Handle collision using double hashing
            int j = i;
            int step = h2(x);
            do {
                j = (j + step) % size;
                if (j == i) {
                    std::cout << "Table is full. Cannot insert " << x << std::endl;
                    return;
                }
            } while (elt[j] != 0);
            elt[j] = x;
        }
    }

    ~htable() {
        delete[] elt;
    }
};


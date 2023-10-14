#include <iostream>
#include <cstdlib>
#include <ctime>
#include "qjob.h"

void bssort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    qjob rizk;
    int a[4];

    // Seed the random number generator
    std::srand(std::time(0));

    // Create an array and sort it
    for (int i = 0; i < 4; i++) {
        a[i] = std::rand() % 50 + 10;
    }

    bssort(a, 4);

    // Fill the queue
    for (int i = 0; i < 4; i++) {
        rizk.enqueue("job", a[i]);
    }

    // Process the jobs (dequeue and log the time)
    job* cu;
    int sum = 0;
    while (!rizk.isempty()) {
        cu = rizk.getfront();
        sum += cu->min;
        rizk.dequeue();
    }

    std::cout << "It took rizk " << sum << " minutes to finish all jobs\n";

    return 0;
}


//write a function to add to the queue

//sort and print function 

//if remaining time < 3

//round robin:  of cpu to allocate....
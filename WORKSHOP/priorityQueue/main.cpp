#include <iostream>
#include <string>
#include "prioQueue.h"
using namespace std;

int main()
{
    PrioQueue pq;

    string task1 = "Wash Dishes";
    int prio1 = 3;

    string task2 = "Do Laundry";
    int prio2 = 5;

    string task3 = "Take out Trash";
    int prio3 = 7;

    string task4 = "Clean Room";
    int prio4 = 1;

    string task5 = "Do Homework";
    int prio5 = 10;

    pq.enqueue(task1, prio1);
    pq.enqueue(task2, prio2);
    pq.enqueue(task3, prio3);
    pq.enqueue(task4, prio4);
    pq.enqueue(task5, prio5);

    pq.display();
}

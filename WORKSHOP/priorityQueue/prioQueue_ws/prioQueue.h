#include <iostream>
using namespace std;

struct node
{
    string task;
    int priority;
    node *next;

    //constructor
    node(string task, int priority)
    {
        this->task = task;
        this->priority = priority;
        next = nullptr;
    }
};

class PrioQueue
{
    private:
        node *front;

    public:
        PrioQueue() {front = nullptr;}

        void enqueue(string, int);

        void display();
};
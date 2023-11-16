#ifndef prioQueue_h
#define prioQueue_h

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

        void enqueue(string task, int priority){
            //Start Implementation
            node* temp;
            node* start;

            temp = new node(task, priority);

            if (front == nullptr || priority > front -> priority){
                temp -> next = front;
                front = temp;
            }
            else{
                start = front;

                while (start -> next != nullptr && start -> next -> priority >= priority){
                    start = start->next;
                }

                temp -> next = start -> next;
                 start -> next = temp;
                }
        }

        void display(){
            node* curr = front;

            if(curr == nullptr)
                return;

            else{
                while(curr != nullptr){
                    cout << curr->task << endl;
                    curr = curr->next;
                }
            }
        }

};

#endif 

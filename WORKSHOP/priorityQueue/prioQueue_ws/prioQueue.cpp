#include <iostream>
#include "prioQueue.h"
using namespace std;

void PrioQueue::enqueue(string task, int priority)
{
    //Start Implementation
    else{
        node* curr = front;

        while(curr->next != nullptr && curr -> priority >)
    }
}
        
void PrioQueue::display()
{
    node* curr = front;

    if(curr == nullptr)
        return;

    else
    {
        while(curr != nullptr)
        {
            cout << curr->task << endl;
            curr = curr->next;
        }
    }
}
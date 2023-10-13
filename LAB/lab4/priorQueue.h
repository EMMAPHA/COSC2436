#ifndef priorQueue_h
#define priorQueue_h

#include <iostream>
using namespace std;
//all of these functions are from lab and workshop slides
struct node{
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

class PriorQueue
{
    private:
        node *front;

    public:

        PriorQueue() {
            front = nullptr;
        }

        bool isEmpty(){
            return front == nullptr;
        }

        string getBeginning(){
            return front->task;
        }


        void enqueue(string task, int prior){
            node *temp = new node(task, prior);
        if(front == nullptr || prior < front->priority){
            temp->next = front;
            front = temp;
        }
        else{
            node *cu = front;
            while(cu->next != nullptr && prior >= cu->next->priority){
            cu = cu->next;
            }
            temp->next = cu->next;
            cu->next = temp;
           
            }
        }
        
        void pop(){
            if(!isEmpty()){
                node* temp = front;
                front = front->next;
                delete temp;
            }
        }

        void display(){
            node* current = front;
            while(current != nullptr){
                cout << current->task << current->priority << endl;
                current = current->next;
        }
    }
};

#endif
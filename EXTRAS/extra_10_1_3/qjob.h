#include <iostream>
#include <string>

struct job {
    std::string name;
    int min;
    job* next;
};

class qjob {
private:
    job* front;
    job* back;

public:
    qjob() {
        front = back = nullptr;
    }

    bool isempty() {
        return front == nullptr;
    }

    void enqueue(std::string n, int m) {
        job* tmp = new job;
        tmp->name = n;
        tmp->min = m;
        tmp->next = nullptr;
        if (isempty()) {
            front = back = tmp;
        }
        else {
            back->next = tmp;
            back = tmp;
        }
    }

    void dequeue() {
        if (!isempty()) {
            job* tmp = front;
            front = front->next;
            delete tmp;
        }
    }

    void print() {
        job* current = front;
        while (current != nullptr) {
            std::cout << "Job: " << current->name << ", Time: " << current->min << " minutes\n";
            current = current->next;
        }
    }

    job* getfront() {
        return front;
    }
};

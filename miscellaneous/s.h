#ifndef S_H
#define S_H

template <class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class Stack {
private:
    Node<T>* top;

public:
    Stack();
    ~Stack();

    void push(const T& item);
    void pop();
    T& peek();
    bool isEmpty() const;
};

#endif // S_H


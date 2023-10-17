#include <iostream>
#include <stack>
using namespace std;
class queue {
private:
    stack<int> s1;
    stack<int> s2;

public:

//adds elements to the end of the queue
    void enqueue(int x) { //O(1)
      s1.push(x);
    }

//removes elements from the front of a queue
    int dequeue() {//O(1)
      if (s2.empty()) {
          while (!s1.empty()) {
              s2.push(s1.top());
              s1.pop();
          }
      }
        int frontElement = s2.top();
      s2.pop();
        return frontElement;
    }

//returns whatever element is at the front of the queue
    int front() {//O(1)
      if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
      }
      return s2.top();
    }

//returns size of the queue
    int size() {//O(1)
        return s1.size() + s2.size();
    }
};

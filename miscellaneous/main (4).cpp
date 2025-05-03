#include <iostream>
#include "q.h"
using namespace std;

int main() {
  //creates a queue object 'q' using the 'queue' class defined in 'q.h'
    queue q;

  //enqueue elements into the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

  
  // displays the front element and the size of the queue
    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;
    cout << endl;
  
    // dequeue an element from the queue
    cout << "Element dequeued: " << q.dequeue() << endl;
    cout << endl;

  // displays the front element and the size of the queue after dequeuing
    cout << "Front element: " << q.front() << endl;
    cout << "Queue size: " << q.size() << endl;
  cout << endl;

  // dequeue another element from the queue
  cout << "Element dequeued: " << q.dequeue() << endl;
  cout << endl;

  // displays the front element and the size of the queue after dequeuing
  cout << "Front element: " << q.front() << endl;
  cout << "Queue size: " << q.size() << endl;
  cout << endl;

  // dequeue another element from the queue
  cout << "Element dequeued: " << q.dequeue() << endl;
  cout << endl;

  // displays the front element and the size of the queue after dequeuing
  cout << "Front element: " << q.front() << endl;
  cout << "Queue size: " << q.size() << endl;
  cout << endl;

  return 0;
}
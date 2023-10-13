#include <iostream>

using namespace std;

struct onechar {
  onechar *prev;
  char l;
  onechar *next;
};

class word {
private:
  onechar *head;

public:
  word() { head = nullptr; }

  bool isEmpty() {
    if (head == nullptr) {
      return true;
    } else {
      return false;
    }
  }

  onechar *getHead() { return head; }

  void insertatbeg(char x);
  void insertatend(char x);
  void print(onechar *curr);
  void recPrint(onechar *curr);
  void reversePrint(onechar *curr);
  void del_c(char x);
};

//print recursively using curr->next
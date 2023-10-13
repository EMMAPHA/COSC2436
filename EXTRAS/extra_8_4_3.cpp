#include <iostream>
using namespace std;

struct st{
 int ps;
float gpa;

};
class c2436{
  private:
     st* p;
    int size;
public:
  c2436(){
    size=120;
    p = new st[size];
}

~c2436(){delete []p;}

};



int main() {
  st Elie; //static
  Elie.ps=123;
  Elie.gpa=4;

 st *p=new st[8]; //dynamic
  (*p).ps=345;
  p->ps=345; //same p->ps = (*p)

  
  (*p).gpa=2.0; //same








  
}
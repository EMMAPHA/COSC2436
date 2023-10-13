#ifndef LINE_H
#define LINE_H

struct point{
int x;
int y;
point *next;
};
class line{
private:
      point *head;
      //point *tail;
public:
     line()
       { head=nullptr;}
     bool isempty();
     point *gethead();
     void insertatbeg(int a, int b); // private of node
    void insertatend(int a, int b);
    void insertatpos(int a, int b, int pos);
    void delfrombeg(int &, int &);

 void display(); // Add a method to display the contents of the list.
};
  

#endif


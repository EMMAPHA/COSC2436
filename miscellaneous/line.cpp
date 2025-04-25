#include "line.h"
#include <iostream>
using namespace std;
void line::insertatbeg(int a, int b){
  //1- create 
  point *tmp=new point;
  //2-fill
  tmp->x=a;
  tmp->y=b;
  tmp->next=0;
  //3-link
  tmp->next=head;
  head=tmp;  
}
void line::insertatend(int a, int b){
  point * cu=head;
  while(cu->next !=0)
      cu=cu->next;
  //stop just at the last node 


  //1- create 
  point *tmp=new point;
  //2-fill
  tmp->x=a;
  tmp->y=b;
  tmp->next=0;
  //3-link
  cu->next=tmp;
}
void line::insertatpos(int a, int b, int pos){
  point * cu=head;
  for(int i=1;i<pos-1;i++) 
        cu=cu->next;
  //stop just at the third position
  //1- create 
  point *tmp=new point;
  //2-fill
  tmp->x=a;
  tmp->y=b;
  tmp->next=0;
  //3-link
   tmp->next=cu->next;
   cu->next=tmp;
}



void line::delfrombeg(int &a, int &b)
{ //1-Mark
  point *tmp=head;
  //2-empty
   a=tmp->x;
   b=tmp->y;
  //3- unlink .....save the head
  head=tmp->next;
  delete tmp; 
  
}
//write binary search 
bool bs(int a[], int low, int up, int key)
{
 int m=0;

  while (low<=up )        // if low>up
    {  m=(low+up)/2;
  if (key<a[m])
       //lower 
       up=m-1;         // return bs(a,low,m-1,key)
  else
    if (key>a[m])
        low=m+1;   //return bs(a,m+1,up,key)
  else
     // (key==a[m])   // if ..true
        return true;}
  return false;



  
}



void line::display() {
    point* current = head;
    while (current != nullptr) {
        cout << "(" << current->x << ", " << current->y << ") ";
        current = current->next;
    }
    cout << endl;
}
#ifndef NECKLACE_H
#define NECKLACE_H

/* #include <iostream>
using namespace std; */

struct pearl{
int color;
int size;
pearl* hole;
};

class necklace{
private:
       pearl* head;
public:
     necklace(){
       head=nullptr;
     }
    
void insertpearl(int c, int s);
void print();//start head
void printrec(pearl* current); //cant write recursive function without parameters

};

#endif

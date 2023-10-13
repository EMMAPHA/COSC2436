//extra_9_3_3
#include <iostream>
using namespace std;

void printNumR(int f, int upTo){
  if (f>upTo){ //stop at 9 if >=
    return;
  }
  cout << f << endl;
  printNumR(f+1, upTo );
  //cout << f << endl;
  cout <<"End of call where f = " << f << endl;
  return;
  
}

int main() {
  printNumR(1,10);
} 



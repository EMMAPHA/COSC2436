//extra_8_5_1
#include <iostream>
using namespace std;
//factorials

/* int m(int a, int b){
  if(b==1)
    return a;
  else
    return a + m(a, b-1);
} */

int f(int v){
 if(v==0){
   return 0;
 }
  else{
   cout << v << "before\n";
   return v + f(v-1);
  }
}
void ex(int x){
  if(x==5){
    cout << "five\n";
  }
  else{
    cout << "not five\n"<<x<<endl;
    cout <<"hello\n";
    ex(x-1); //doesn't go to next line right away until x=5
    cout <<"bye" <<x<<endl;
    
  }
}

int main() {
  cout << f(4) << endl;
  ex(7);
}
//what is output?
//write recursive function to print array
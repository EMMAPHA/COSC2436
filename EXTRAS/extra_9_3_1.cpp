//extra_9_3_1
#include <iostream>
using namespace std;

int fib(int n){
  if(n<=1){
    return n;
  }
    return fib(n-1) + fib(n-2);
}
int main() {
  int numpos;
  cin >> numpos;
  cout << fib(numpos) << endl;
}
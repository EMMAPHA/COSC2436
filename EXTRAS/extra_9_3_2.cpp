#include <iostream>
using namespace std;
string printRev(string s, int start, int end){
  if(start>=end){
    return s;
  }

  char temp = s[start]; //temp to swap the characters
  s[start]=s[end];
  s[end] = temp;

  return printRev(s, start + 1, end -1); //start goes forward, end goes backwards
  
}
int main() {
  string a_string = "xyz";
 //string reversed = printRev(a_string, 0, a_string.length() - 1);
  cout << printRev(a_string, 0, a_string.length() - 1) << endl; //insert reversed
}
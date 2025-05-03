#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include "ArgumentManager.h"
using namespace std;

/* An expression is valid if:
● there is a corresponding closing bracket for every open bracket
● there is a corresponding open bracket for every closing bracket
● the closing bracket matches the open bracket
● the brackets are in the correct order */

/* Brackets are in the correct order if:
● For a set of corresponding brackets, the open bracket is before the closed
bracket
● Curly Brackets { } are only enclosed in other curly brackets
● Square Brackets [ ] are only enclosed in either curly or square brackets
● Round Brackets ( ) are enclosed in either curly or square or round
brackets
● Correct Order: { [ ( ) ] }
● Incorrect Order: ( [ { } ] )
● Incorrect Order: } ] ) ( [ { */

/* ⢀⡴⠑⡄⠀⠀⠀ ⣀⣀⣤⣤⣤⣀⡀
   ⠸⡇⠀⠿⡀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
 ⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿"
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉ */

/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⡤⠤⠤⠤⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠞⠋⠁⠀⠀⠀⠀⠀⠀⠀⠉⠛⢦⣤⠶⠦⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⣴⠞⢋⡽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠀⠀⠙⢶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣰⠟⠁⠀⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡀⠀⠀⠉⠓⠦⣤⣤⣤⣤⣤⣤⣄⣀⠀⠀⠀
⠀⠀⠀⠀⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣷⡄⠀⠀⢻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣆⠀
⠀⠀⣠⠞⠁⠀⠀⣀⣠⣏⡀⠀⢠⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⠿⡃⠀⠀⠀⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡆
⢀⡞⠁⠀⣠⠶⠛⠉⠉⠉⠙⢦⡸⣿⡿⠀⠀⠀⡄⢀⣀⣀⡶⠀⠀⠀⢀⡄⣀⠀⣢⠟⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠃
⡞⠀⠀⠸⠁⠀⠀⠀⠀⠀⠀⠀⢳⢀⣠⠀⠀⠀⠉⠉⠀⠀⣀⠀⠀⠀⢀⣠⡴⠞⠁⠀⠀⠈⠓⠦⣄⣀⠀⠀⠀⠀⣀⣤⠞⠁⠀
⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠁⠀⢀⣀⣀⡴⠋⢻⡉⠙⠾⡟⢿⣅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⠛⠉⠉⠀⠀⠀⠀
⠘⣦⡀⠀⠀⠀⠀⠀⠀⣀⣤⠞⢉⣹⣯⣍⣿⠉⠟⠀⠀⣸⠳⣄⡀⠀⠀⠙⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠈⠙⠒⠒⠒⠒⠚⠋⠁⠀⡴⠋⢀⡀⢠⡇⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⢀⡾⠋⢻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⢸⡀⠸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⢠⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠀⠀⠉⠋⠻⣄⠀⠀⠀⠀⠀⣀⣠⣴⠞⠋⠳⠶⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⠦⢤⠤⠶⠋⠙⠳⣆⣀⣈⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀ */

/*⠀⠀⠀⠀⢀⣹⣿⣿⣿⡟⠉⠀⣸⣿⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡹⣿⣿⠀⠀⢹⣿⣿⣿⣿⣍⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢸⡌⢿⣿⣿⡇⠀⠀⡟⣸⢟⣿⣿⢿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⡆⢻⣧⠸⣿⣀⠔⠈⣿⣿⣿⣿⣽⡇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢸⣿⡈⢿⣿⡀⠀⠀⠣⡟⢸⣿⠇⢸⣿⠃⣿⠹⣿⣿⣿⣿⣿⣿⣿⠈⣿⡇⠀⢻⢠⡟⠁⠀⠀⣿⣿⡿⢹⣻⡇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢸⡋⡿⣾⣿⡇⠀⠀⠀⢱⠀⢻⠀⢸⡇⠀⢻⢹⣿⣿⣿⣿⠟⣼⡇⠀⣼⡇⣀⣼⠀⠀⠀⠀⠀⣿⣿⣧⣏⠋⡇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠘⣷⣵⣿⡏⠻⣄⣀⣤⣄⡀⠘⠀⠘⠟⠈⠛⠆⢻⣿⡏⣟⡸⢹⠁⠼⠻⠋⠉⣠⣴⣦⣤⣤⡴⠋⢹⢯⣿⣺⠃⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠘⢎⣿⡃⠀⠙⢿⣿⣿⣿⣷⣶⣶⣶⣶⣦⣀⠀⣿⣇⣿⣁⣠⣴⣶⣶⣾⣿⣿⣿⣿⣿⠋⠀⠀⣯⣾⢰⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⣎⢳⠀⠀⠀⢹⣿⣿⣭⣿⣿⣿⣿⡿⣿⣿⣿⣷⣿⣿⣿⣿⡿⠛⠛⠛⠉⠀⣼⠏⠀⠀⠀⣿⢡⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⢺⣇⠀⠀⠀⠙⢯⣿⣿⣉⣩⡿⠿⠋⠀⠃⠀⠘⠁⠈⠻⡿⠷⠶⠶⠶⠿⠋⠀⠀⠀⢰⣿⠉⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠘⡄⠀⢸⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣀⣀⣀⣀⠀⠈⡆⢧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠤⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢣⢀⡏⣸⣤⣶⣶⣶⣶⣤⡀⠀⠀
⢀⣾⣿⣿⣿⣿⣿⣿⣶⡧⠈⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡄⠀⠀⠀⠠⣤⠄⠀⠀⠀⠀⠀⣤⡀⡠⢻⡞⠀⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀
⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠈⢧⡄⠀⣿⡁⠀⠀⠀⠀⢹⡀⠀⠀⠀⢀⡼⠀⠀⠀⠀⢀⡴⠋⣁⢠⡾⠀⢘⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣳⡀⠀⠳⡄⠈⢿⣷⣄⡀⠀⠀⢿⣤⣀⣤⡿⢁⢀⣀⣠⣶⣟⡀⠀⣥⣟⣥⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⣹⣖⠘⢿⣿⣟⡛⡟⢿⠉⢿⠉⢽⠉⡟⡼⣾⣿⣯⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣳⣙⣿⣾⣾⣦⣾⣤⣷⣾⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ */


bool validParentheses(string exp){
  stack<char> st;
  for(int i = 0; i < exp.length(); i++){
    if(exp[i] == '('){
      st.push(exp[i]);
    }
      // when the loop is at '['
      // it checks the top of the stack for a '('
      // if there is then it's false cuz square brackets cant be enclosed by those
    else if (exp[i] == '['){
      if (!st.empty() && st.top() == '('){
        return false;
      }
      st.push(exp[i]);
    }
    else if (exp[i] == '{'){
      if (!st.empty() && (st.top() == '(' || st.top() == '[')){
        return false;
      }
      st.push(exp[i]);
    }
    else if(exp[i] == ')'){
      if(st.empty() || st.top() != '('){
        return false;
      }
        st.pop();
     }
    else if(exp[i] == ']'){
      if(st.empty() || st.top() != '['){
        return false;
      }
        st.pop();
    }
    else if(exp[i] == '}'){
      if(st.empty() || st.top() != '{'){
        return false;
      }
        st.pop();
    }
}
return st.empty();
} 


int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  ifstream ifs(am.get("input"));
  ofstream ofs(am.get("output"));

  string str="";
  queue<string> valid, invalid;
  while(getline(ifs, str)){
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(remove(str.begin(), str.end(), '\r'), str.end());



    if(validParentheses(str)){
     valid.push(str);
     //cout << "Valid" << endl;
    }
    else if(!validParentheses(str)){
     invalid.push(str);
     //cout <<"Invalid" << endl; 
    }
  }

  //for testing
  /*if(!invalid.empty()){
    cout << "Invalid"<< endl;
    while(!invalid.empty()){
      cout << invalid.front() << endl;
      invalid.pop();
    }
  }
  if(!valid.empty()){
    cout << "Valid" << endl;
    while(!valid.empty()){
      cout << valid.front() << endl;
      valid.pop();
    }
  }
  */

  if(!invalid.empty()){
    ofs << "Invalid"<< endl;
    while(!invalid.empty()){
      ofs << invalid.front() << endl;
      invalid.pop();
    }
  }
  if(!valid.empty()){
    ofs << "Valid" << endl;
    while(!valid.empty()){
      ofs << valid.front() << endl;
      valid.pop();
    }
  }

  return 0;
}
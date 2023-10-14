#include<iostream>
#include<fstream>
#include<string>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[]){

  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
  
  int matrix[13][4];

  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
      matrix[i][j] = 0;
    }
  }

  string str;
  int x, y;
  bool flag = false;

  while(input >> str){
    if(str[0] == 'J'){
      x = 10;
    }
    else if(str[0] == 'Q'){
      x = 11;
    }
    else if(str[0] == 'K'){
      x = 12;
    }
    else{
      if(!isdigit(str[1]))
        x = str[0] - 49;
      else{
        x = 9;
        flag = true;
      }
    }
    if(!flag){
      if(str[1] == 'S')
        y = 0;
      else if(str[1] == 'C')
        y = 2;
      else if(str[1] == 'H')
        y = 1;
      else if(str[1] == 'D')
        y = 3;
    }
    else{
      if(str[2] == 'S')
        y = 0;
      else if(str[2] == 'C')
        y = 2;
      else if(str[2] == 'H')
        y = 1;
      else if(str[2] == 'D')
        y = 3;
      flag = false;
    }
    matrix[x][y] = 1;
  }

  for(int i = 0; i < 13; i++){
    for(int j = 0; j < 4; j++){
      output << matrix[i][j] << " ";
    }
    output << endl;
  }

  return 0;
}
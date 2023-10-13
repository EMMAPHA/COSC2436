#include <iostream>
#include <algorithm>
#include "ArgumentManager.h"
#include "LinkedList.h"
#include <fstream>
#include <string>

string decode(string code)
{
  string decoded = "";
  int rightOpenPar = 0;
  int leftClosePar = 0;
  while(code.find('(') != string::npos)
  {
    rightOpenPar = code.find_last_of('(');
    leftClosePar = rightOpenPar + code.substr(rightOpenPar).find(')');

    //decoded = reverseString(code.substr(rightOpenPar, leftClosePar-rightOpenPar-1));
    
    decoded = "";

    for(int i = rightOpenPar+1; i<leftClosePar; i++)
    {
      decoded = code.at(i) + decoded;
    }
    
    decoded = code.substr(0, rightOpenPar) + decoded;
    if(leftClosePar+1 < code.length())
    {
      decoded = decoded + code.substr(leftClosePar+1);
    }

    code = decoded;
  }
  return code;
}

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  
  if(input.peek()==EOF)
  {
    input.close();
    return 0;
  }
  LinkedList innocent("Innocent");
  LinkedList guilty("Guilty");

  string inputline;
  
  while(getline(input, inputline))
  {
    inputline.erase(remove(inputline.begin(), inputline.end(), '\n'), inputline.end());
    inputline.erase(remove(inputline.begin(), inputline.end(), '\r'), inputline.end());

    if (inputline.empty() || inputline == "Bar1" || inputline == "Bar2") 
    {
      continue;
    }

    string result = inputline;

    result = decode(result);

    //check if duplicate
    bool isDuplicate = innocent.isDuplicate(result) || guilty.search(result);
    if(isDuplicate && !guilty.search(result)) //if dupe AND not in guilty
    {
      //add to guilty. isDuplicate() should have deleted it from inno already
      guilty.insert(result);
    }
    //no duplicate --->innocent
    else if(!isDuplicate)
    {
      //add to innocent for realsies
      innocent.insert(result);
    }
  }
  input.close(); //close it asap
  
  //only open it when necessary - Printing
  ofstream output(am.get("output"));
  guilty.print(output);
  innocent.print(output);
  
  output.close();

  return 0;
}
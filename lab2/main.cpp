#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <algorithm>
#include "linkedlist.h"
#include "ArgumentManager.h"
using namespace std;


int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
  
 string input = am.get("input");
     string output = am.get("output");


    ofstream ofs(output);
    ifstream ifs(input); 
    LinkedList words;
  
  string line = "";
while(getline(ifs, line))
    {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
       line.erase(remove(line.begin(), line.end(), '\r'), line.end());

      stringstream ss(line);
      string command;
     ss >> command;

      string location;
      ss >> location;

      string word;
      ss >> word;
/* words.display();
cout << endl; */
            //cout << "size: " << words.getSize() << endl;
   

    if(command == "Insert"){
        if(location == "Head"){
            words.insertAtHead(word);
        }
        else if(location == "Tail"){
             words.insertAtTail(word);   
        }
        else{

            int pos = stoi(location);
            words.insertAtPos(word, pos);
   
        }
    }
    else if(command == "Remove"){
         
        if(location == "Head"){
           
            words.removeAtHead();
            
        }
        else if(location == "Tail"){
            words.removeAtTail();

        }
        else{
            int pos = stoi(location);
            words.removeAtPos(pos);
        }
    }
    else if(command == "Print"){
        if(location == "[Head]"){
            words.printHead(ofs);
        }
        else if(location == "[Tail]"){
            words.printTail(ofs);  
        }
        else{
            int pos = stoi(location.substr(1,location.length() - 2));//this removes '[' and ']'
            words.printAtPos(ofs, pos);
        }

    }
      
      
      //cout << command << endl;
      //cout << location << " " << word << endl;
      
    }

    ifs.close(); //MAKE SURE TO CLOSE FILES
    ofs.close();
  
    return 0;

} 

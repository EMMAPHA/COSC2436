#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "priorQueue.h"
#include "ArgumentManager.h"
using namespace std;

/* umm u just put stuff into a queue
arrange it so that lowest numbers are at the front
and then execute the instructions
and like
the instruction determines if the door is open or closed

so if the last instruction at the end of the queue is to close the door
door = "the door is closed"
or however u will do it
door.closed();
idk

it's basically just using a priority queue to do a step-by-step instruction thing to open and close and lock/unlock a door 
 */

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    PriorQueue doorQu;
    string line;
    int pp;
    
    while(getline(ifs, line)){
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());

        if(line.empty()){
            continue;
        }
        if(line.find("open the door")!=string::npos || line.find("close the door")!=string::npos 
        || line.find("unlock the door")!=string::npos || line.find("lock the door")!=string::npos){
            string instruct = line.substr(0, line.find('('));
            string priorT = (line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));
            bool is_digit = all_of(priorT.begin(), priorT.end(),::isdigit);
/*              for(int i = 0; i < priorT.length();i++){

                    if(!isdigit(priorT[i])){
                        continue;
                    }
             } */

             if(!is_digit){
                continue;
             }

            else{
             pp = stoi(priorT);
             doorQu.enqueue(instruct, pp);
            }

        }

        else{
            continue;
        }
    }
    doorQu.display();

//ASSUME THE DOOR STARTS CLOSED AND UNLOCKED

    bool isUnlocked = true;
    string doorPhase = "the door is closed";

    while(!doorQu.isEmpty()){
        string front = doorQu.getBeginning();

        if(front.find("open the door")!=string::npos){
            if(isUnlocked){
                doorPhase = "the door is open";
                //cout << "here1" << endl;  
            }
        }
        
        else if(front.find("close the door")!=string::npos){

            if(isUnlocked){
                doorPhase = "the door is closed";
            }
        }
           else if(front.find("unlock the door")!=string::npos){
                isUnlocked = true;

           }
            else if(front.find("lock the door")!=string::npos){

                isUnlocked = false;
            }

            doorQu.pop();

    }
    

    ofs << doorPhase;
    ifs.close();
    ofs.close();
    return 0;
}


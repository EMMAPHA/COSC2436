#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "ArgumentManager.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
     ArgumentManager am(argc, argv);

     string input = am.get("input");
    string command = am.get("command");
     string output = am.get("output");

/*     string input = "input8.txt";
    string command = "command8.txt";
    string output = "output8.txt"; */

    ifstream ifs(input);
    ifstream cfs(command);
    ofstream ofs(output);

    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open the file." << endl;
        return -1;
    }

    // variables

    // * Processing the input files
    // [name: Rob; age: 34; deposit: 1234; number of drinks: 1]
    LinkedList casino;
    string inputline;
    while (getline(ifs, inputline))
    {
        // ? Clean lines
        inputline.erase(remove(inputline.begin(), inputline.end(), '\n'),
                        inputline.end());
        inputline.erase(remove(inputline.begin(), inputline.end(), '\r'),
                        inputline.end());
        string name;
        int age, deposit, drinks;
        // Parse the lines to get the data
        name = inputline.substr(7, inputline.find(';') - 7);
        inputline = inputline.substr(inputline.find(';') + 2);
        // // cout << inputline << endl;
        age = stoi(inputline.substr(5, inputline.find(';') - 5));
        inputline = inputline.substr(inputline.find(';') + 2);
        // // cout << inputline << endl;
        deposit = stoi(inputline.substr(9, inputline.find(';') - 9));
        inputline = inputline.substr(inputline.find(';') + 2);
        // // cout << inputline << endl;
        drinks = stoi(inputline.substr(18, inputline.find(']') - 18));

        // cout << name << endl;
        // cout << age << endl;
        // cout << deposit << endl;
        // cout << drinks << endl;

        node *newNode = new node(name, age, deposit, drinks);
        if (casino.getSize() == 0)
            casino.insertAtHead(newNode);
        else
        {
            casino.insertAtTail(newNode);
        }
        // else
        //     casino.insertAtPos(newNode, casino.getSize() - 1);
        // cout << "new input" << endl;
        // casino.print();
    }
    ifs.close();

    // * cmd file processing
    string commandstr;
    while (getline(cfs, commandstr))
    {
        // ? Clean lines
        commandstr.erase(remove(commandstr.begin(), commandstr.end(), '\n'), commandstr.end());
        commandstr.erase(remove(commandstr.begin(), commandstr.end(), '\r'), commandstr.end());

        string attribute, name;
        int attribute_num, index, age, deposit, drinks;
        cout << commandstr << endl;
        // ? Add handling
        if (commandstr[0] == 'A')
        {
            // get index
            index = stoi(commandstr.substr(5, commandstr.find(')') - 5));
            // cout << index << endl;
            commandstr = commandstr.substr(commandstr.find(':') + 2);
            // cout << commandstr << endl;
            name = commandstr.substr(0, commandstr.find(';'));
            // cout << name << endl;
            commandstr = commandstr.substr(commandstr.find(':') + 2);
            // cout << commandstr << endl;
            age = stoi(commandstr.substr(0, commandstr.find(';')));
            // cout << age << endl;
            commandstr = commandstr.substr(commandstr.find(':') + 2);
            // cout << commandstr << endl;
            deposit = stoi(commandstr.substr(0, commandstr.find(';')));
            // cout << deposit << endl;
            commandstr = commandstr.substr(commandstr.find(':') + 2);
            // cout << commandstr << endl;
            drinks = stoi(commandstr.substr(0, commandstr.find(']')));
            // cout << drinks << endl;
            node *newNode = new node(name, age, deposit, drinks);
        
            casino.insertAtPos(newNode, index);
            // casino.print();
        }
        // ? Remove handling
        else if (commandstr[0] == 'R')
        {
            if (commandstr.find("name") != string::npos)
            {
                commandstr = commandstr.substr(commandstr.find(':') + 2);
                name = commandstr.substr(0, commandstr.find(')'));
                casino.removeBy("name", 0, name);
            }
            else if (commandstr.find("age") != string::npos)
            {
                commandstr = commandstr.substr(commandstr.find(':') + 2);
                age = stoi(commandstr.substr(0, commandstr.find(']')));
                casino.removeBy("age", age);
            }
            else if (commandstr.find("deposit") != string::npos)
            {
                commandstr = commandstr.substr(commandstr.find(':') + 2);
                deposit = stoi(commandstr.substr(0, commandstr.find(']')));
                casino.removeBy("deposit", deposit);
            }
            else if (commandstr.find("drinks") != string::npos)
            {
                commandstr = commandstr.substr(commandstr.find(':') + 2);
                drinks = stoi(commandstr.substr(0, commandstr.find(']')));
                casino.removeBy("drinks", drinks);
            }
            // attribute = commandstr.substr(start + 1, end - (start + 1));
            // cout << attribute << endl;
            // int end2 = commandstr.find(")");
            // attribute_num = stoi(commandstr.substr(end + 1, (end2 - (end + 1))));
            //  casino.remove(attribute, attribute_num);
        }
        else if (commandstr[0] == 'S')
        {
            if (commandstr.find("name") != string::npos)
                casino.sortByAlpha();
            else if (commandstr.find("age") != string::npos)
                casino.sortByAge();
            else if (commandstr.find("deposit") != string::npos)
                casino.sortByDeposit();
            else if (commandstr.find("drinks") != string::npos)
                casino.sortByDrinks();
            // cout << commandstr << endl;
            // casino.bubble(casino.getHead(), attribute);
        }
        // cout << commandstr << endl;
        casino.print();
        cout << endl;
    }
     //added

    casino.print(ofs);

    node *curr = casino.getHead();
    cfs.close();
    ofs.close();
}
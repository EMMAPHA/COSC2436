#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[]) {
     ArgumentManager am(argc, argv);

     ifstream ifs(am.get("input"));
     ofstream ofs(am.get("output"));

     int n = 0;
     string str = "";
     map<string,int>m;

     ifs >> n;

     for(int i = 0; i<n;i++){
            ifs >> str;

            m[str]++;
     }
     map<string,int>::iterator itr;

     for(itr=m.begin();itr != m.end();itr++){
        ofs << itr->first << ": " << itr->second<<endl;
     }

    return 0;
}
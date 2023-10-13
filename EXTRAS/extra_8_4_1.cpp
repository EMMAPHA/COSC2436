#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  cout << "Hello World!\n";
  cout << " nb of arg " << argc << endl; //argument counter


  if (argc <3)
    cout << "the nb of parm should be at least 2";
  cout <<" the name of the file is " << argv[0]<<endl;


// ./main hello -4 -21 /p 
//each is 1 arg
//whole thing is argv

 for(int i = 0;i<argc;i++){
  cout << argv[i]<<endl;

}

  return 0;
}

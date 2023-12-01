#include  <iostream>
#include  <stack>
#include  <queue>
#include  <fstream>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

struct vertex{
    int value;
    vertex *next;
};

void BFS(vertex *arr[], int source, int n){
    queue<int> q; // Initialize queue
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    q.push(source);
    int v;
    int next;
    vertex *curr = nullptr;
    while(!q.empty()){ // Perform BFS
        v = q.front();
        q.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        curr = arr[v];
        while(curr != nullptr){ // Push adjacent vertices to queue
            next = curr->value;
            if(!visited[next]){
                q.push(next);
            }
            curr = curr->next;
        }
    }
    cout << endl;
    delete [] visited;
}

void DFS(vertex *arr[], int source, int n){
    stack<int> s; // Initialize stack
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    s.push(source);
    int v;
    int next;
    vertex *curr = nullptr;
    while(!s.empty()){ // Perform DFS
        v = s.top();
        s.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        curr = arr[v];
        while(curr != nullptr){ // Push adjacent vertices to stack
            next = curr->value;
            if(!visited[next]){
                s.push(next);
            }
            curr = curr->next;
        }
    }
    cout << endl;
    delete [] visited;
}

void BFS(int **graph, int source, int n){
    queue<int> q; // Initialize queue
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    q.push(source);
    int v;
    while(!q.empty()){ // Perform BFS
        v = q.front();
        q.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        for(int i = 0; i < n; i++){ // Push adjacent vertices to queue
            if(graph[v][i] != 0 && !visited[i]){
                q.push(i);
            }
        }
    }
    cout << endl;
    delete [] visited;
}
void printGraph(int** graph, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


void DFS(int **graph, int source, int n){
    stack<int> s; // Initialize stack
    bool *visited = new bool[n]; // Initialize visited array
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    s.push(source);
    while(!s.empty()){ // Perform DFS
        int v = s.top();
        s.pop();
        if(!visited[v]){
            cout << v << " ";
            visited[v] = true;
        }
        for(int i = 0; i < n; i++){ // Push adjacent vertices to stack
            if(graph[v][i] != 0 && !visited[i]){
                s.push(i);
            }
        }
    }
    cout << endl;
    delete [] visited;
}

bool DFS(int** graph, int n, int node, int start, vector<bool>& visited) {
    if (visited[node]) {
        if (node == start) {
            return true;
        }
        return false;  // not a cycle unless revisiting the start node
    }
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && DFS(graph, n, i, start, visited)) {
            return true;  
        }
    }

    return false;
}

void insertVertex(vertex *arr[], int x, int y){
    vertex *v = new vertex;
    v->value = y;
    v->next = nullptr;
    if(arr[x] ==  nullptr){
        arr[x] = v;
    }
    else{
        vertex *curr = arr[x];
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = v;
    }
}

int main(int argc, char* argv[]){
    ArgumentManager am(argc, argv);
    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    string line="0";

    getline(ifs, line);
    int n = stoi(line); // how many nodes

    int x, y;

    vertex *arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = nullptr;
    }


    int **graph = new int*[n];
    for(int i = 0; i < n; i++){
        graph[i] = new int[n];
    }
  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = 0;
        }
    }

    while(getline(ifs, line)){
          stringstream ss(line);
          ss >> x >> y;
          graph[x][y] = 1;
          insertVertex(arr,x,y);
        }

    printGraph(graph, n);
    bool cycle= false;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && DFS(graph, n, i, i, visited)) {
            cycle = true;
            break;
        }
    }

    if(cycle)
      ofs << "TRUE";
    else
      ofs << "FALSE";
  
    for(int i = 0; i < n; i++){
        delete [] graph[i];
    }
    delete [] graph;

    return 0;
}
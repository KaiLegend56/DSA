#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>
#include <vector>
void adjListDFS(){
    int n,m;
    cout << "enter no. of nodes";
    cin >> n;
    cout << " enter no. of edges";
    cin >> m;
    vector <int> adjList[n+1];
    for( int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int visited[n+1] = {0};

    stack <int> s;
    int start;
    cout << " enter start node : ";
    cin >> start;
    s.push(start);
    
    visited[start] = 1;
    while( s.size() ){
        auto top = s.top();
        cout << top;
        s.pop();
        
        for( auto i : adjList[top] ){
            if( visited[i] == 0){  
            s.push(i);
            visited[i] = 1;
            }
        }

    }

}
void DFS(){
    int G[8][8]={{0,0,0,0,0,0,0,0},
            {0,0,1,1,1,0,0,0},
            {0,1,0,1,0,0,0,0},
            {0,1,0,0,1,1,0,0},
            {0,1,0,1,0,1,0,0},
            {0,0,0,1,1,0,1,1},
            {0,0,0,0,0,1,0,0},
            {0,0,0,0,0,1,0,0}};
    int visited[8] = {0};

    stack <int> s;
    s.push(4);
    visited[4] = 1;
    while( s.size() ){
        auto top = s.top();
        cout << top;
        s.pop();
        for( int i = 1 ; i < 8; i++){
            if( G[top][i] == 1 && visited[i] == 0){  
            s.push(i);
            visited[i] = 1;
            }
        }

    }

}
int main(){
    DFS();
    adjListDFS();
}
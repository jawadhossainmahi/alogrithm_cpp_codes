#include <iostream>
using namespace std;

const int MAX = 5;

int adj[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0}
};

bool visited[MAX];

void dfs(int node){
    visited[node]=true;
    cout <<node<<" ";
    for(int i=0;i<MAX;i++){
        if(!visited[i]&& adj[node][i]){
            bfs(i);
        }
    }
}


int main() {
    for(int i=0;i<MAX;i++){
        visited[i]=false;
    }
    cout <<"dfs traversal :";
    dfs(0);
    return 0;
}
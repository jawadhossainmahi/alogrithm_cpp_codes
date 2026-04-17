// Online C++ compiler to run C++ program online
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

int q[MAX],front=0,rear=0;

void enqueue(int x){
    q[rear++]=x;
}

int dequeue(){
    return q[front++];
}

bool empty(){
    return front ==rear;
}

void bfs(int start){
    for(int i=0;i<MAX;i++){
        visited[i]=false;
    }
    visited[start]=true;
    enqueue(start);
    cout <<"bfs traversal :";
    while(!empty()){
        int node = dequeue();
        cout << node<<" ";
        for(int i=0;i<MAX;i++){
            if(!visited[i] && adj[node][i]){
                visited[i]=true;
                enqueue(i);
            }
        }
    }
}

int main() {
    // Write C++ code here
    cout << "Try programiz.pro";
    bfs(0);
    return 0;
}
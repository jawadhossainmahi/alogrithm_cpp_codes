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

int s[MAX],top=-1;

void push(int x){
    s[++top]=x;
}

int pop(){
    return s[top--];
}

bool empty(){
    return top==-1;
}

void dfs(int start){
    for(int i=0;i<MAX;i++){
        visited[i]=false;
    }
    push(start);
    visited[start]=true;
    while(!empty()){
        int node = pop();
        cout <<node<<" ";
        for(int i=0;i<MAX;i++){
            if(!visited[i] && adj[node][i]){
                visited[i]=true;
                push(i);
            }
        }
    }

}

int main() {
    dfs(0);
    return 0;
}
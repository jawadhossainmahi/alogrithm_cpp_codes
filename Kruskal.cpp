#include <bits/stdc++.h>
using namespace std;

int V = 5;

int graph[5][5] = {
    {0,2,0,6,0},
    {2,0,3,8,5},
    {0,3,0,0,7},
    {6,8,0,0,9},
    {0,5,7,9,0}
};

int parent[5];

// Edge stored in arrays
int u[50], v[50], w[50];
int edgeCount = 0;

// create edge list
void createEdges() {
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                u[edgeCount] = i;
                v[edgeCount] = j;
                w[edgeCount] = graph[i][j];
                edgeCount++;
            }
        }
    }
}

// bubble sort by weight
void sortEdges() {
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (w[j] > w[j + 1]) {

                swap(w[j], w[j + 1]);
                swap(u[j], u[j + 1]);
                swap(v[j], v[j + 1]);
            }
        }
    }
}

// find
int find(int x) {
    if (parent[x] == x)
        return x;
    return find(parent[x]);
}

// union
void unite(int a, int b) {
    parent[find(a)] = find(b);
}

void kruskal() {

    for (int i = 0; i < V; i++)
        parent[i] = i;

    createEdges();
    sortEdges();

    cout << "Edge : Weight\n";

    int count = 0;

    for (int i = 0; i < edgeCount && count < V - 1; i++) {

        int setU = find(u[i]);
        int setV = find(v[i]);

        if (setU != setV) {
            cout << u[i] << " - " << v[i] << " : " << w[i] << endl;
            unite(setU, setV);
            count++;
        }
    }
}

int main() {
    kruskal();
    return 0;
}
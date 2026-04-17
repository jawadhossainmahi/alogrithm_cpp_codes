#include <bits/stdc++.h>
using namespace std;

int V = 5;

int graph[5][5] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};
void dijkstra(int graph[5][5], int src) {

    int dist[V];
    bool visited[V];

    // initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    // V-1 iterations
    for (int i = 0; i < V - 1; i++) {

        // find minimum distance vertex
        int min = INT_MAX, u = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        // relax adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print result
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t " << dist[i] << endl;
    }
}
int main() {
    dijkstra(graph, 0);
    return 0;
}
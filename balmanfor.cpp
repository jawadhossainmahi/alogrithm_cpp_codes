void bellmanFord(int graph[5][5], int src) {

    int dist[V];

    // initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    // V-1 iterations
    for (int k = 0; k < V - 1; k++) {

        // check all edges
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {

                if (graph[u][v] && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // check negative cycle
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {

            if (graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                cout << "Negative cycle detected\n";
                return;
            }
        }
    }

    // print result
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t " << dist[i] << endl;
    }
}
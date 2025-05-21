#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source) {
    
    vector<pair<int, int>> adj[vertices];  
    for (int i = 0; i < edges; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); 
    }

    
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Min-heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if (d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter each edge as: u v weight\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> result = dijkstra(edges, V, E, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Vertex " << i << " : " << result[i] << "\n";
    }

    return 0;
}

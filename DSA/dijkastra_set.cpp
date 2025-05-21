#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int vertices, vector<vector<int>> &edges, int source) {
    vector<pair<int, int>> adj[vertices];  

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); 
    }

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    set<pair<int, int>> st; 
    st.insert({0, source});

    while (!st.empty()) {
        pair<int, int> top = *st.begin();
        st.erase(st.begin());
        int d = top.first;
        int node = top.second;

        for (int i = 0; i < adj[node].size(); i++) {
            int adjNode = adj[node][i].first;
            int wt = adj[node][i].second;

            if (d + wt < dist[adjNode]) {
                if (dist[adjNode] != INT_MAX) {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = d + wt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int source;
    cin >> source;

    vector<int> res = dijkstra(V, edges, source);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

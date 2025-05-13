#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> adj[n];

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n, INF);
    vector<int> parent(n, -1);
    int inMST[n]; // use int instead of bool

    for (int i = 0; i < n; i++)
        inMST[i] = 0; // 0 means not in MST

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = 1; // mark as included

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        totalWeight += key[i];
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}

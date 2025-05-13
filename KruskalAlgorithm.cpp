#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5; // adjust if needed

int parent[MAX];
int rankArr[MAX];

// Find the representative of a set (with path compression)
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

// Union by rank
void unionSet(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;

    if (rankArr[pu] < rankArr[pv]) {
        parent[pu] = pv;
    } else if (rankArr[pu] > rankArr[pv]) {
        parent[pv] = pu;
    } else {
        parent[pv] = pu;
        rankArr[pu]++;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<tuple<int, int, int>> edges; // (weight, u, v)

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Initialize Union-Find arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    int totalWeight = 0;

    cout << "Edges in MST:\n";
    for (auto [w, u, v] : edges) {
        if (find(u) != find(v)) {
            unionSet(u, v);
            totalWeight += w;
            cout << u << " - " << v << " : " << w << endl;
        }
    }

    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}

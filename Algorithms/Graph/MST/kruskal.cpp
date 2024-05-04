#include <bits/stdc++.h>
using namespace std;

vector<int> parent, size_component;

int root(int u) {
    if(parent[u] == u) return u;
    return parent[u] = root(parent[u]);
}

bool connected(int u, int v) { return root(u) == root(v); }

void union_comps(int u, int v) {
    int ru = root(u);
    int rv = root(v);

    if(ru == rv) return;
    else if(size_component[ru] < size_component[rv]) {
        parent[ru] = rv;
        size_component[rv] += size_component[ru];
    } else {
        parent[rv] = ru;
        size_component[ru] += size_component[rv];
    }
}

vector<vector<pair<int, int>>> kruskal_mst(vector<vector<int>> edges, int n) {
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    sort(edges.begin(), edges.end());
    for(vector<int> edge : edges) {
        int u = edge[1], v = edge[2], w = edge[0];
        if(!connected(u, v)) {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            union_comps(u, v);
        }
    }
    return g;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, u, v, w;
    vector<vector<int>> edges;
    cin >> n >> m;
    parent.resize(n + 1);
    size_component.resize(n + 1, 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    vector<vector<pair<int, int>>> mst = kruskal_mst(edges, n + 1);

    for(int i = 1; i <= n; i++) 
        for(int j = 0; j < (int) mst[i].size(); j++)
            cout << i << ' ' << mst[i][j].first << ' ' << mst[i][j].second << '\n'; 

    return 0;
}
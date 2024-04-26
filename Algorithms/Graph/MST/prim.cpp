#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> prim_mst(int init_node, vector<vector<pair<int, int>>> g) {
    set<int> v;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    v.insert(init_node);
    vector<vector<int>> e;
    for(int i = 0; i < (int) g[init_node].size(); i++) {
        vector<int> edge = {g[init_node][i].second, init_node, g[init_node][i].first};
        pq.push(edge);
    }
    
    while(v.size() != g.size() - 1) {
        while(v.count(pq.top()[2])) pq.pop();
        int cur_node = pq.top()[2];
        e.push_back(pq.top());
        pq.pop();
        v.insert(cur_node);
        for(int i = 0; i < (int) g[cur_node].size(); i++) {
            vector<int> edge = {g[cur_node][i].second, cur_node, g[cur_node][i].first};
            pq.push(edge);
        }
    }

    vector<vector<pair<int, int>>> mst(g.size());
    for(int i = 0; i < (int) e.size(); i++) {
        int u = e[i][1], v = e[i][2], w = e[i][0];
        mst[u].push_back({v, w});
        mst[v].push_back({u, w});
    }

    return mst;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<vector<pair<int, int>>> mst = prim_mst(1, graph);

    for(int i = 1; i <= n; i++) 
        for(int e = 0; e < (int) mst[i].size(); e++) 
            cout << i << ' ' << mst[i][e].first << ' ' << mst[i][e].second << '\n';

    return 0;
}
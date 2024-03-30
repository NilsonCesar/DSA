#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    int n, e, u, v, origin, cur_node;
    vector<vector<int>> graph;
    vector<bool> visited;
    queue<int> nodes;
    cin >> n >> e;
    graph.resize(n, vector<int>());
    visited.resize(n, false);

    for(int i = 0; i < e; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> origin;
    nodes.push(origin);

    while(!nodes.empty()) {
        cur_node = nodes.front();
        nodes.pop();
        visited[cur_node] = true;
        cout << cur_node << '\n';

        for(int node : graph[cur_node])
            if(!visited[node])
                nodes.push(node);
    }
}
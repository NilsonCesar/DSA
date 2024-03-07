#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
    int n, e, u, v, origin, cur_node;
    vector<vector<int>> graph;
    vector<bool> visited;
    stack<int> nodes;
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
        cur_node = nodes.top();
        nodes.pop();
        cout << cur_node << '\n';
        visited[cur_node] = true;
        for(int node : graph[cur_node])
            if(!visited[node]) 
                nodes.push(node);
    }
}
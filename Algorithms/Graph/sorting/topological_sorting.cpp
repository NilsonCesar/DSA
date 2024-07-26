#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> labels;
int current_label;

void dfs(vector<vector<int>> graph, int current_node) {
    visited[current_node] = true;
    for(int node : graph[current_node])
        if(!visited[node])
            dfs(graph, node);
    labels[current_node] = current_label;
    current_label--;
}

void topological_sort(vector<vector<int>> graph, int root) {
   for(int node : graph[root]) 
        dfs(graph, node);
}

int main()
{
    int n, e;
    cin >> n >> e;
    visited.resize(n, false);
    labels.resize(n);
    current_label = n - 1;
    
    vector<vector<int>> graph(n, vector<int>());
    
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    int root;
    cin >> root;
    topological_sort(graph, root);
    
    for(int i = 0; i < n; i++) cout << i << " -> " << labels[i] << '\n';

    return 0;
}
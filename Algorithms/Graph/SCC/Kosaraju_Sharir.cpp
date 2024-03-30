#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g, gr;
vector<int> scc;
vector<bool> visited;
stack<int> processing_order;

void dfsr(int v) {
	visited[v] = true;
	for(int i = (int) gr[v].size() - 1; i >= 0; i--) {
		if(!visited[gr[v][i]]) 
			dfsr(gr[v][i]);
	}
	processing_order.push(v);
}

void dfs(int v, int l) {
	scc[v] = l;
	for(int i = 0; i < (int) g[v].size(); i++)
		if(!scc[g[v][i]])
			dfs(g[v][i], l);
}

void Kosaraju_Sharir() {
	int v, l = 1;
	for(int i = 1; i <= n; i++) 
		if(!visited[i])
			dfsr(i);

	while(!processing_order.empty()) {
		v = processing_order.top();
		processing_order.pop();
		if(!scc[v]) dfs(v, l++);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int e, u, v;
	cin >> n >> e;
	g.resize(n + 1);
	gr.resize(n + 1);
	scc.resize(n + 1, 0);
	visited.resize(n + 1, false);

	for(int i = 0; i < e; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		gr[v].push_back(u);
	}

	for(int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
		sort(gr[i].begin(), gr[i].end());
	}

	Kosaraju_Sharir();

	for(int i = 1; i <= n; i++) cout << scc[i] << " ";
	cout << '\n';

    return 0;
}
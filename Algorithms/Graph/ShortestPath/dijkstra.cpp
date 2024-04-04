#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int n, e;
vector<vector<pair<int, int>>> graph;
vector<int> sp;
vector<bool> visited;

void Dijkstra(int s) {
	pair<int, int> v;
	sp[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({sp[s], s});

	while(!pq.empty()) {
		v = pq.top();
		pq.pop();
		if(visited[v.second]) continue;
		visited[v.second] = true;
		for(pair<int, int> p : graph[v.second]) {
			if(sp[p.first] > v.first + p.second) {
				sp[p.first] = v.first + p.second;
				pq.push({sp[p.first], p.first});
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	
	int u, v, w;
	cin >> n >> e;
	graph.resize(n);
	sp.resize(n, numeric_limits<int>::max());
	visited.resize(n, false);

	for(int i = 0; i < e; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}

	Dijkstra(0);

	for(int i = 0; i < n; i++) cout << i << " " << sp[i] << '\n';

    return 0;
}
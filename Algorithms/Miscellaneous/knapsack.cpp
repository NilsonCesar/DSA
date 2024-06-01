#include <bits/stdc++.h>
using namespace std;

int n, w;
vector<int> W, V;
map<pair<int, int>, long long> knapsack;

long long knapsack_solution(int i, int x) {
    auto it = knapsack.find({i, x});
    if(it != knapsack.end())
        return knapsack[{i, x}];

    if(x < 0) {
        return -1e9;
    }

    if(i == 0) return 0;
    
    knapsack[{i, x}] = max(knapsack_solution(i - 1, x), knapsack_solution(i - 1, x - W[i]) + V[i]);

    return knapsack[{i, x}];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> w >> n;
    W.resize(n + 1);
    V.resize(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> V[i] >> W[i];

    long long ans = knapsack_solution(n, w);

    cout << ans << '\n';

    return 0;
}
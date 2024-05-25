#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> fw_table(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));

    for(int i = 1; i <= n; i++)
        fw_table[i][i] = 0;

    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        fw_table[u][v] = c;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                if((fw_table[i][j] > fw_table[i][k] + fw_table[k][j]) &&
                    fw_table[i][k] != numeric_limits<int>::max() &&
                    fw_table[k][j] != numeric_limits<int>::max())
                    fw_table[i][j] = fw_table[i][k] + fw_table[k][j];
    
    for(int i = 1; i <= n; i++)
        if(fw_table[i][i] < 0) {
            cout << "Has negative cycle" << '\n';
	    return 0;
	}

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << fw_table[i][j] << ' ';
    	cout << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n = 4;

    vector<vector<int>> men = {
        {2, 3, 0, 1},
        {3, 2, 1, 0},
        {3, 2, 0, 1},
        {0, 1, 3, 2}
    };

    vector<vector<int>> women = {
        {2, 0, 1, 3},
        {3, 0, 2, 1},
        {3, 1, 2, 0},
        {2, 3, 1, 0}
    };

    vector<int> engagement(n, -1);
    vector<int> menActualChoice = {0, 0, 0, 0};
    vector<bool> engagedMan = {false, false, false, false};
    vector<vector<int>> womenPreference(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        int cnt = n;
        for (int j = 0; j < n; j++) {
            womenPreference[i][women[i][j]] = cnt--;
        }
    }
    
    while(true) {
        int done = true;
        int man, woman;
        for (int i = 0; i < n; i++) {
            if (!engagedMan[i]) {
                done = false;
                man = i;
                break;
            }
        }

        if (done) break;

        woman = men[man][menActualChoice[man]];
        menActualChoice[man]++;

        if (engagement[woman] == -1) {
            engagement[woman] = man;
            engagedMan[man] = true;
        } else if (womenPreference[woman][engagement[woman]] < womenPreference[woman][man]) {
            engagedMan[engagement[woman]] = false;
            engagedMan[man] = true;
            engagement[woman] = man;
        }
        
    }

    for (int i = 0; i < n; i++) {
        cout << "Woman " << i + 1 << " engage with: " << engagement[i] + 1 << '\n';
    }

    return 0;
}
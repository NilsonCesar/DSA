#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> Sieve(int a) {
    int lim = sqrt(a);
    int nums[a + 1];
    for (int i = 1; i <= a; i++) nums[i] = i;
    nums[1] = -1;

    for (int i = 1; i <= lim; i++) {
        if (nums[i] == -1) continue;
        int inc = i;

        while (inc + i <= a) {
            nums[inc + i] = -1;
            inc += i;
        }
    }

    vector<int> ans;

    for (int i = 1; i <= a; i++)
        if (nums[i] != -1)
            ans.push_back(i);
    
    return ans;
}

int main (void) { }
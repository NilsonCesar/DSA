#include <iostream>

int binarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1, m;

    while(l <= r) {
        m = (l + r) / 2;

        if(arr[m] == x) return m; 
        else if(arr[m] > x) r = m - 1;
        else l = m + 1;
    }

    return -1;
}

int main(void) { return 0; }
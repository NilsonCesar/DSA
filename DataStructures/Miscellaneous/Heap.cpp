#include <bits/stdc++.h>

using namespace std;
#define N 100000

void heapify_up(vector<int>& heap, int i) {
    if (i > 1) {
        int j = i / 2;

        // cout << i << " " << j << '\n';
        // cout << heap[i] << " " << heap[j] << '\n';
        if (heap[j] > heap[i]) {
            int c = heap[i];
            heap[i] = heap[j];
            heap[j] = c;
            heapify_up(heap, j);
        }
    }
}

int main(void) {
    vector<int> heap(N);
    int n = 1;
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        heap[n] = num;
        heapify_up(heap, n); n++;
    }

    for (int i = 1; i <= 10; i++) {
        cout << heap[i] << '\n';
    }

}
#include <bits/stdc++.h>

using namespace std;
#define N 100000

void heapify_up(vector<int>& heap, int i) {
    if (i > 1) {
        int j = i / 2;

        if (heap[j] > heap[i]) {
            swap(heap[i], heap[j]);
            heapify_up(heap, j);
        }
    }
}

void heapify_down(vector<int>& heap, int i, int n) {
    if (2 * i > n) return;
    int j = 2 * i;
    if (2 * i < n) {
        if (heap[2 * i] > heap[2 * i + 1]) {
            j = 2 * i + 1;
        } 
    }

    if (heap[j] < heap[i]) {
        swap(heap[i], heap[j]);
        heapify_down(heap, j, n);
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
    n--;

    cout << "heap:" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << ' ';
    }
    cout << '\n';

    vector<int> sorted_a(10);
    for (int i = 0; i < 10; i++) {
        sorted_a[i] = heap[1];
        swap(heap[1], heap[n]);
        heapify_down(heap, 1, --n);
    }

    cout << "Array sorted by heapsort:" << '\n';
    for (int i = 0; i < 10; i++) {
        cout << sorted_a[i] << ' ';
    }
    cout << '\n';

}
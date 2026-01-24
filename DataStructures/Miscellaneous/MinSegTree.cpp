#include <bits/stdc++.h>

using namespace std;
#define MAXN 100007
#define INF 0x3f3f3f3f

int v[MAXN];
int seg[MAXN*4];

// p = seg index, l = left end in v, r = right end in v (inclusive)
// build(1, 0, n - 1);
int build(int p, int l, int r) {
    if (l == r) return seg[p] = v[l];
    int m = (l + r) / 2;
    return seg[p] = min(build(2 * p, l, m), build(2 * p + 1, m + 1, r));  
}

// query(l, r, 1, 0, n - 1); l e r 0-indexados
int query(int a, int b, int p, int l, int r) {
    if (b < l || r < a) return INF;
    if (a <= l && r <= b) return seg[p];
    int m = (l + r) / 2;
    return min(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}

// update(i, x, 1, 0, n - 1); muda valor da posicao i para x, i 0-indexado
int update(int i, int x, int p, int l, int r) {
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l + r) / 2;
    return seg[p] = min(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}
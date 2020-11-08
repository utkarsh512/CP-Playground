#include <bits/stdc++.h>
using namespace std;

/**
 * Implementation of segment tree to answer maximum in given range efficiently
 * 
 * build(1, 0, n-1);
 * query(1, 0, n-1, l, r);
 * update(1, 0, n-1, pos, val);
 */

const int N = 1e5 + 10;
const int infi = 1e9;
int a[N], t[4*N];

void build (int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = max(t[2*v], t[2*v+1]);
  }
}

int query (int v, int tl, int tr, int l, int r) {
  if (l > r) return -infi;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return max(query(2*v, tl, tm, l, min(tm, r)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

signed main() {
  return 0;
}
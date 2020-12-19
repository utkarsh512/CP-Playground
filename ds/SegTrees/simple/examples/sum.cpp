#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)x.size()

/**
 * Implementation of seg-tree to efficiently handle sum queries for a range
 * and update queries
 */

/**
 * If index of parent is v, and it covers segment [l, r], let mid = (l+r)/2, then,
 * index of left child = v + 1;
 * index of right child = v + 2*(mid - l + 1)
 */

const int N = 1e6 + 10;
int a[N], int t[2*N];

void build (int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(v+1, tl, tm);
    build(v+2*(tm-tl+1), tm+1, tr);
    t[v] = t[v+1] + t[v+2*(tm-tl+1)];
  }
}

int query (int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return query(v+1, tl, tm, l, min(tm, r)) + query(v+2*(tm-tl+1), tm+1, tr, max(l, tm+1), r);
}

void update (int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) t[v] = new_val;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(v+1, tl, tm, pos, new_val);
    } else {
      update(v+2*(tm-tl+1), tm+1, tr, pos, new_val);
    }
    t[v] = t[v+1] + t[v+2*(tm-tl+1)];
  }
}

signed main() {
  return 0;
}
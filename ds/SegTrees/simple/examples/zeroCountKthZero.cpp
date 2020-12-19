#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], t[4*N];

void build (int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = (a[tl] == 0)? 1 : 0;
  } else {
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = t[2*v] + t[2*v+1];
  }
} 

int query (int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return query(2*v, tl, tm, l, min(r, tm)) + query(2*v+1, tm+1, tr, max(l, tm+1), r);
}

void update (int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    if (val == 0) t[v] = 1;
    else t[v] = 0;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    t[v] = t[2*v] + t[2*v+1];
  }
}

int findkth (int v, int tl, int tr, int k) {
  if (t[v] < k) return -1;
  if (tl == tr) {
    return tl;
  } else {
    int tm = (tl + tr) / 2;
    if (t[2*v] >= k) return findkth(2*v, tl, tm, k);
    return findkth(2*v+1, tm+1, tr, k-t[2*v]);
  }
}

signed main() {
  return 0;
}
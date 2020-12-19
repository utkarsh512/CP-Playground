/**
 *  Task: For a given value x we have to quickly find smallest index i such that 
 * the sum of the first i elements of the array a[] is greater or equal to x
 */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], t[4*N];

void build (int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = t[2*v] + t[2*v+1];
  }
}

void update (int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    t[v] = t[2*v] + t[2*v+1];
  }
}

int query (int v, int tl, int tr, int x) {
  if (t[v] < x) return -1;
  if (tl == tr) return tl;
  int tm = (tl + tr) / 2;
  if (x <= t[2*v]) return query(2*v, tl, tm, x);
  return query(2*v+1, tm+1, tr, x - t[2*v]);
}

signed main() {
  return 0;
}
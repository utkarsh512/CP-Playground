/**
 * Implementation of segment tree to answer query regarding the smallest index i
 * such that a[i] >= x
 */

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

const int N = 1e5 + 10;
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

void update (int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    t[v] = max(t[2*v], t[2*v+1]);
  }
}

int query (int v, int tl, int tr, int l, int r, int x) {
  if (l > r) return -1;
  if (t[v] <= x) return -1;
  if (tl == tr) return tl;
  int tm = (tl + tr) / 2;
  if (t[2*v] > x) return query(2*v, tl, tm, l, min(r, tm), x);
  return query(2*v+1, tm+1, tr, max(l, tm+1), r, x);
}

void prn() {
  cout << "[";
  for (int i = 1; i <= 10; i++) cout << a[i] << ", ";
  cout << "]\n";
}

signed main() {
  srand(time(0));
  for (int i = 1; i <= 10; i++) a[i] = rand() % 101;
  build(1, 1, 10);
  int ch;
  cout << "Enter choice : ";
  cin >> ch;
  while (ch != -1) {
    prn();
    if (ch == 1) {
      int l, r, x;
      cout << "Enter l, r, x : ";
      cin >> l >> r >> x;
      int out = query(1, 1, 10, l, r, x);
      cout << "Index : " << out << "\n";
    }
    if (ch == 2) {
      int pos, val;
      cout << "Enter pos, val : ";
      cin >> pos >> val;
      a[pos] = val;
      update(1, 1, 10, pos, val);
    }
    cout << "Enter choice : ";
    cin >> ch;
  }
  return 0;
}
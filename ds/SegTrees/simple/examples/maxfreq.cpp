#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

const int infi = 1e9;
typedef pair<int, int> pi;

const int N = 1e6 + 10;
int a[N];
pi t[4 * N];

void build (int v, int tl, int tr) {
  if (tl == tr) {
    t[v].ff = a[tl];
    t[v].ss = 1;
  } else {
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    if (t[2*v].ff == t[2*v+1].ff) {
      t[v].ff = t[2*v].ff;
      t[v].ss = t[2*v].ss + t[2*v+1].ss;
    } else if (t[2*v].ff > t[2*v+1].ff) {
      t[v].ff = t[2*v].ff;
      t[v].ss = t[2*v].ss;
    } else {
      t[v].ff = t[2*v+1].ff;
      t[v].ss = t[2*v+1].ss;
    }
  }
}

pi query (int v, int tl, int tr, int l, int r) {
  if (l > r) return (pi){-infi, 1};
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  pi a = query(2*v, tl, tm, l, min(tm, r));
  pi b = query(2*v+1, tm+1, tr, max(l, tm+1), r);
  if (a.ff == b.ff) return (pi){a.ff, a.ss+b.ss};
  else if (a.ff > b.ff) return a;
  else return b;
}

void update (int v, int tl, int tr, int pos , int val) {
  if (tl == tr) {
    t[v] = (pi){val, 1};
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    if (t[2*v].ff == t[2*v+1].ff) {
      t[v].ff = t[2*v].ff;
      t[v].ss = t[2*v].ss + t[2*v+1].ss;
    } else if (t[2*v].ff > t[2*v+1].ff) {
      t[v].ff = t[2*v].ff;
      t[v].ss = t[2*v].ss;
    } else {
      t[v].ff = t[2*v+1].ff;
      t[v].ss = t[2*v+1].ss;
    }
  }
}

signed main() {
  return 0;
}
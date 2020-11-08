#include <bits/stdc++.h>
using namespace std;

#define int long long

const int infi = 2e9;

template <class T, int SZ>
struct LazySegTree {
  using tp = pair<T, int>;
  tp t[2*SZ];
  int lazy[2*SZ];

  tp combine (tp l, tp r) {
    if (l.first != r.first) return min(l, r);
    return (tp){l.first, l.second + r.second};
  }

  LazySegTree () {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }

  void push (int v, int tl, int tr) {
    if (tl != tr) {
      lazy[2*v] += lazy[v];
      lazy[2*v+1] += lazy[v];
    }
    t[v].ff += lazy[v];
    lazy[v] = 0;
  }

  void pull (int v) {
    t[v] = combine(t[2*v], t[2*v+1]);
  }

  void build () {
    for (int i = SZ; i < 2*SZ; i++) {
      t[i] = {0, 1};
    }
    for (int i = SZ - 1; i >= 1; i--) {
      pull(i);
    }
  }

  void update (int l, int r, int inc, int v = 1, int tl = 1, int tr = SZ) {
    push(v, tl, tr);
    if (l > tr || r < tl) return;
    if (l <= tl && tr <= r) {
      lazy[v] += inc;
      push(v, tl, tr);
    } else {
      int tm = (tl + tr) / 2;
      update(l, r, inc, 2*v, tl, tm);
      update(l, r, inc, 2*v+1, tm+1, tr);
      pull(v);
    }
  }

  tp query (int l, int r, int v = 1, int tl = 1, int tr = SZ) {
    push(v, tl, tr);
    if (l > tr || r < tl) return (tp){infi, 0};
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    auto a = query(l, r, 2*v, tl, tm);
    auto b = query(l, r, 2*v+1, tm+1, tr);
    return combine(a, b);
  }
};
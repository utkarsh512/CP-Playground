/**
 * Description: Template for Lazy Segment Tree
 * How to use:
 *  SZ -> maximum length of the array (in powers of 2)
 *  init:
 *    LazySegTree<int, (1 << 18)> seg;
 *  operation:
 *    build  -> seg.build(a); Note: a must be zero-indexed
 *    update -> seg.update(L, R, inc);
 *    query  -> seg.query(L, R);
 * Source: self
 */

template <class T, int SZ>
struct LazySegTree {
  T t[2*SZ], lazy[2*SZ];

  LazySegTree () {
    // initialization
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }

  void push (int v, int tl, int tr) {
    if (tl != tr) {
      lazy[2*v] += lazy[v];
      lazy[2*v+1] += lazy[v];
    }
    // operation
    t[v] += (tr - tl + 1) * lazy[v];
    lazy[v] = 0;
  }

  void pull (int v) {
    // operation
    t[v] = t[2*v] + t[2*v+1];
  }

  void build (const vector<int>& a) {
    assert((int)a.size() <= SZ);
    for (int i = 0; i < (int)a.size(); i++) {
      t[SZ + i] = a[i];
    }
    for (int i = SZ - 1; i >= 1; i--) {
      pull(i);
    }
  }

  void update (int l, int r, T inc, int v = 1, int tl = 1, int tr = SZ) {
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

  T query (int l, int r, int v = 1, int tl = 1, int tr = SZ) {
    push(v, tl, tr);
    if (l > tr || r < tl) return 0; // out-of-index value
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    // operation
    return query(l, r, 2*v, tl, tm) + query(l, r, 2*v+1, tm+1, tr);
  }
};